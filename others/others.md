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

```go
func curring(funca func(), a int) {
    return func A(b int) {
        return funca(a, b)
    }
}
```

