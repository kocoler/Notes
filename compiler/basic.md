
### static single assignment form(SSA)

单静态赋值

是 IR(intermediate representation) 的特性，每个变量仅被赋值一次。

编译器优化的算法，可以借由SSA的使用，达到以下的改进：

常量传播 （constant propagation）
值域传播（value range propagation）
稀疏有条件的常量传播 （sparse conditional constant propagation）
消除无用的代码 （dead code elimination）
全局数值编号 （global value numbering）
消除部分的冗余 （partial redundancy elimination）
强度折减 （strength reduction）
寄存器配置 （register allocation）

### continuation-passing style (CPS)

In functional programming

### Meta programming

元编程，这类计算机程序编写或者操纵其它程序（或者自身）作为它们的资料，或者在运行时完成部分本应在编译时完成的工作。

元编程通常通过两种方式实现。
一种是通过应用程序编程接口（APIs）将运行时引擎的内部信息暴露于编程代码。
另一种是动态执行包含编程命令的字符串表达式。

### Homoiconicity

同像，即语言的源代码和 AST 同构

### Meta-circular evaluator
