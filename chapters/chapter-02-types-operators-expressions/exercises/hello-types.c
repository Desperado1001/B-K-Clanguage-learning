/*
 * ===================================================================
 * 📖 第2章 2.1-2.3 - 变量名、数据类型和常量 练习
 * 🎯 练习名称: 数据类型探索器 (Hello Types!)
 * 👨‍💻 作者: 费曼教授的C语言学生
 * 📅 创建时间: 2025-10-23
 * ===================================================================
 *
 * 🎓 费曼教授的解释:
 * "这个程序就像一个数据类型博物馆！
 *  它向你展示C语言中各种不同的数据类型，
 *  就像参观博物馆看不同的展品一样！
 *
 *  每种数据类型都有自己的特点和用途：
 *  - int 就像整数计数器，只能数整数
 *  - float 就像尺子，能量小数
 *  - char 就像字母积木，存储单个字符
 *  - double 就像高精度天平，更精确的小数"
 *
 * 🔍 学习要点:
 * 1. 理解各种基本数据类型
 * 2. 了解不同类型的大小 (sizeof)
 * 3. 看到各种类型的输出格式
 * 4. 理解常量的表示方法
 * 5. 体验类型的基本运算
 * ===================================================================
 */

#include <stdio.h>

int main() {
    // 程序介绍
    printf("🎭 C语言数据类型探索器\n");
    printf("======================\n\n");

    // ==================== 整数类型 ====================
    printf("📊 整数类型 (Integer Types):\n");
    printf("----------------------------\n");

    // 基本整数类型
    int integer_var = 42;
    short short_var = 1000;
    long long_var = 100000L;
    long long long_long_var = 9000000000LL;  // 需要 long long

    // 无符号整数类型
    unsigned int unsigned_int = 4000000000U;
    unsigned short unsigned_short = 65000U;
    unsigned long unsigned_long = 4000000000UL;

    // 显示整数变量
    printf("int integer_var = %d\n", integer_var);
    printf("short short_var = %hd\n", short_var);
    printf("long long_var = %ld\n", long_var);
    printf("long long long_long_var = %lld\n", long_long_var);
    printf("unsigned int unsigned_int = %u\n", unsigned_int);
    printf("unsigned short unsigned_short = %hu\n", unsigned_short);
    printf("unsigned long unsigned_long = %lu\n\n", unsigned_long);

    // 显示各种类型的大小
    printf("📏 数据类型大小 (Type Sizes):\n");
    printf("----------------------------\n");
    printf("sizeof(char) = %zu byte(s)\n", sizeof(char));
    printf("sizeof(short) = %zu byte(s)\n", sizeof(short));
    printf("sizeof(int) = %zu byte(s)\n", sizeof(int));
    printf("sizeof(long) = %zu byte(s)\n", sizeof(long));
    printf("sizeof(long long) = %zu byte(s)\n", sizeof(long long));
    printf("sizeof(float) = %zu byte(s)\n", sizeof(float));
    printf("sizeof(double) = %zu byte(s)\n", sizeof(double));
    printf("sizeof(long double) = %zu byte(s)\n\n", sizeof(long double));

    // ==================== 浮点类型 ====================
    printf("🌊 浮点类型 (Floating-Point Types):\n");
    printf("----------------------------\n");

    float float_var = 3.14159f;      // f 表示 float 常量
    double double_var = 2.718281828; // double 常量
    long double long_double_var = 1.23456789012345L; // L 表示 long double

    printf("float float_var = %.6f\n", float_var);
    printf("double double_var = %.12f\n", double_var);
    printf("long double long_double_var = %.15Lf\n\n", long_double_var);

    // ==================== 字符类型 ====================
    printf("📝 字符类型 (Character Types):\n");
    printf("----------------------------\n");

    char char_var = 'A';             // 字符常量
    signed char signed_char = -100;  // 有符号字符
    unsigned char unsigned_char = 200; // 无符号字符

    printf("char char_var = '%c' (ASCII: %d)\n", char_var, char_var);
    printf("signed char signed_char = %d\n", signed_char);
    printf("unsigned char unsigned_char = %u\n\n", unsigned_char);

    // 特殊字符常量
    printf("🔤 特殊字符常量 (Special Character Constants):\n");
    printf("----------------------------\n");
    printf("换行符: '\\n' 显示效果:\n");
    printf("制表符: '\\t' 显示效果:\t中间有制表符\n");
    printf("反斜杠: '\\\\' 显示效果: \\\n");
    printf("双引号: '\\\"' 显示效果: \"\n");
    printf("单引号: '\\'' 显示效果: '\n\n");

    // ==================== 常量演示 ====================
    printf("🔢 各种常量表示 (Constant Representations):\n");
    printf("----------------------------\n");

    // 整数常量的不同进制
    int decimal = 42;        // 十进制
    int octal = 052;         // 八进制 (以0开头)
    int hexadecimal = 0x2A;  // 十六进制 (以0x开头)

    printf("十进制 42 = %d\n", decimal);
    printf("八进制 052 = %d (十进制)\n", octal);
    printf("十六进制 0x2A = %d (十进制)\n\n", hexadecimal);

    // 浮点常量的不同表示
    float normal_float = 123.45f;
    float scientific_float = 1.2345e2f;  // 科学计数法

    printf("普通表示: %.2f\n", normal_float);
    printf("科学计数法: %.2e\n", scientific_float);
    printf("它们是相等的: %s\n", (normal_float == scientific_float) ? "是" : "否\n");

    // ==================== 简单运算演示 ====================
    printf("\n➕ 基本运算演示 (Basic Operations):\n");
    printf("----------------------------\n");

    int a = 10, b = 3;
    float x = 10.0f, y = 3.0f;

    printf("整数运算: %d + %d = %d\n", a, b, a + b);
    printf("整数运算: %d - %d = %d\n", a, b, a - b);
    printf("整数运算: %d * %d = %d\n", a, b, a * b);
    printf("整数运算: %d / %d = %d (整数除法!)\n", a, b, a / b);
    printf("整数运算: %d %% %d = %d (求余数)\n\n", a, b, a % b);

    printf("浮点运算: %.1f + %.1f = %.1f\n", x, y, x + y);
    printf("浮点运算: %.1f - %.1f = %.1f\n", x, y, x - y);
    printf("浮点运算: %.1f * %.1f = %.1f\n", x, y, x * y);
    printf("浮点运算: %.1f / %.1f = %.3f (浮点除法!)\n\n", x, y, x / y);

    // ==================== 类型转换演示 ====================
    printf("🔄 类型转换演示 (Type Conversion):\n");
    printf("----------------------------\n");

    int int_val = 5;
    float float_val = 2.5f;
    double result;

    // 隐式类型转换
    result = int_val + float_val;  // int 被转换为 float
    printf("int(5) + float(2.5) = double(%.1f)\n", result);

    // 强制类型转换
    result = (double)int_val / 2;  // 强制转换为 double
    printf("(double)int(5) / 2 = %.1f\n", result);

    // 整数除法 vs 浮点除法
    printf("5 / 2 = %d (整数除法)\n", 5 / 2);
    printf("5.0 / 2.0 = %.1f (浮点除法)\n", 5.0 / 2.0);

    return 0;
}

/*
 * ===================================================================
 * 🎮 编译和运行指南:
 *
 * gcc hello-types.c -o hello-types
 * ./hello-types
 *
 * ===================================================================
 *
 * 💡 费曼教授的思考题:
 *
 * 1. 为什么 sizeof(long) 的大小在不同系统上可能不同？
 * 2. 'A' 和 65 有什么关系？为什么 char 可以用 %d 显示？
 * 3. 为什么 5 / 2 等于 2，而 5.0 / 2.0 等于 2.5？
 * 4. 强制类型转换 (double)5 / 2 和 (double)(5 / 2) 有什么区别？
 * 5. 什么时候应该使用 float，什么时候使用 double？
 *
 * 🚀 扩展练习:
 *
 * 1. 尝试计算各种类型的最大值和最小值
 * 2. 研究整数溢出的情况
 * 3. 比较不同浮点数的精度
 * 4. 探索更多转义字符的使用
 * 5. 编写程序测试不同类型之间的转换
 *
 * ===================================================================
 */