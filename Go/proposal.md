Golang/Proposal
===

> 本文档为 golang/proposal 学习计划
> *除了部分，其他都不是逐字逐句翻译的

### [27539-internal-abi](https://github.com/golang/proposal/blob/master/design/27539-internal-abi.md)

前置知识:
- ABI
- OS
- calling convention

trace:

概要:
Go 目前的调用共约(calling convention, 这里是指函数的调用规约)涉及到了很多明显的优化, 这里提到了 register passing。但是在实现的时候，遇到了很大的问题。虽然 Go 的兼容性保证(Go 1 compatibility promise)并没有约束调用公约，但是如果没有调用公约，编写 Go 的汇编代码是不可能的。所以，Go 的大部分调用约定是公开的，并且必须以向后兼容的方式进行维护。

我们提出了一个基于多种调用规约的办法。我们建议维护现有的调用规约，并且引入一个新的，私有的调用规约，新的调用规约并不明确向后兼容并且对于汇编代码来说并不可见。然后再提供一个机制去保持不同的调用规约之间的互操作。这种机制可以用于未来引进其他的调用规约，具体的内容不属于本提案。

这个提案不包含任何具体的新调用规约。只是关于开始将新的调用规约引入先用的 Go 生态中。这是长期计划的(第)一步。

> 从这里我们就可以看出来，通过调用规约这个契机，我们可以对 ABI 部分进行新的改进。
> 我认为这是一个很大的改进。
> 从体量及未来说都是

背景：

ABI 中重要一个概念就是调用规约。
**which defines how function calls in the language operate at a machine-code level**
在机器码层面定义了语言函数调用操作


