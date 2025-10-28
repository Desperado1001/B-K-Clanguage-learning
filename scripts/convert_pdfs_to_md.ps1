<#
.SYNOPSIS
  Convert all PDFs under docs/ to Markdown using 'markitdown'.

.DESCRIPTION
  This script scans the docs directory for PDF files and converts each one
  to Markdown by invoking the 'markitdown' CLI. Output files are written in
  UTF-8 encoding to a sibling directory (default: docs_markdown).

.PARAMETER SrcDir
  Source directory to search for PDFs. Defaults to <repo_root>\docs
  where <repo_root> is the parent of this script's directory.

.PARAMETER OutDir
  Output directory for generated Markdown files. Defaults to <repo_root>\docs_markdown.

.PARAMETER Markitdown
  Path to the 'markitdown' executable or a name resolvable on PATH.
  Defaults to 'markitdown'.

.PARAMETER Recurse
  If specified, search for PDFs recursively under SrcDir.

.PARAMETER Force
  If specified, overwrite existing Markdown files.

.EXAMPLE
  # Convert PDFs in the default docs directory
  ./convert_pdfs_to_md.ps1

.EXAMPLE
  # Convert recursively, overwrite existing files
  ./convert_pdfs_to_md.ps1 -Recurse -Force

.EXAMPLE
  # Convert a custom folder using a specific markitdown path
  ./convert_pdfs_to_md.ps1 -SrcDir "D:\docs" -OutDir "D:\docs_md" -Markitdown "D:\miniconda3\Scripts\markitdown.exe"

.NOTES
  - Requires the 'markitdown' CLI to be installed and available.
  - Output files are encoded as UTF-8 for best compatibility with GitHub rendering.
#>

[CmdletBinding(SupportsShouldProcess = $true)]
param(
  [Parameter(Mandatory = $false)]
  [string]$SrcDir = (Join-Path (Split-Path -Parent $PSScriptRoot) 'docs'),

  [Parameter(Mandatory = $false)]
  [string]$OutDir = (Join-Path (Split-Path -Parent $PSScriptRoot) 'docs_markdown'),

  [Parameter(Mandatory = $false)]
  [string]$Markitdown = 'markitdown',

  [Parameter(Mandatory = $false)]
  [switch]$Recurse,

  [Parameter(Mandatory = $false)]
  [switch]$Force
)

function Write-Info($Message)  { Write-Host "[INFO ] $Message" -ForegroundColor Cyan }
function Write-Warn($Message)  { Write-Warning "$Message" }
function Write-ErrorLine($Message) { Write-Host "[ERROR] $Message" -ForegroundColor Red }

# Validate markitdown availability (only if it's not a full path that exists)
$mdCmd = $null
if (Test-Path -LiteralPath $Markitdown) {
  $mdCmd = (Resolve-Path -LiteralPath $Markitdown).Path
} else {
  $mdCmd = Get-Command -Name $Markitdown -ErrorAction SilentlyContinue | Select-Object -First 1 -ExpandProperty Source
}

if (-not $mdCmd) {
  Write-ErrorLine "Cannot find 'markitdown' executable. Set -Markitdown to the full path or ensure it is on PATH."
  exit 1
}

# Validate source directory
if (-not (Test-Path -LiteralPath $SrcDir)) {
  Write-ErrorLine "Source directory not found: $SrcDir"
  exit 1
}

# Ensure output directory exists
if (-not (Test-Path -LiteralPath $OutDir)) {
  New-Item -ItemType Directory -Path $OutDir | Out-Null
  Write-Info "Created output directory: $OutDir"
}

# Discover PDF files
$searchParams = @{
  Path  = $SrcDir
  Filter= '*.pdf'
  File  = $true
}
if ($Recurse) { $searchParams['Recurse'] = $true }

$files = Get-ChildItem @searchParams | Sort-Object FullName

if (-not $files -or $files.Count -eq 0) {
  Write-Info "No PDF files found in $SrcDir"
  exit 0
}

Write-Info "Using markitdown: $mdCmd"
Write-Info "Source: $SrcDir"
Write-Info "Output: $OutDir"
if ($Recurse) { Write-Info "Search mode: recursive" } else { Write-Info "Search mode: non-recursive" }
if ($Force)   { Write-Info "Overwrite existing: enabled" } else { Write-Info "Overwrite existing: disabled" }
Write-Host ""

$converted = 0
$skipped   = 0
$failed    = 0
$stopwatch = [System.Diagnostics.Stopwatch]::StartNew()

foreach ($pdf in $files) {
  try {
    $outFile = Join-Path $OutDir ($pdf.BaseName + '.md')

    if (-not $Force -and (Test-Path -LiteralPath $outFile)) {
      Write-Info "Skip (exists): $($pdf.Name)"
      $skipped++
      continue
    }

    $actionDesc = "Convert: $($pdf.FullName) -> $outFile"
    if ($PSCmdlet.ShouldProcess($pdf.FullName, "markitdown -> $outFile")) {
      Write-Info $actionDesc

      # Invoke markitdown, capture stdout+stderr, then write UTF-8 markdown
      $mdOutput = & $mdCmd -- "$($pdf.FullName)" 2>&1
      $exitCode = $LASTEXITCODE

      if ($exitCode -ne 0) {
        Write-Warn "markitdown returned exit code $exitCode for: $($pdf.Name)"
        if ($mdOutput) {
          Write-Warn ($mdOutput | Out-String)
        }
        $failed++
        continue
      }

      # Write UTF-8 (with BOM in Windows PowerShell; UTF-8 in PowerShell 7+)
      $mdOutput | Out-File -FilePath $outFile -Encoding utf8
      $converted++
    }
  } catch {
    Write-ErrorLine "Failed to convert: $($pdf.FullName)"
    Write-ErrorLine $_.Exception.Message
    $failed++
  }
}

$stopwatch.Stop()
Write-Host ""
Write-Info "Done in $([Math]::Round($stopwatch.Elapsed.TotalSeconds, 2))s"
Write-Info "Converted: $converted"
Write-Info "Skipped  : $skipped"
Write-Info "Failed   : $failed"
