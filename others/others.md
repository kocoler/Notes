### 尾递归

``` go
func a() {
    return b()
}
```

直接返回第二个 function call，不做其他处理，参数可以处理

因为这样的话，上一个函数栈就无用了，可以直接覆盖，避免了栈溢出

es6、c有，go好像没有

### 柯里化（currying）

在只接受一个单一参数的lambda演算中，提供了带有多个参数的函数的方式

```go
func curring(funca func(), a int) {
    return func A(b int) {
        return funca(a, b)
    }
}
```


### Rack middleware

这玩意就是 Rack 实现的 pipeline


### Murmur hash

对于规律性较强的 key, murmurhash 的随机分布性特征表现更良好


### JIT

just-in-time (JIT) compilation (also dynamic translation or run-time compilations)

运行时编译吧，是动态编译的一种形式

他可以进行很多 运行时 的优化

最重要的是 他也是 编译

比如 Google 的 V8 引擎，完全都是 JIT 而不是解释


### DRC

动态重编译

也是为了更好的性能

Adaptive optimization(自适应优化) 也是通过运行时进行重编译实现的


### AOT compilation

ahead-of-time compilation 运行前编译，一般都是和 JIT 对着

优点就是可以生成更多更复杂的编译优化，但是有些运行时才能优化的东西就没法优化(感知)

比如根据配置文件优化

> https://en.wikipedia.org/wiki/Ahead-of-time_compilation


### OSR

On stack Replacement(OSR)

可以在同一个函数的不同实现中切换

比如可以从未优化过的代码切换到编译好(优化好)的代码，或者反过来


### Framework vs Library

Farmwork call you, you call library.



### Edge trigger vs Level trigger

边缘触发和水平触发

如果放到实际中考虑还是挺有区别的

水平触发会一直触发，边缘触发只会在边缘触发的时候触发

具体等我学学 epoll 吧 ...

也有的是类似边缘出发的水平触发，即只记录上一次低电平以来的一次，为了使 handler 只触发一次

> https://electronics.stackexchange.com/questions/21886/what-does-edge-triggered-and-level-triggered-mean

### Type–length–value (TLV)

https://en.wikipedia.org/wiki/Type%E2%80%93length%E2%80%93value

### Codec

codec 就是计算机中负责编解码数据流或者信号的设备

### Develop, Test, QA, Production Env



https://docs.oracle.com/cd/E19225-01/821-0763/ahxbb/index.html

https://oroinc.com/b2b-ecommerce/blog/testing-and-staging-environments-in-ecommerce-implementation/


