@echo off
REM ===================================================================
REM UTF-8 编码批处理包装器
REM 此脚本会切换到 UTF-8 代码页，然后运行原始的 build-and-run.bat
REM ===================================================================

REM 保存当前代码页
for /f "tokens=2 delims=:" %%a in ('chcp') do set ORIGINAL_CP=%%a

REM 切换到 UTF-8 代码页
chcp 65001 >nul

REM 运行原始批处理文件
call "%~dp0build-and-run.bat"

REM 恢复原始代码页
chcp %ORIGINAL_CP% >nul
