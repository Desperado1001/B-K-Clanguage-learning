@echo off
REM ===================================================================
REM 🚀 C程序设计语言学习项目 - 快速编译运行脚本
REM 👨‍💻 作者: 费曼教授的Windows助手
REM 📅 创建时间: 2025-10-23
REM ===================================================================

echo 🎯 C程序学习项目 - 编译运行助手
echo ===================================

:menu
echo.
echo 请选择操作:
echo 第1章程序:
echo   1. Hello World
echo   2. 温度转换程序
echo   3. 单词计数器
echo 第2章程序:
echo   4. 数据类型探索器
echo   5. 交互式计算器
echo   6. 位运算探索器
echo   7. 单位转换器
echo 批量操作:
echo   8. 编译所有第1章程序
echo   9. 编译所有第2章程序
echo  10. 清理构建文件
echo  11. 退出
echo.
set /p choice=请输入选项 (1-11):

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
echo 无效选项，请重新选择！
goto menu

:hello-world
echo.
echo 🚀 编译运行 Hello World...
if not exist build mkdir build
gcc chapters\chapter-01-tutorial\exercises\hello-world.c -o build\hello-world.exe
if errorlevel 1 goto compile-error
build\hello-world.exe
echo.
echo ✅ Hello World 运行完成！
pause
goto menu

:temp-converter
echo.
echo 🌡️ 编译运行 温度转换程序...
if not exist build mkdir build
gcc chapters\chapter-01-tutorial\exercises\fahrenheit-celsius.c -o build\fahrenheit-celsius.exe
if errorlevel 1 goto compile-error
build\fahrenheit-celsius.exe
echo.
echo ✅ 温度转换程序运行完成！
pause
goto menu

:word-counter
echo.
echo 📊 编译运行 单词计数器...
if not exist build mkdir build
gcc chapters\chapter-01-tutorial\projects\word-counter.c -o build\word-counter.exe
if errorlevel 1 goto compile-error
build\word-counter.exe
echo.
echo ✅ 单词计数器运行完成！
pause
goto menu

:hello-types
echo.
echo 🎭 编译运行 数据类型探索器...
if not exist build mkdir build
gcc chapters\chapter-02-types-operators-expressions\exercises\hello-types.c -o build\hello-types.exe
if errorlevel 1 goto compile-error
build\hello-types.exe
echo.
echo ✅ 数据类型探索器运行完成！
pause
goto menu

:calculator
echo.
echo 🧮 编译运行 交互式计算器...
if not exist build mkdir build
gcc chapters\chapter-02-types-operators-expressions\exercises\calculator.c -o build\calculator.exe
if errorlevel 1 goto compile-error
build\calculator.exe
echo.
echo ✅ 交互式计算器运行完成！
pause
goto menu

:bit-ops
echo.
echo 🔧 编译运行 位运算探索器...
if not exist build mkdir build
gcc chapters\chapter-02-types-operators-expressions\exercises\bit-ops.c -o build\bit-ops.exe
if errorlevel 1 goto compile-error
build\bit-ops.exe
echo.
echo ✅ 位运算探索器运行完成！
pause
goto menu

:unit-converter
echo.
echo 🌍 编译运行 单位转换器...
if not exist build mkdir build
gcc chapters\chapter-02-types-operators-expressions\projects\unit-converter.c -o build\unit-converter.exe
if errorlevel 1 goto compile-error
build\unit-converter.exe
echo.
echo ✅ 单位转换器运行完成！
pause
goto menu

:build-chapter01
echo.
echo 📚 编译所有第1章程序...
if not exist build mkdir build

echo 正在编译 hello-world.c...
gcc chapters\chapter-01-tutorial\exercises\hello-world.c -o build\hello-world.exe
if errorlevel 1 goto compile-error

echo 正在编译 fahrenheit-celsius.c...
gcc chapters\chapter-01-tutorial\exercises\fahrenheit-celsius.c -o build\fahrenheit-celsius.exe
if errorlevel 1 goto compile-error

echo 正在编译 word-counter.c...
gcc chapters\chapter-01-tutorial\projects\word-counter.c -o build\word-counter.exe
if errorlevel 1 goto compile-error

echo.
echo.
echo ✅ 第1章所有程序编译完成！
echo 🎯 可执行文件位于 build\ 目录:
echo    - hello-world.exe
echo    - fahrenheit-celsius.exe
echo    - word-counter.exe
pause
goto menu

:build-chapter02
echo.
echo 📚 编译所有第2章程序...
if not exist build mkdir build

echo 正在编译 hello-types.c...
gcc chapters\chapter-02-types-operators-expressions\exercises\hello-types.c -o build\hello-types.exe
if errorlevel 1 goto compile-error

echo 正在编译 calculator.c...
gcc chapters\chapter-02-types-operators-expressions\exercises\calculator.c -o build\calculator.exe
if errorlevel 1 goto compile-error

echo 正在编译 bit-ops.c...
gcc chapters\chapter-02-types-operators-expressions\exercises\bit-ops.c -o build\bit-ops.exe
if errorlevel 1 goto compile-error

echo 正在编译 unit-converter.c...
gcc chapters\chapter-02-types-operators-expressions\projects\unit-converter.c -o build\unit-converter.exe
if errorlevel 1 goto compile-error

echo.
echo ✅ 第2章所有程序编译完成！
echo 🎯 可执行文件位于 build\ 目录:
echo    - hello-types.exe
echo    - calculator.exe
echo    - bit-ops.exe
echo    - unit-converter.exe
pause
goto menu

:clean
echo.
echo 🧹 清理构建文件...
if exist build rmdir /s /q build
echo ✅ 构建文件已清理！
pause
goto menu

:compile-error
echo.
echo ❌ 编译错误！请检查代码是否有语法错误。
pause
goto menu

:exit
echo.
echo 🎓 感谢使用 C语言学习助手！
echo 费曼教授说：记住，每个错误都是学习的机会！
echo.
pause