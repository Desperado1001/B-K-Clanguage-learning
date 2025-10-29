<#
.SYNOPSIS
  Normalize headings in a large K&R Markdown file, split by chapter into multiple files, and generate a top-level index.

.DESCRIPTION
  This script performs three main tasks on a large Markdown file converted from
  "The C Programming Language (K&R 2e)":
  1) Heading normalization:
     - Converts plain-text headings like "Chapter 1 - A Tutorial Introduction" to "# Chapter 1 - A Tutorial Introduction"
     - Converts section numbers like "1.1 Getting Started" to "## 1.1 Getting Started"
     - Converts deeper numbers like "1.5.1 File Copying" to "### 1.5.1 File Copying"
     - Handles appendices, e.g., "Appendix A - Reference Manual" -> "# Appendix A - Reference Manual"
     - Handles appendix sections like "A.7.10 Equality Operators" -> "### A.7.10 Equality Operators"
     - Removes form feed characters and trims trailing spaces
  2) Splitting:
     - Splits the normalized file into per-chapter files on each top-level heading (# ...)
     - Supports "Preface", "Preface to the first edition", "Chapter N - Title", "Appendix X - Title"
  3) Index generation:
     - Creates an index README.md that lists all split files in logical order with links

.PARAMETER SourceFile
  Path to the source Markdown file. If omitted, the script will try to locate a single .md under <repo_root>\docs_markdown.
  If multiple candidates exist, it picks the one that best matches "C Programming Language" naming.

.PARAMETER OutDir
  Output directory for split files and index. Defaults to <repo_root>\docs_markdown\kr2e.

.PARAMETER NormalizedOutFile
  Optional path to write the single normalized monolithic Markdown (for reference).
  Defaults to <OutDir>\_normalized.md.

.PARAMETER Force
  Overwrite existing split files and index if they exist.

.PARAMETER WhatIf
  Show what would be done without making changes.

.EXAMPLE
  # Use defaults (auto-detect source doc; output to docs_markdown\kr2e)
  .\kr2e_transform.ps1

.EXAMPLE
  # Specify source explicitly and overwrite outputs
  .\kr2e_transform.ps1 -SourceFile "E:\system_program\c_programming_language\docs_markdown\KNR2e.md" -Force

.NOTES
  - Outputs are UTF-8 encoded.
  - This script does not modify the original source file; it writes a normalized copy and split files.
#>

[CmdletBinding(SupportsShouldProcess = $true)]
param(
  [Parameter(Mandatory = $false)]
  [string]$SourceFile,

  [Parameter(Mandatory = $false)]
  [string]$OutDir,

  [Parameter(Mandatory = $false)]
  [string]$NormalizedOutFile,

  [switch]$Force
)

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

function Write-Info([string]$msg) { Write-Host "[INFO ] $msg" -ForegroundColor Cyan }
function Write-Warn([string]$msg) { Write-Warning $msg }
function Write-Err ([string]$msg) { Write-Host "[ERROR] $msg" -ForegroundColor Red }

# Resolve repo root as parent of scripts directory
$repoRoot = Split-Path -Parent $PSScriptRoot
if (-not $OutDir -or [string]::IsNullOrWhiteSpace($OutDir)) {
  $OutDir = Join-Path $repoRoot 'docs_markdown\kr2e'
}
if (-not $NormalizedOutFile -or [string]::IsNullOrWhiteSpace($NormalizedOutFile)) {
  $NormalizedOutFile = Join-Path $OutDir '_normalized.md'
}

# Attempt to auto-detect the source file if not provided
if (-not $SourceFile -or [string]::IsNullOrWhiteSpace($SourceFile)) {
  $docsDir = Join-Path $repoRoot 'docs_markdown'
  if (-not (Test-Path -LiteralPath $docsDir)) {
    Write-Err "Docs directory not found: $docsDir"
    exit 1
  }
  $candidates = Get-ChildItem -LiteralPath $docsDir -Filter *.md -File -ErrorAction Stop
  if (-not $candidates -or $candidates.Count -eq 0) {
    Write-Err "No .md files found under $docsDir"
    exit 1
  }
  # Prefer a filename containing 'C Programming Language' or 'K&R'
  $preferred = $candidates | Where-Object {
    $_.Name -match 'C\s*Programming\s*Language' -or $_.Name -match 'K&R' -or $_.Name -match 'Kernighan|Ritchie'
  } | Select-Object -First 1
  if ($preferred) {
    $SourceFile = $preferred.FullName
  } else {
    $SourceFile = $candidates[0].FullName
    Write-Warn "Using first .md candidate (no preferred match found): $SourceFile"
  }
}

if (-not (Test-Path -LiteralPath $SourceFile)) {
  Write-Err "Source file not found: $SourceFile"
  exit 1
}

# Ensure output directory exists
if (-not (Test-Path -LiteralPath $OutDir)) {
  New-Item -ItemType Directory -Path $OutDir | Out-Null
  Write-Info "Created output directory: $OutDir"
}

