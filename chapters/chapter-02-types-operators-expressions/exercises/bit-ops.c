/*
 * ===================================================================
 * 📖 第2章 2.9 - 位运算符 练习
 * 🎯 练习名称: 位运算探索器 (Bit Operations Explorer)
 * 👨‍💻 作者: 费曼教授的C语言学生
 * 📅 创建时间: 2025-10-23
 * ===================================================================
 *
 * 🎓 费曼教授的解释:
 * "位运算就像在操作开关的电路板！
 *  每个比特就像一个小开关，可以是开(1)或关(0)。
 *
 *  想象你在管理一个有8个开关的控制面板：
 *  - & (与): 两个开关都开时灯才亮
 *  - | (或): 任一开关开时灯就亮
 *  - ^ (异或): 两个开关状态不同时灯才亮
 *  - ~ (非): 把所有开关状态反过来
 *  - << (左移): 把开关向左移动
 *  - >> (右移): 把开关向右移动"
 *
 * 🔍 学习要点:
 * 1. 理解二进制表示
 * 2. 掌握各种位运算符的使用
 * 3. 理解位运算的应用场景
 * 4. 学习位移操作
 * 5. 位运算的实际应用
 * ===================================================================
 */

#include <stdio.h>

// 函数：打印整数的二进制表示
void print_binary(unsigned int num) {
    printf("二进制: ");
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0 && i != 0) printf(" "); // 每4位加空格
    }
    printf("\n");
}

