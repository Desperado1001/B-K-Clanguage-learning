/*
 * ===================================================================
 * 📖 第1章 综合项目
 * 🎯 项目名称: 单词计数器 (Word Counter)
 * 👨‍💻 作者: 费曼教授的C语言学生
 * 📅 创建时间: 2025-10-23
 * ===================================================================
 *
 * 🎓 费曼教授的解释:
 * "这个程序就像一个聪明的图书管理员！
 *  它能够：
 *  ✅ 数出文本中有多少个字符
 *  ✅ 数出有多少个单词
 *  ✅ 数出有多少行
 *
 *  想象你在分析一本书的长度，或者统计一篇作文的字数，
 *  这个程序就是你的好帮手！"
 *
 * 🔍 综合运用知识点:
 * 1. 字符输入输出 (getchar, putchar)
 * 2. 变量和运算符
 * 3. 控制流 (while循环, if-else)
 * 4. 字符数组处理
 * 5. 外部变量和作用域
 * ===================================================================
 */

#include <stdio.h>

// 定义状态常量 - 让代码更易读
#define IN  1   // 在单词内部
#define OUT 0   // 在单词外部

int main() {
    // 统计变量 - 给它们起清晰的名字
    int character_count = 0;    // 字符计数器
    int word_count = 0;        // 单词计数器
    int line_count = 0;        // 行计数器
    int current_char;          // 当前读取的字符
    int state = OUT;           // 当前状态：是否在单词中

    // 程序说明
    printf("📊 单词计数器程序\n");
    printf("================\n");
    printf("请输入文本内容 (按 Ctrl+D 或 Ctrl+Z 结束输入):\n\n");

    // 主循环 - 逐个字符读取输入
    while ((current_char = getchar()) != EOF) {
        // 字符计数：每个字符都计数
        character_count++;

        // 行计数：遇到换行符就增加
        if (current_char == '\n') {
            line_count++;
        }

        // 单词计数逻辑 - 这是核心算法！
        if (current_char == ' ' || current_char == '\n' || current_char == '\t') {
            // 遇到空白字符，说明单词结束了
            state = OUT;
        } else if (state == OUT) {
            // 之前不在单词中，现在遇到非空白字符，说明新单词开始了
            state = IN;
            word_count++;
        }
    }

    // 显示统计结果 - 美观的格式化输出
    printf("\n📈 统计结果:\n");
    printf("============\n");
    printf("📝 字符数: %d\n", character_count);
    printf("📚 单词数: %d\n", word_count);
    printf("📄 行数:   %d\n", line_count);

    // 计算额外信息
    if (line_count > 0) {
        float avg_chars_per_line = (float)character_count / line_count;
        float avg_words_per_line = (float)word_count / line_count;
        float avg_chars_per_word = (float)character_count / word_count;

        printf("\n📊 分析数据:\n");
        printf("============\n");
        printf("📏 平均每行字符数: %.1f\n", avg_chars_per_line);
        printf("📖 平均每行单词数: %.1f\n", avg_words_per_line);
        printf("✏️  平均每个单词字符数: %.1f\n", avg_chars_per_word);
    }

    // 根据统计结果给出评价
    printf("\n🎯 文本分析:\n");
    printf("============\n");
    if (word_count < 10) {
        printf("📝 这是一段简短的文本！\n");
    } else if (word_count < 50) {
        printf("📖 这是一段中等长度的文本。\n");
    } else {
        printf("📚 这是一段较长的文本！\n");
    }

    return 0;
}

/*
 * ===================================================================
 * 🎮 编译和运行指南:
 *
 * gcc word-counter.c -o word-counter
 * ./word-counter
 *
 * 运行后输入任意文本，然后按 Ctrl+D (Linux/Mac) 或 Ctrl+Z (Windows) 结束
 *
 * ===================================================================
 *
 * 🚀 扩展挑战:
 *
 * 1. 📊 添加更多统计功能：
 *    - 统计句子数量 (以 . ? ! 结尾)
 *    - 统计段落数量
 *    - 统计特定单词出现的次数
 *
 * 2. 🎨 改进用户界面：
 *    - 添加彩色输出
 *    - 更好的格式化显示
 *    - 进度条显示
 *
 * 3. 📁 文件处理：
 *    - 从文件读取内容
 *    - 将统计结果保存到文件
 *    - 支持命令行参数
 *
 * 4. 🔍 高级功能：
 *    - 忽略大小写进行单词统计
 *    - 支持多种语言
 *    - 生成简单的词频统计
 *
 * ===================================================================
 */