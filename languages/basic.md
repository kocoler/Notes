
### 一等公民

first-class citizen(aka type, object, entity or value)

一般来说，函数式编程语言、动态语言和现代的编程语言，函数都会作为一等公民，比如：Scala、Julia 等函数式语言，JavaScript、Python 等动态语言，Go、Rust、Swift 等现代的编译型语言。


### 语言分类

基本上来说，计算机语言被分成了两类：
1. Imperative languages
2. Declarative languages

- Declarative Programming Languages


重要的概念：`statement-at-a-time` 准则，所以说，每条语句都可以对内存有操作

更难以 debug



- Imperative languages

这个就是不改变内存

主要有两种命令式编程：
1. functional programming
2. logic programming

> ref: https://personal.utdallas.edu/~gupta/courses/apl/lec1.html

### 如何去设计鸭子类型

隐式：先定义类的主要部分，然后用模块添加额外功能。这种由 `Flavors` 引入，在上至 `Smalltalk`，下至 `Python` 的众多语言中采用的编程风格，就称作 `mixin`。在这些语言中，带 `mixin` 的载体虽未必称作模块，但基本前提是一致的: 使用单一继承结合 `mixin` 的方式，尽可能合理地把各种行为打包到一起。

### top-level functions

这个最初了解于 kotlin

用于解决在 java 中，为了使用单个函数而


### HDL

Hardware description languages

主要用于描绘复杂的数字逻辑，可以下载到 FPGA 中运行

主要代表语言是 Verilog
