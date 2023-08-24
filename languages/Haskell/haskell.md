## What is Haskell?
Haskell is a lazy, functional programming language created in the late 1980s by a committee of academics.

### Functional

这里很神奇哦，给出了

> There is no precise, accepted meaning for the term “functional”. 

这样的说法。

> But when we say that Haskell is a functional language, we usually have in mind two things:

这就说明了，正常情况下，如果满足这样的条件，那么我们将可以说他是一门函数式语言。

1. Functions are first-class, that is, functions are values which can be used in exactly the same ways as any other sort of value.

函数是一等公民

2. The meaning of Haskell programs is centered around evaluating expressions rather than executing instructions.

更看重 evaluating 而不是 executing instructions

EVAL!

> Taken together, these result in an entirely different way of thinking about programming. Much of this course will be spent exploring this way of thinking.

### Pure
1. 不变
   这也是大部分函数式语言的特性吧

2. 表达式没有副作用(side effects)
   
3. 使用相同的参数调用相同的函数每次都会产生相同的输出

这些特性，感觉也是函数式编程的特点

### Abstraction

Eg:
parametric polymorphism, higher-order functions, and type classes 

这些也是帮助抽象的方法之一

### Grammar

:: is pronounced “has type”
= denotes definition
idiomatic Haskell uses camelCase for identifier names
/ performs floating-point division only
Note that function application has higher precedence than any infix operators!

> ... other basic things move to UPenn cis194 notes


The primary purpose of the . operator is not to avoid parentheses, but to chain functions. It lets you tie the output of whatever appears on the right to the input of whatever appears on the left. This usually also results in fewer parentheses, but works differently.