int main() {
    // 程序介绍
    printf("🔧 费曼教授的位运算探索器\n");
    printf("===========================\n");
    printf("让我们一起探索位运算的神奇世界！\n\n");

    // 示例数字
    unsigned int a = 60;  // 二进制: 0011 1100
    unsigned int b = 13;  // 二进制: 0000 1101

    printf("📊 基础数字演示:\n");
    printf("================\n");
    printf("a = %u\n", a);
    print_binary(a);
    printf("\n");
    printf("b = %u\n", b);
    print_binary(b);
    printf("\n");

    // ==================== 按位与运算 (&) ====================
    printf("🔗 按位与运算 (a & b):\n");
    printf("====================\n");
    unsigned int and_result = a & b;
    printf("a & b = %u\n", and_result);
    print_binary(and_result);
    printf("💡 解释: 只有对应位都为1时结果位才为1\n\n");

    // ==================== 按位或运算 (|) ====================
    printf("🔀 按位或运算 (a | b):\n");
    printf("====================\n");
    unsigned int or_result = a | b;
    printf("a | b = %u\n", or_result);
    print_binary(or_result);
    printf("💡 解释: 对应位只要有一个为1结果位就为1\n\n");

    // ==================== 按位异或运算 (^) ====================
    printf("🔄 按位异或运算 (a ^ b):\n");
    printf("====================\n");
    unsigned int xor_result = a ^ b;
    printf("a ^ b = %u\n", xor_result);
    print_binary(xor_result);
    printf("💡 解释: 对应位不同时结果位为1，相同时为0\n\n");

    // ==================== 按位取反运算 (~) ====================
    printf("🔁 按位取反运算 (~a):\n");
    printf("===================\n");
    unsigned int not_result = ~a;
    printf("~a = %u\n", not_result);
    print_binary(not_result);
    printf("💡 解释: 将所有位反转（1变0，0变1）\n");
    printf("⚠️  注意：由于是unsigned int，结果是 (2^32 - 1 - a)\n\n");

    // ==================== 左移运算 (<<) ====================
    printf("⬅️ 左移运算 (a << 2):\n");
    printf("===================\n");
    unsigned int left_shift_result = a << 2;
    printf("a << 2 = %u\n", left_shift_result);
    print_binary(left_shift_result);
    printf("💡 解释: 所有位向左移动2位，右边补0\n");
    printf("📈 数学效果: a * 2^2 = %u * 4 = %u\n\n", a, left_shift_result);

    // ==================== 右移运算 (>>) ====================
    printf("➡️ 右移运算 (a >> 2):\n");
    printf("===================\n");
    unsigned int right_shift_result = a >> 2;
    printf("a >> 2 = %u\n", right_shift_result);
    print_binary(right_shift_result);
    printf("💡 解释: 所有位向右移动2位，左边补0（unsigned）\n");
    printf("📉 数学效果: a / 2^2 = %u / 4 = %u\n\n", a, right_shift_result);

    // ==================== 实际应用演示 ====================
    printf("🎯 实际应用演示:\n");
    printf("================\n");

    // 1. 检查特定位是否为1
    printf("1️⃣ 检查特定位是否为1:\n");
    unsigned int test_num = 42; // 二进制: 0010 1010
    printf("检查数字 %u 的第3位是否为1:\n", test_num);
    print_binary(test_num);

    int bit_position = 3;
    if ((test_num >> bit_position) & 1) {
        printf("✅ 第%d位是1\n", bit_position);
    } else {
        printf("❌ 第%d位是0\n", bit_position);
    }
    printf("\n");

    // 2. 设置特定位为1
    printf("2️⃣ 设置特定位为1:\n");
    printf("将数字 %u 的第1位设置为1:\n", test_num);
    unsigned int set_result = test_num | (1 << 1);
    printf("结果: %u\n", set_result);
    print_binary(set_result);
    printf("\n");

    // 3. 清除特定位为0
    printf("3️⃣ 清除特定位为0:\n");
    printf("将数字 %u 的第5位清除为0:\n", set_result);
    unsigned int clear_result = set_result & ~(1 << 5);
    printf("结果: %u\n", clear_result);
    print_binary(clear_result);
    printf("\n");

    // 4. 切换特定位
    printf("4️⃣ 切换特定位:\n");
    printf("切换数字 %u 的第2位:\n", clear_result);
    unsigned int toggle_result = clear_result ^ (1 << 2);
    printf("结果: %u\n", toggle_result);
    print_binary(toggle_result);
    printf("\n");

    // 5. 快速乘除法演示
    printf("5️⃣ 快速乘除法演示:\n");
    unsigned int multiply_num = 10;
    printf("原始数字: %u\n", multiply_num);
    printf("%u << 1 = %u (相当于 * 2)\n", multiply_num, multiply_num << 1);
    printf("%u << 3 = %u (相当于 * 8)\n", multiply_num, multiply_num << 3);
    printf("%u >> 1 = %u (相当于 / 2)\n", multiply_num, multiply_num >> 1);
    printf("💡 位运算比乘除法更快！\n\n");

    // 6. 交换两个数（不使用临时变量）
    printf("6️⃣ 异或交换两个数:\n");
    unsigned int x = 5, y = 3;
    printf("交换前: x = %u, y = %u\n", x, y);
    x = x ^ y;
    y = x ^ y;  // y = (x ^ y) ^ y = x
    x = x ^ y;  // x = (x ^ y) ^ x = y
    printf("交换后: x = %u, y = %u\n", x, y);
    printf("🪄 神奇！没有使用临时变量就交换了两个数！\n\n");

    return 0;
}

/*
 * ===================================================================
 * 🎮 编译和运行指南:
 *
 * gcc bit-ops.c -o bit-ops
 * ./bit-ops
 *
 * ===================================================================
 *
 * 💡 费曼教授的思考题:
 *
 * 1. 为什么位运算比乘除法更快？
 * 2. 左移和右移在数学上等价于什么运算？
 * 3. 如何用位运算检查一个数是否是2的幂？
 * 4. 异或运算有什么特殊的性质？为什么可以用来交换两个数？
 * 5. 在实际编程中，位运算主要用在哪些场景？
 *
 * 🚀 扩展练习:
 *
 * 1. 编写函数，计算一个数中有多少个1位（汉明权重）
 * 2. 编写函数，检查一个数是否是2的幂
 * 3. 编写函数，反转一个数的所有位
 * 4. 实现简单的加密/解密程序（使用异或运算）
 * 5. 研究位移运算中算术移位和逻辑移位的区别
 *
 * ===================================================================
 */