Write-Info "SourceFile: $SourceFile"
Write-Info "OutDir    : $OutDir"
Write-Info "Normalized: $NormalizedOutFile"

# Utility: Create a URL/filename-friendly slug
function New-Slug([string]$text) {
  $s = $text.ToLowerInvariant()
  $s = $s -replace '\&', ' and '
  $s = $s -replace '[^\p{L}\p{Nd}]+', '-'     # replace non-letters/digits with hyphen
  $s = $s -replace '-{2,}', '-'               # collapse multiple hyphens
  $s = $s.Trim('-')
  if ([string]::IsNullOrWhiteSpace($s)) { $s = 'section' }
  return $s
}

# Utility: Normalize a single line into a Markdown heading if it matches known patterns
function Normalize-HeadingLine([string]$line) {
  if ($null -eq $line) { return $line }

  # Remove form feed and trailing whitespace
  $l = $line -replace "`f", ''  # remove form feed char (0x0C)
  $l = $l.TrimEnd()

  # Skip if it already is a heading
  if ($l -match '^\s*#{1,6}\s+') { return $l }

  # Preface variants
  if ($l -match '^\s*Preface\s*$') {
    return '# Preface'
  }
  if ($l -match '^\s*Preface\s+to\s+the\s+first\s+edition\s*$') {
    return '# Preface to the first edition'
  }

  # Chapter heading: "Chapter 1 - Title" or "Chapter 1: Title" (be flexible)
  $m = [regex]::Match($l, '^\s*Chapter\s+(\d+)\s*[-:]\s*(.+?)\s*$')
  if ($m.Success) {
    $num = $m.Groups[1].Value
    $title = $m.Groups[2].Value
    return "# Chapter $num - $title"
  }

  # Appendix heading: "Appendix A - Title"
  $m = [regex]::Match($l, '^\s*Appendix\s+([A-Z])\s*[-:]\s*(.+?)\s*$')
  if ($m.Success) {
    $letter = $m.Groups[1].Value
    $title  = $m.Groups[2].Value
    return "# Appendix $letter - $title"
  }

  # Chapter section "1.1 Title" or deeper "1.5.1 Title"
  $m = [regex]::Match($l, '^\s*(\d+(?:\.\d+){1,})\s+(.+?)\s*$')
  if ($m.Success) {
    $numStr = $m.Groups[1].Value
    $title  = $m.Groups[2].Value
    $depth  = ($numStr -split '\.').Count  # 2 -> 1.1 => "##"; 3 -> "###"; 4 -> "####"
    $level  = [Math]::Min(6, 1 + $depth)   # "##" for 1.1; "###" for 1.1.1; cap at 6
    return ('#' * $level) + " $numStr $title"
  }

  # Appendix section "A.7 Title" or "A.7.10 Title"
  $m = [regex]::Match($l, '^\s*([A-Z]\.(?:\d+)(?:\.\d+)*)\s+(.+?)\s*$')
  if ($m.Success) {
    $numStr = $m.Groups[1].Value
    $title  = $m.Groups[2].Value
    $parts  = ($numStr -split '\.').Count # "A.1" => 2 parts; "A.7.10" => 3 parts
    $level  = [Math]::Min(6, $parts)      # "##" for A.1 (2), "###" for A.1.1 (3)
    return ('#' * $level) + " $numStr $title"
  }

  return $l
}

# Parse a normalized top-level heading line into a descriptor object
function Parse-TopHeading([string]$headingLine) {
  # expects line starting with "# "
  $text = $headingLine -replace '^\s*#\s+', ''
  $obj = [ordered]@{
    Raw         = $headingLine
    Title       = $text
    Kind        = 'Other'  # Preface|Preface1E|Chapter|Appendix|Other
    Number      = $null    # for Chapter
    Letter      = $null    # for Appendix
    FileName    = $null
    OrderKey    = $null
  }

  # Preface variants
  if ($text -match '^\s*Preface\s+to\s+the\s+first\s+edition\s*$') {
    $obj.Kind = 'Preface1E'
    $obj.FileName = '00-preface-first-edition.md'
    $obj.OrderKey = '0001'
    return $obj
  }
  if ($text -match '^\s*Preface\s*$') {
    $obj.Kind = 'Preface'
    $obj.FileName = '00-preface.md'
    $obj.OrderKey = '0000'
    return $obj
  }

  # Chapter N - Title
  $m = [regex]::Match($text, '^\s*Chapter\s+(\d+)\s*-\s*(.+?)\s*$')
  if ($m.Success) {
    $num   = [int]$m.Groups[1].Value
    $title = $m.Groups[2].Value
    $slug  = New-Slug $title
    $obj.Kind    = 'Chapter'
    $obj.Number  = $num
    $obj.FileName = ('ch{0}-{1}.md' -f $num.ToString('00'), $slug)
    $obj.OrderKey = ('1{0:D3}' -f $num)
    return $obj
  }

  # Appendix X - Title
  $m = [regex]::Match($text, '^\s*Appendix\s+([A-Z])\s*-\s*(.+?)\s*$')
  if ($m.Success) {
    $letter = $m.Groups[1].Value
    $title  = $m.Groups[2].Value
    $slug   = New-Slug $title
    $obj.Kind     = 'Appendix'
    $obj.Letter   = $letter
    $obj.FileName = ('appendix-{0}-{1}.md' -f $letter.ToLowerInvariant(), $slug)
    $obj.OrderKey = ('2{0}' -f $letter)
    return $obj
  }

  # Fallback for other top-level sections
  $slug = New-Slug $text
  $obj.Kind     = 'Other'
  $obj.FileName = ('section-{0}.md' -f $slug)
  $obj.OrderKey = '9' + $slug
  return $obj
}

