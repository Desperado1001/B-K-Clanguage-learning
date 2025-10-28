# B&K C Programming Language Learning (K&R C 2e)

[English](#english) | [中文](#中文)

[![CI](https://github.com/Desperado1001/B-K-Clanguage-learning/actions/workflows/ci.yml/badge.svg?branch=main)](https://github.com/Desperado1001/B-K-Clanguage-learning/actions/workflows/ci.yml)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](./LICENSE)
![C Standard](https://img.shields.io/badge/C-ANSI%20C%20(C89%2FC90)-blue)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](./.github/PULL_REQUEST_TEMPLATE.md)

---

## English

A curated, hands-on learning project to deeply study “The C Programming Language” (Kernighan & Ritchie, 2nd Edition). We follow a learn–practice–test–expand loop with project-based exercises to truly master the essence of C.

- Textbook: The C Programming Language (2nd Edition) by Brian W. Kernighan & Dennis M. Ritchie
- Standard: ANSI C (C89/C90)
- Focus: clarity, craftsmanship, and practical exercises

### Highlights
- Chapter-by-chapter guided notes and exercises
- Clean, consistent project structure and build helpers
- CI with GitHub Actions to compile all examples on every PR
- PR template for high-quality contributions
- MIT License

### Project Structure
    c_programming_language/
    ├─ README.md
    ├─ docs/                       # Reference materials (no copyrighted books committed)
    ├─ chapters/                   # Chapter notes, exercises, small projects
    │  └─ chapter-01-tutorial/
    │     ├─ README.md
    │     └─ exercises/
    │        ├─ hello-world.c
    │        └─ fahrenheit-celsius.c
    ├─ common/                     # Shared templates, tools, references
    ├─ tests/                      # Test cases (scaffold)
    ├─ progress/                   # Learning progress tracking
    ├─ build/                      # Build artifacts (gitignored)
    ├─ build-and-run.bat           # Windows helper script
    └─ .github/
       ├─ workflows/ci.yml         # GitHub Actions workflow
       └─ PULL_REQUEST_TEMPLATE.md # PR template

### Quick Start

- Requirements
  - A C compiler (GCC or Clang) and a shell/terminal
  - On Windows, you can use the provided batch script

- Compile examples (Linux/macOS)
  
      gcc chapters/chapter-01-tutorial/exercises/hello-world.c -o build/hello-world
      ./build/hello-world

      gcc chapters/chapter-01-tutorial/exercises/fahrenheit-celsius.c -o build/temp-converter
      ./build/temp-converter

- Compile and run on Windows

      build-and-run.bat
      (Select the program from the interactive menu)

### Continuous Integration (CI)

- The CI workflow automatically:
  - Checks out the code
  - Installs build tools on Ubuntu
  - Finds and compiles all C sources under chapters/**/exercises
- Status is visible via the badge at the top of this README.

### Contributing

- Fork the repository and create a feature branch
- Keep changes focused and well-documented
- Open a Pull Request using the template to describe
  - What changed and why
  - How it was tested
  - Related issues/links
- The CI build must pass

### Roadmap

- Add more chapter scaffolds and exercises
- Add simple unit tests for selected programs
- Provide cross-platform build helpers (e.g., Makefile/CMake)

### License

- MIT License (see LICENSE)

### Acknowledgements

- Brian W. Kernighan and Dennis M. Ritchie for creating C and the definitive textbook
- The open-source community for tools and inspiration

---

## 中文

一个围绕《C 程序设计语言》（K&R 第二版）的系统化学习项目。采用“学-练-测-拓”的闭环方式，通过实践项目真正吃透 C 语言本质。

- 参考教材：《C 程序设计语言（第 2 版）》Kernighan & Ritchie
- 标准版本：ANSI C（C89/C90）
- 项目风格：清晰、精致、注重实践

### 特色
- 按章节精读与练习
- 结构清晰、构建脚本友好
- GitHub Actions 持续集成：每次 PR 自动编译所有示例
- 统一的 PR 模板，确保高质量协作
- MIT 开源许可

### 目录结构
    c_programming_language/
    ├─ README.md
    ├─ docs/                       # 参考资料（不提交受版权保护的书籍）
    ├─ chapters/                   # 章节笔记、练习、小项目
    │  └─ chapter-01-tutorial/
    │     ├─ README.md
    │     └─ exercises/
    │        ├─ hello-world.c
    │        └─ fahrenheit-celsius.c
    ├─ common/                     # 公共模板、工具、参考
    ├─ tests/                      # 测试用例（脚手架）
    ├─ progress/                   # 学习进度追踪
    ├─ build/                      # 构建产物（已加入 .gitignore）
    ├─ build-and-run.bat           # Windows 一键编译运行脚本
    └─ .github/
       ├─ workflows/ci.yml         # CI 工作流
       └─ PULL_REQUEST_TEMPLATE.md # PR 模板

### 快速开始

- 环境要求
  - 安装 C 编译器（GCC 或 Clang）和终端/命令行环境
  - Windows 可使用提供的批处理脚本

- 编译示例（Linux/macOS）
  
      gcc chapters/chapter-01-tutorial/exercises/hello-world.c -o build/hello-world
      ./build/hello-world

      gcc chapters/chapter-01-tutorial/exercises/fahrenheit-celsius.c -o build/temp-converter
      ./build/temp-converter

- Windows 一键运行

      build-and-run.bat
      （在交互菜单中选择要运行的程序）

### 持续集成（CI）

- CI 工作流会：
  - 拉取代码
  - 在 Ubuntu 安装构建工具
  - 自动查找并编译 chapters/**/exercises 下的所有 C 源文件
- 构建状态可在本页顶部徽章查看。

### 贡献指南

- Fork 仓库并创建特性分支
- 变更应聚焦、清晰、附带必要说明
- 提交 PR 时使用模板，说明：
  - 改动内容与动机
  - 测试步骤
  - 相关问题/链接
- 确保 CI 通过

### 规划

- 增补更多章节脚手架与练习
- 为部分程序补充简单单元测试
- 提供跨平台构建辅助（如 Makefile/CMake）

### 许可证

- MIT（见 LICENSE 文件）

### 致谢

- 感谢 Brian W. Kernighan 与 Dennis M. Ritchie 创作 C 语言与经典教材
- 感谢开源社区提供的工具与灵感

---

Tip
- The original book PDF is not included in the repository to avoid copyright issues. Please obtain the book legally.
- 如需更多章节脚手架或改进建议，欢迎提交 Issue 或 PR。