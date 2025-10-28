# 📖 Chapter 3: Control Flow | 第3章：控制流

[English](#english) | [中文](#中文)

---

## English

Master the building blocks of program execution: decisions, loops, and structured exits. In this chapter, you’ll learn how to control the path of execution precisely and write clear, idiomatic C.

### Objectives
- Understand and use core control structures:
  - if, else-if ladder, switch
  - while, for, do-while loops
  - break, continue, goto (with caution)
- Choose the right construct for clarity and correctness
- Recognize precedence between assignment/conditions
- Write side-effect-safe loop conditions and branches

### Chapter Outline (K&R 2e mapping)
- 3.1 Statements and Blocks
- 3.2 If-Else
- 3.3 Else-If Ladder
- 3.4 Switch
- 3.5 Loops
- 3.6 While and For
- 3.7 Do-While
- 3.8 Break and Continue
- 3.9 Goto and Labels (rarely used in modern code; read to understand legacy patterns)

### Study Plan (suggested 5–8 hours)
- Day 1
  - Theory: if/else, else-if ladder, blocks
  - Practice: branch basics, boundary conditions
- Day 2
  - Theory: while, for, do-while, loop invariants
  - Practice: loop conversion (while <-> for), fencepost problems
- Day 3
  - Theory: switch, break/continue, goto (reading only)
  - Practice: menu-driven switch programs, controlled exits

### Exercises (exercises/)
- if-else-basics.c — Simple branching and range categorization
- else-if-ladder.c — Grading or tiered pricing
- while-loop-basics.c — Input-driven accumulation (e.g., sum until EOF)
- for-loop-patterns.c — Pattern printing; loop invariants
- do-while-io.c — Menu loop with validated input
- break-continue-demo.c — Skipping/terminating within loops
- switch-menu.c — Command/option selector with default case
- fizzbuzz.c — Classic loop/branch practice (neatly and efficiently)
- min-max-stream.c — Read a stream of numbers and track min/max
- binary-search-steps.c — Count comparisons to compare variants (ties to K&R 3-1)

Optional (advanced or exploratory)
- goto-pitfall.c — Small demo showing why goto often reduces clarity; show structured alternative

### Projects (projects/)
- menu-toolkit.c — A menu-driven utility:
  - Options: compute factorial, GCD, average, temperature convert
  - Uses switch for command routing, do-while for main loop
- histogram-control-flow.c — Word length or character-class histogram:
  - Read stdin, build bins with loops
  - Use continue/break for edge conditions

Tip: Place your C files under chapters/chapter-03-control-flow/exercises or projects so CI can compile exercises automatically.

### Common Pitfalls and Patterns
- Dangling else: Always use braces for clarity with nested if
- Off-by-one errors: Check loop bounds, especially with indexes
- Break vs continue: Be intentional; comment non-obvious flows
- Switch fall-through: Use explicit break; if intentional, comment “/* fall through */”
- Do-while: Prefer when you need at least one iteration
- Loop conditions with side effects: Avoid hidden side effects; be explicit

### Self-Check
- [ ] I can rewrite any while loop as a for loop and vice versa
- [ ] I always brace multi-line branches (and I prefer bracing single-line ones for safety)
- [ ] I know when to choose switch over else-if ladder
- [ ] I can explain break vs continue and when to use each
- [ ] I can detect and fix off-by-one and fencepost errors
- [ ] I can implement and compare two binary search variants and reason about comparisons

### Build & Run

Linux/macOS:
- gcc chapters/chapter-03-control-flow/exercises/if-else-basics.c -o build/if-else-basics
- ./build/if-else-basics

Windows:
- gcc chapters\chapter-03-control-flow\exercises\if-else-basics.c -o build\if-else-basics.exe
- build\if-else-basics.exe

Note
- CI will attempt to compile all files under chapters/**/exercises.
- Prefer ANSI C (C89/C90) compatible code unless otherwise noted.

---

## 中文

掌握程序执行的基本“交通规则”：分支、循环与受控退出。你将学会精确控制程序的执行路径，并写出清晰、符合习惯的 C 代码。

### 学习目标
- 熟练使用核心控制结构：
  - if、else-if 梯形结构、switch
  - while、for、do-while 循环
  - break、continue、goto（谨慎使用）
- 根据场景选择最合适的控制结构，提升可读性和正确性
- 理解条件与赋值、短路求值的行为
- 写出副作用可控的分支与循环条件

### 本章目录（K&R 2e 对应）
- 3.1 语句与代码块
- 3.2 if-else
- 3.3 else-if 梯形结构
- 3.4 switch
- 3.5 循环
- 3.6 while 与 for
- 3.7 do-while
- 3.8 break 与 continue
- 3.9 goto 与标签（现代代码很少使用；理解历史即可）

### 学习计划（建议 5–8 小时）
- 第1天
  - 理论：if/else、else-if 梯形、代码块
  - 实践：分支基础与边界条件
- 第2天
  - 理论：while、for、do-while、循环不变式
  - 实践：循环相互转换，围栏/边界问题
- 第3天
  - 理论：switch、break/continue、goto（仅阅读理解）
  - 实践：菜单式程序、受控中断

### 练习（exercises/）
- if-else-basics.c — 简单分支与区间判断
- else-if-ladder.c — 分段评分/分层定价
- while-loop-basics.c — 基于输入的累加（例如读到 EOF 停止）
- for-loop-patterns.c — 图形/模式打印；循环不变式
- do-while-io.c — 菜单循环与输入校验
- break-continue-demo.c — 在循环中跳过/提前终止
- switch-menu.c — 命令/选项选择与默认分支
- fizzbuzz.c — 经典循环/分支练习（优雅高效）
- min-max-stream.c — 读取数字流并维护最值
- binary-search-steps.c — 统计比较次数以对比变体（呼应 K&R 3-1）

可选（进阶/探索）
- goto-pitfall.c — 小示例展示 goto 降低可读性，给出结构化替代方案

### 项目实践（projects/）
- menu-toolkit.c — 菜单驱动工具集：
  - 选项示例：阶乘、最大公约数、平均值、温度转换
  - 用 switch 分发命令、do-while 维护主循环
- histogram-control-flow.c — 单词长度或字符类别直方图：
  - 读取标准输入，用循环构建统计
  - 用 continue/break 处理边界场景

提示：将 C 文件放在 chapters/chapter-03-control-flow/exercises 或 projects 下，CI 会自动编译 exercises。

### 常见陷阱与模式
- 悬挂 else：嵌套 if 时总是使用花括号让结构清晰
- Off-by-one：检查循环边界，尤其是数组/下标
- break vs continue：有意为之并注释不明显的路径
- switch 落空：默认使用 break；若有意 fall-through，请显式注释“/* fall through */”
- do-while：当你需要至少执行一次循环体时使用
- 条件副作用：避免隐蔽副作用；显式表达优先

### 自测清单
- [ ] 能将 while 与 for 互相转换，并说出各自适用场景
- [ ] 即使单行分支，也倾向加花括号保证可维护性
- [ ] 知道何时用 switch 替代 else-if 梯形
- [ ] 能说明 break 与 continue 的差异及使用时机
- [ ] 能定位并修复 Off-by-one/围栏错误
- [ ] 能实现两种二分查找变体并比较其比较次数

### 构建与运行

Linux/macOS：
- gcc chapters/chapter-03-control-flow/exercises/if-else-basics.c -o build/if-else-basics
- ./build/if-else-basics

Windows：
- gcc chapters\chapter-03-control-flow\exercises\if-else-basics.c -o build\if-else-basics.exe
- build\if-else-basics.exe

说明
- CI 会尝试编译 chapters/**/exercises 下的所有源文件。
- 优先保持 ANSI C（C89/C90）兼容。

---

Progress
- Difficulty: ⭐⭐⭐☆☆ (Intermediate)
- Suggested Time: 5–8 hours
- Goal: Reliability first; clarity always. Use braces, avoid surprises, and comment intentional control transfers.