# Load source lines
Write-Info "Reading source..."
$lines = Get-Content -LiteralPath $SourceFile -Encoding UTF8

# Normalize all lines
Write-Info "Normalizing headings and cleaning content..."
$norm = New-Object System.Collections.Generic.List[string]
foreach ($line in $lines) {
  $norm.Add( (Normalize-HeadingLine $line) )
}

# Write normalized monolithic file
if ($PSCmdlet.ShouldProcess($NormalizedOutFile, "Write normalized monolithic markdown")) {
  # Ensure parent directory exists
  $normDir = Split-Path -Parent $NormalizedOutFile
  if (-not (Test-Path -LiteralPath $normDir)) {
    New-Item -ItemType Directory -Path $normDir | Out-Null
  }
  if ((-not $Force) -and (Test-Path -LiteralPath $NormalizedOutFile)) {
    Write-Warn "Normalized file exists and -Force not set: $NormalizedOutFile (skipping)"
  } else {
    $norm | Set-Content -LiteralPath $NormalizedOutFile -Encoding UTF8
    Write-Info "Wrote normalized file: $NormalizedOutFile"
  }
}

# Split on top-level headings (# ...)
Write-Info "Splitting by top-level headings..."
$segments   = @()
$currentBuf = New-Object System.Collections.Generic.List[string]
$currentHdr = $null

function Flush-CurrentSegment {
  param([bool]$final = $false)

  if ($null -eq $currentHdr -or $currentBuf.Count -eq 0) { return }

  $filePath = Join-Path $OutDir $currentHdr.FileName
  if ($PSCmdlet.ShouldProcess($filePath, "Write split file")) {
    if ((-not $Force) -and (Test-Path -LiteralPath $filePath)) {
      Write-Warn "Split file exists and -Force not set: $filePath (skipping)"
    } else {
      $currentBuf | Set-Content -LiteralPath $filePath -Encoding UTF8
      Write-Info "Wrote: $filePath"
    }
  }
  # Track for index
  $segments += ,@($currentHdr.Title, $currentHdr.FileName, $currentHdr.OrderKey)

  # Reset for next
  $script:currentBuf = New-Object System.Collections.Generic.List[string]
  $script:currentHdr = $null
}

# Iterate normalized lines, detect "# " top-level headings and split
foreach ($l in $norm) {
  if ($l -match '^\s*#\s+(.+)$') {
    # If this is a new top-level heading and we already have one buffered, flush previous
    if ($null -ne $currentHdr) {
      Flush-CurrentSegment
    }
    $currentHdr = Parse-TopHeading $l
    $currentBuf.Add($l)
  } else {
    # Just collect lines; even if first lines before first top-level, buffer them into a generic segment
    if ($null -eq $currentHdr) {
      # Synthesize a heading for preface-like prologue if needed
      $currentHdr = Parse-TopHeading '# Preface'
      $currentBuf.Add('# Preface')
    }
    $currentBuf.Add($l)
  }
}
# Flush last segment
Flush-CurrentSegment -final:$true

# Generate index README
Write-Info "Generating index README..."
$indexPath = Join-Path $OutDir 'README.md'

# Order segments by OrderKey then by filename for stable output
$ordered = $segments | Sort-Object { $_[2] }, { $_[1] }

$indexLines = New-Object System.Collections.Generic.List[string]
$indexLines.Add("# K&R 2e – Split Index")
$indexLines.Add("")
$indexLines.Add("> Generated by scripts/kr2e_transform.ps1")
$indexLines.Add("")
$indexLines.Add("## Contents")
$indexLines.Add("")

foreach ($seg in $ordered) {
  $title = $seg[0]
  $file  = $seg[1]
  $indexLines.Add( ("- [{0}]({1})" -f $title, "./" + $file) )
}

if ($PSCmdlet.ShouldProcess($indexPath, "Write split index README")) {
  if ((-not $Force) -and (Test-Path -LiteralPath $indexPath)) {
    Write-Warn "Index exists and -Force not set: $indexPath (skipping)"
  } else {
    $indexLines | Set-Content -LiteralPath $indexPath -Encoding UTF8
    Write-Info "Wrote index: $indexPath"
  }
}

Write-Info "Done."
