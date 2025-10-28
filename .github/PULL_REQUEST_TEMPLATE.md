# Pull Request Template / 拉取请求模板

[English] | [中文]

---

## English

Please fill out the sections below. You can delete any parts that are not applicable.

### Summary
- What changed and why:
  - 
- Context/Background (optional):
  - 

### Type of change
- [ ] Bug fix (non-breaking change that fixes an issue)
- [ ] New feature/exercise (non-breaking change)
- [ ] Documentation update
- [ ] Refactor (no functional changes)
- [ ] CI/configuration
- [ ] Other:

### Scope
- Affected chapters/paths (check all that apply):
  - [ ] `chapters/chapter-01-tutorial`
  - [ ] `chapters/chapter-02-*`
  - [ ] `common/*`
  - [ ] `tests/*`
  - [ ] `.github/*`
  - [ ] Other:

### How to test
- Local build steps (Linux/macOS):
  - Ensure a C compiler is installed (gcc/clang)
  - Example: `gcc chapters/chapter-01-tutorial/exercises/hello-world.c -o build/hello-world && ./build/hello-world`
- Local build steps (Windows):
  - Run `build-and-run.bat` and choose the target from the menu
- Additional validation (optional):
  - Inputs/outputs verified:
  - Edge cases covered:

### Screenshots / Logs (optional)
- If UI/console output changed, paste or describe relevant output here.

### Breaking changes
- [ ] This change breaks backward compatibility
- Migration notes (if any):

### Linked issues
- Closes #
- Related to #

### Checklist
- [ ] Code compiles locally
- [ ] CI is expected to pass (or is already passing)
- [ ] No new warnings with `-Wall -Wextra`
- [ ] C standard respected: ANSI C (C89/C90) where applicable
- [ ] Files placed under correct directories (e.g., `chapters/**/exercises`)
- [ ] Documentation updated (README/notes), if needed
- [ ] Tests updated/added, if applicable
- [ ] No secrets, credentials, or copyrighted materials committed
- [ ] Self-review completed (naming, comments, small and focused changes)

### Additional notes for reviewers (optional)
- 

---

## 中文

请填写以下内容；不适用的部分可以删除。

### 变更摘要
- 变更内容与原因：
  - 
- 背景/上下文（可选）：
  - 

### 变更类型
- [ ] 缺陷修复（不影响兼容性）
- [ ] 新特性/新练习（不影响兼容性）
- [ ] 文档更新
- [ ] 重构（无功能变更）
- [ ] CI/配置
- [ ] 其他：

### 影响范围
- 受影响的章节/路径（勾选所有相关项）：
  - [ ] `chapters/chapter-01-tutorial`
  - [ ] `chapters/chapter-02-*`
  - [ ] `common/*`
  - [ ] `tests/*`
  - [ ] `.github/*`
  - [ ] 其他：

### 测试方法
- 本地构建（Linux/macOS）：
  - 确认已安装 C 编译器（gcc/clang）
  - 示例：`gcc chapters/chapter-01-tutorial/exercises/hello-world.c -o build/hello-world && ./build/hello-world`
- 本地构建（Windows）：
  - 运行 `build-and-run.bat` 并在菜单中选择目标程序
- 其他验证（可选）：
  - 输入/输出校验：
  - 边界用例覆盖：

### 截图 / 日志（可选）
- 若有 UI/控制台输出变更，请粘贴或描述关键信息。

### 兼容性影响
- [ ] 此变更可能引入不兼容
- 迁移说明（如有）：

### 关联问题
- 关闭（Closes） #
- 相关（Related） #

### 提交检查清单
- [ ] 本地可编译通过
- [ ] CI 预计通过（或已通过）
- [ ] 使用 `-Wall -Wextra` 无新增告警
- [ ] 符合 ANSI C（C89/C90）规范（如适用）
- [ ] 文件放置在正确目录（如 `chapters/**/exercises`）
- [ ] 如需，已更新文档（README/笔记）
- [ ] 如适用，已更新/新增测试
- [ ] 未提交任何密钥、凭证或受版权保护的内容
- [ ] 已自检（命名、注释、变更小而聚焦）

### 评审补充说明（可选）
- 
