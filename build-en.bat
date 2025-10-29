@echo off
REM ===================================================================
REM C Programming Language Learning Project - Build and Run Script
REM Author: Feynman's Windows Assistant
REM Created: 2025-10-23
REM ===================================================================

echo C Programming Learning Project - Build Assistant
echo ===================================

:menu
echo.
echo Please select an option:
echo Chapter 1 Programs:
echo   1. Hello World
echo   2. Temperature Converter
echo   3. Word Counter
echo Chapter 2 Programs:
echo   4. Data Types Explorer
echo   5. Interactive Calculator
echo   6. Bitwise Operations Explorer
echo   7. Unit Converter
echo Batch Operations:
echo   8. Build all Chapter 1 programs
echo   9. Build all Chapter 2 programs
echo  10. Clean build files
echo  11. Exit
echo.
set /p choice=Enter your choice (1-11):

if "%choice%"=="1" goto hello-world
if "%choice%"=="2" goto temp-converter
if "%choice%"=="3" goto word-counter
if "%choice%"=="4" goto hello-types
if "%choice%"=="5" goto calculator
if "%choice%"=="6" goto bit-ops
if "%choice%"=="7" goto unit-converter
if "%choice%"=="8" goto build-chapter01
if "%choice%"=="9" goto build-chapter02
if "%choice%"=="10" goto clean
if "%choice%"=="11" goto exit
echo Invalid option, please try again!
goto menu

:hello-world
echo.
echo [BUILD] Compiling Hello World...
if not exist build mkdir build
gcc chapters\chapter-01-tutorial\exercises\hello-world.c -o build\hello-world.exe
if errorlevel 1 goto compile-error
build\hello-world.exe
echo.
echo [DONE] Hello World completed!
pause
goto menu

:temp-converter
echo.
echo [BUILD] Compiling Temperature Converter...
if not exist build mkdir build
gcc chapters\chapter-01-tutorial\exercises\fahrenheit-celsius.c -o build\fahrenheit-celsius.exe
if errorlevel 1 goto compile-error
build\fahrenheit-celsius.exe
echo.
echo [DONE] Temperature Converter completed!
pause
goto menu

:word-counter
echo.
echo [BUILD] Compiling Word Counter...
if not exist build mkdir build
gcc chapters\chapter-01-tutorial\projects\word-counter.c -o build\word-counter.exe
if errorlevel 1 goto compile-error
build\word-counter.exe
echo.
echo [DONE] Word Counter completed!
pause
goto menu

:hello-types
echo.
echo [BUILD] Compiling Data Types Explorer...
if not exist build mkdir build
gcc chapters\chapter-02-types-operators-expressions\exercises\hello-types.c -o build\hello-types.exe
if errorlevel 1 goto compile-error
build\hello-types.exe
echo.
echo [DONE] Data Types Explorer completed!
pause
goto menu

:calculator
echo.
echo [BUILD] Compiling Interactive Calculator...
if not exist build mkdir build
gcc chapters\chapter-02-types-operators-expressions\exercises\calculator.c -o build\calculator.exe
if errorlevel 1 goto compile-error
build\calculator.exe
echo.
echo [DONE] Interactive Calculator completed!
pause
goto menu

:bit-ops
echo.
echo [BUILD] Compiling Bitwise Operations Explorer...
if not exist build mkdir build
gcc chapters\chapter-02-types-operators-expressions\exercises\bit-ops.c -o build\bit-ops.exe
if errorlevel 1 goto compile-error
build\bit-ops.exe
echo.
echo [DONE] Bitwise Operations Explorer completed!
pause
goto menu

:unit-converter
echo.
echo [BUILD] Compiling Unit Converter...
if not exist build mkdir build
gcc chapters\chapter-02-types-operators-expressions\projects\unit-converter.c -o build\unit-converter.exe
if errorlevel 1 goto compile-error
build\unit-converter.exe
echo.
echo [DONE] Unit Converter completed!
pause
goto menu

:build-chapter01
echo.
echo [BATCH] Building all Chapter 1 programs...
if not exist build mkdir build

echo Compiling hello-world.c...
gcc chapters\chapter-01-tutorial\exercises\hello-world.c -o build\hello-world.exe
if errorlevel 1 goto compile-error

echo Compiling fahrenheit-celsius.c...
gcc chapters\chapter-01-tutorial\exercises\fahrenheit-celsius.c -o build\fahrenheit-celsius.exe
if errorlevel 1 goto compile-error

echo Compiling word-counter.c...
gcc chapters\chapter-01-tutorial\projects\word-counter.c -o build\word-counter.exe
if errorlevel 1 goto compile-error

echo.
echo [SUCCESS] All Chapter 1 programs built successfully!
echo Executables are in the build\ directory:
echo    - hello-world.exe
echo    - fahrenheit-celsius.exe
echo    - word-counter.exe
pause
goto menu

:build-chapter02
echo.
echo [BATCH] Building all Chapter 2 programs...
if not exist build mkdir build

echo Compiling hello-types.c...
gcc chapters\chapter-02-types-operators-expressions\exercises\hello-types.c -o build\hello-types.exe
if errorlevel 1 goto compile-error

echo Compiling calculator.c...
gcc chapters\chapter-02-types-operators-expressions\exercises\calculator.c -o build\calculator.exe
if errorlevel 1 goto compile-error

echo Compiling bit-ops.c...
gcc chapters\chapter-02-types-operators-expressions\exercises\bit-ops.c -o build\bit-ops.exe
if errorlevel 1 goto compile-error

echo Compiling unit-converter.c...
gcc chapters\chapter-02-types-operators-expressions\projects\unit-converter.c -o build\unit-converter.exe
if errorlevel 1 goto compile-error

echo.
echo [SUCCESS] All Chapter 2 programs built successfully!
echo Executables are in the build\ directory:
echo    - hello-types.exe
echo    - calculator.exe
echo    - bit-ops.exe
echo    - unit-converter.exe
pause
goto menu

:clean
echo.
echo [CLEAN] Cleaning build files...
if exist build rmdir /s /q build
echo [DONE] Build files cleaned!
pause
goto menu

:compile-error
echo.
echo [ERROR] Compilation failed! Please check your code for syntax errors.
pause
goto menu

:exit
echo.
echo Thank you for using the C Learning Assistant!
echo Professor Feynman says: Remember, every error is a learning opportunity!
echo.
pause
