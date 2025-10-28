/*
 * ===================================================================
 * 📖 第2章 综合项目
 * 🎯 项目名称: 通用单位转换器 (Universal Unit Converter)
 * 👨‍💻 作者: 费曼教授的C语言学生
 * 📅 创建时间: 2025-10-23
 * ===================================================================
 *
 * 🎓 费曼教授的解释:
 * "这个项目就像一个万能翻译官！
 *  它能在不同的'语言'（单位系统）之间翻译：
 *  - 长度：米↔英尺↔英寸↔厘米
 *  - 重量：公斤↔磅↔盎司↔克
 *  - 温度：摄氏度↔华氏度↔开尔文
 *  - 时间：秒↔分钟↔小时↔天
 *
 *  想象你在出国旅游，需要把当地的单位转换成你熟悉的单位，
 *  这个程序就是你的好帮手！"
 *
 * 🔍 综合运用知识点:
 * 1. 各种数据类型的使用 (int, double, char)
 * 2. 算术运算符 (+, -, *, /)
 * 3. 关系和逻辑运算符 (>, <, ==, &&, ||)
 * 4. 类型转换 (显式和隐式)
 * 5. 运算符优先级
 * 6. 表达式的复杂计算
 * 7. 输入输出处理
 * 8. 控制流 (switch-case, if-else)
 * ===================================================================
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 函数声明
void show_menu();
void length_converter();
void weight_converter();
void temperature_converter();
void time_converter();
void clear_input_buffer();

int main() {
    printf("🌍 费曼教授的通用单位转换器\n");
    printf("==============================\n");
    printf("支持长度、重量、温度、时间的单位转换！\n\n");

    int choice;
    char continue_choice;

    do {
        show_menu();
        printf("请选择转换类型 (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("❌ 输入错误，请输入数字！\n");
            clear_input_buffer();
            continue;
        }

        switch (choice) {
            case 1:
                length_converter();
                break;
            case 2:
                weight_converter();
                break;
            case 3:
                temperature_converter();
                break;
            case 4:
                time_converter();
                break;
            default:
                printf("❌ 无效选择，请输入1-4之间的数字！\n");
                break;
        }

        printf("\n是否继续转换？(y/n): ");
        clear_input_buffer();
        scanf(" %c", &continue_choice);
        printf("\n");

    } while (tolower(continue_choice) == 'y');

    printf("👋 感谢使用费曼单位转换器！\n");

    return 0;
}

void show_menu() {
    printf("📋 转换菜单:\n");
    printf("============\n");
    printf("1. 📏 长度转换\n");
    printf("2. ⚖️ 重量转换\n");
    printf("3. 🌡️ 温度转换\n");
    printf("4. ⏰ 时间转换\n");
    printf("============\n");
}

void length_converter() {
    printf("\n📏 长度单位转换器\n");
    printf("================\n");
    printf("支持的单位: 米(m), 英尺(ft), 英寸(in), 厘米(cm)\n\n");

    double value;
    char from_unit[10], to_unit[10];
    double result;

    printf("请输入数值: ");
    if (scanf("%lf", &value) != 1) {
        printf("❌ 数值输入错误！\n");
        return;
    }

    printf("从单位 (m/ft/in/cm): ");
    scanf("%s", from_unit);
    printf("到单位 (m/ft/in/cm): ");
    scanf("%s", to_unit);

    // 先转换为米作为基准
    double meters = 0.0;

    if (strcmp(from_unit, "m") == 0) {
        meters = value;
    } else if (strcmp(from_unit, "cm") == 0) {
        meters = value / 100.0;        // 1米 = 100厘米
    } else if (strcmp(from_unit, "ft") == 0) {
        meters = value * 0.3048;       // 1英尺 = 0.3048米
    } else if (strcmp(from_unit, "in") == 0) {
        meters = value * 0.0254;       // 1英寸 = 0.0254米
    } else {
        printf("❌ 不支持的源单位: %s\n", from_unit);
        return;
    }

    // 从米转换到目标单位
    if (strcmp(to_unit, "m") == 0) {
        result = meters;
    } else if (strcmp(to_unit, "cm") == 0) {
        result = meters * 100.0;       // 1米 = 100厘米
    } else if (strcmp(to_unit, "ft") == 0) {
        result = meters / 0.3048;      // 1英尺 = 0.3048米
    } else if (strcmp(to_unit, "in") == 0) {
        result = meters / 0.0254;      // 1英寸 = 0.0254米
    } else {
        printf("❌ 不支持的目标单位: %s\n", to_unit);
        return;
    }

    printf("📊 转换结果: %.4f %s = %.4f %s\n", value, from_unit, result, to_unit);
}

void weight_converter() {
    printf("\n⚖️ 重量单位转换器\n");
    printf("================\n");
    printf("支持的单位: 公斤(kg), 磅(lb), 盎司(oz), 克(g)\n\n");

    double value;
    char from_unit[10], to_unit[10];
    double result;

    printf("请输入数值: ");
    if (scanf("%lf", &value) != 1) {
        printf("❌ 数值输入错误！\n");
        return;
    }

    printf("从单位 (kg/lb/oz/g): ");
    scanf("%s", from_unit);
    printf("到单位 (kg/lb/oz/g): ");
    scanf("%s", to_unit);

    // 先转换为公斤作为基准
    double kilograms = 0.0;

    if (strcmp(from_unit, "kg") == 0) {
        kilograms = value;
    } else if (strcmp(from_unit, "g") == 0) {
        kilograms = value / 1000.0;    // 1公斤 = 1000克
    } else if (strcmp(from_unit, "lb") == 0) {
        kilograms = value * 0.453592;  // 1磅 = 0.453592公斤
    } else if (strcmp(from_unit, "oz") == 0) {
        kilograms = value * 0.0283495; // 1盎司 = 0.0283495公斤
    } else {
        printf("❌ 不支持的源单位: %s\n", from_unit);
        return;
    }

    // 从公斤转换到目标单位
    if (strcmp(to_unit, "kg") == 0) {
        result = kilograms;
    } else if (strcmp(to_unit, "g") == 0) {
        result = kilograms * 1000.0;   // 1公斤 = 1000克
    } else if (strcmp(to_unit, "lb") == 0) {
        result = kilograms / 0.453592; // 1磅 = 0.453592公斤
    } else if (strcmp(to_unit, "oz") == 0) {
        result = kilograms / 0.0283495; // 1盎司 = 0.0283495公斤
    } else {
        printf("❌ 不支持的目标单位: %s\n", to_unit);
        return;
    }

    printf("📊 转换结果: %.4f %s = %.4f %s\n", value, from_unit, result, to_unit);
}

void temperature_converter() {
    printf("\n🌡️ 温度单位转换器\n");
    printf("================\n");
    printf("支持的单位: 摄氏度(°C), 华氏度(°F), 开尔文(K)\n\n");

    double value;
    char from_unit[10], to_unit[10];
    double result;

    printf("请输入数值: ");
    if (scanf("%lf", &value) != 1) {
        printf("❌ 数值输入错误！\n");
        return;
    }

    printf("从单位 (C/F/K): ");
    scanf("%s", from_unit);
    printf("到单位 (C/F/K): ");
    scanf("%s", to_unit);

    // 先转换为摄氏度作为基准
    double celsius = 0.0;

    if (strcmp(from_unit, "C") == 0) {
        celsius = value;
    } else if (strcmp(from_unit, "F") == 0) {
        celsius = (value - 32.0) * 5.0 / 9.0;  // F = C*9/5 + 32
    } else if (strcmp(from_unit, "K") == 0) {
        celsius = value - 273.15;              // K = C + 273.15
    } else {
        printf("❌ 不支持的源单位: %s\n", from_unit);
        return;
    }

    // 从摄氏度转换到目标单位
    if (strcmp(to_unit, "C") == 0) {
        result = celsius;
    } else if (strcmp(to_unit, "F") == 0) {
        result = celsius * 9.0 / 5.0 + 32.0;   // F = C*9/5 + 32
    } else if (strcmp(to_unit, "K") == 0) {
        result = celsius + 273.15;             // K = C + 273.15
    } else {
        printf("❌ 不支持的目标单位: %s\n", to_unit);
        return;
    }

    printf("📊 转换结果: %.2f°%s = %.2f°%s\n", value, from_unit, result, to_unit);
}

void time_converter() {
    printf("\n⏰ 时间单位转换器\n");
    printf("================\n");
    printf("支持的单位: 秒(s), 分钟(min), 小时(h), 天(d)\n\n");

    double value;
    char from_unit[10], to_unit[10];
    double result;

    printf("请输入数值: ");
    if (scanf("%lf", &value) != 1) {
        printf("❌ 数值输入错误！\n");
        return;
    }

    printf("从单位 (s/min/h/d): ");
    scanf("%s", from_unit);
    printf("到单位 (s/min/h/d): ");
    scanf("%s", to_unit);

    // 先转换为秒作为基准
    double seconds = 0.0;

    if (strcmp(from_unit, "s") == 0) {
        seconds = value;
    } else if (strcmp(from_unit, "min") == 0) {
        seconds = value * 60.0;       // 1分钟 = 60秒
    } else if (strcmp(from_unit, "h") == 0) {
        seconds = value * 3600.0;     // 1小时 = 3600秒
    } else if (strcmp(from_unit, "d") == 0) {
        seconds = value * 86400.0;    // 1天 = 86400秒
    } else {
        printf("❌ 不支持的源单位: %s\n", from_unit);
        return;
    }

    // 从秒转换到目标单位
    if (strcmp(to_unit, "s") == 0) {
        result = seconds;
    } else if (strcmp(to_unit, "min") == 0) {
        result = seconds / 60.0;      // 1分钟 = 60秒
    } else if (strcmp(to_unit, "h") == 0) {
        result = seconds / 3600.0;    // 1小时 = 3600秒
    } else if (strcmp(to_unit, "d") == 0) {
        result = seconds / 86400.0;   // 1天 = 86400秒
    } else {
        printf("❌ 不支持的目标单位: %s\n", to_unit);
        return;
    }

    printf("📊 转换结果: %.2f %s = %.2f %s\n", value, from_unit, result, to_unit);
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/*
 * ===================================================================
 * 🎮 编译和运行指南:
 *
 * gcc unit-converter.c -o unit-converter
 * ./unit-converter
 *
 * ===================================================================
 *
 * 💡 费曼教授的思考题:
 *
 * 1. 为什么在温度转换中，摄氏度到华氏度的公式是 F = C*9/5 + 32？
 * 2. 在这个程序中，为什么要先转换为基准单位再转换到目标单位？
 * 3. 如果用户输入了负数的长度或重量，程序会怎么处理？这样合理吗？
 * 4. 如何改进这个程序，让它支持更多的单位？
 * 5. 为什么使用 double 而不是 float 来存储转换结果？
 *
 * 🚀 扩展挑战:
 *
 * 1. 📊 添加更多单位类型：
 *    - 面积：平方米↔平方英尺↔平方英寸
 *    - 体积：升↔加仑↔立方米
 *    - 速度：米/秒↔公里/小时↔英里/小时
 *    - 压力：帕斯卡↔大气压↔毫米汞柱
 *
 * 2. 🎨 改进用户界面：
 *    - 添加彩色输出
 *    - 更好的错误处理
 *    - 历史记录功能
 *    - 批量转换模式
 *
 * 3. 📁 数据持久化：
 *    - 保存常用转换
 *    - 自定义单位
 *    - 配置文件
 *
 * 4. 🔍 高级功能：
 *    - 支持复合单位转换（如 km/h 转换为 m/s）
 *    - 精度控制
 *    - 科学计数法支持
 *    - 单位验证和自动纠错
 *
 * ===================================================================
 */