Using the GNU Compiler Collection(GCC)
===

> GCC 这么牛的编译器，非常值得学习 —— 我
> 本文档为 GCC 学习计划
> https://gcc.gnu.org/onlinedocs/gcc/index.html
> 全部为原生 理解/翻译 哦~

#### 1 Programming Languages Supported by GCC

这一节就是说的 GCC 支持的语言，以及一些基础概念

GCC 是 "GNU Compiler Collection", 是 Collection 哦，所以不是专门给 C 用的
> 但是曾经是 "GNU C Compiler"

更多语言制定方面详见 3.2 (-x language overwrite x.language behavior)

- GCC 与 G++ 的区别

    G++ 约等于 gcc -xc++ -lstdc++ -shared-libgcc (也有可能并不是，但是他确实只是多链接了几个库，可以通过 -v 看看)
    他们的本质区别是连接的库不一样以及会有一些额外的 宏定义(Extra Macros)
    ref: https://stackoverflow.com/questions/172587/what-is-the-difference-between-g-and-gcc


#### 3.2 Options Controlling the Kind of Output

这一节主要讲的是输出控制(选项)

前文有一些比较重要的概念：

> Compilation can involve up to four stages: preprocessing, compilation proper, assembly and linking, always in that order. 

就是说一般有四个阶段嘛，预处理，正确的编译，汇编，链接

> GCC is capable of preprocessing and compiling several files either into several assembler input files, or into one assembler input file; then each assembler input file produces an object file, and linking combines all the object files (those newly compiled, and those specified as input) into an executable file.

说的是，GCC 可以帮你 预处理 和 编译 成若干(或者只有一个) 汇编输入文件，然后每个汇编输入文件生成一个对象文件(object file)，然后链接生成一个可执行文件

- 第一部分 他可以根据你输入的文件去判断要干什么
    file.c: C 语言源代码


#### 3.3 Compiling C++ Programs

这一节讲的是 如何编译 CPP 程序

这里我们知道 CPP 源代码一般是 ""


#### 4.15 Architecture

- Value to the macro
- 


#### 6.2 Locally Declared Labels

就是局部的标签，只在其 block scope 中有效(所以他只能在 block 的最开始生命)

```c
__label__ label1, label2;
```


#### 6.4 Nested Functions

在另外一个函数中定义的函数就是 嵌套函数(Nested function)

```c
foo (double a, double b) {
  double square (double z) { return z * z; }

  return square (a) + square (b);
}
```

和 Go 中的差不多，要注意的是这个应该是这个函数是存在与函数栈上的，所以函数退出会被清理

在这里面定义 extern 或者 static 是错的，这也很明显

在使用前定义
```c
auto int access(int *, int);
```


#### 6.20 Arrays of Variable Length

这个其实就是 动态声明一个数组
通常情况下我们都是定长数组嘛，需要动态的时候我们都是用 malloc 手动维护
但是 VLA(variable length arrays) 可以帮助你在栈上搞定这些东西
相当于 alloca (alloca 是在函数退出的时候释放, VLA 是作用域结束就释放了)

不过这些在栈上的东西都很容易爆内存哦~

alloca: https://man7.org/linux/man-pages/man3/alloca.3.html

#### 6.21 Macros with a Variable Number of Arguments

```c
#define debug(format, ...) fprintf (stderr, format, __VA_ARGS__)
```

```c
#define debug(format, ...) fprintf (stderr, format, ## __VA_ARGS__)
```

这个 `##` 可以帮你删掉前面多余的 `,`，如果你只传一个参数的话hhh


#### [18.7.4 Handling Leaf Function](https://gcc.gnu.org/onlinedocs/gccint/Leaf-Functions.html)

> on some machines

是某些机器，可以提升性能，在这些机器上会提供优化 leaf function 的方式(the target machine offers a way to optimize the treatment of leaf functions)

Leaf Function 都是不调用其他函数的函数(但是不调用其他函数不一定是 Leaf Function)

这里需要重排寄存器

然后这个还有一个优点就是可以不需要依赖本身的寄存器规则


