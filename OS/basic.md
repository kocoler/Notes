![图 3](https://s2.loli.net/2022/03/29/tSUyKA8iLFI1MPg.png)  


### 细胞自动机(Cellular automaton)

> 它是由无限个有规律、坚硬的方格组成，每格均处于一种有限状态。
> 整个格网可以是任何有限维的。同时也是离散的。
> 每格于t时的态由t-1时的一集有限格（这集叫那格的邻域）的态决定。
> 每一格的“邻居”都是已被固定的。（一格可以是自己的邻居。）每次演进时，每格均遵从同一规矩一齐演进。

- 平行计算（parallel computation）：每一个细胞个体都同时同步的改变
- 局部的（local）：细胞的状态变化只受周遭细胞的影响。
- 一致性的（homogeneous）：所有细胞均受同样的规则所支配

### 图灵完备性

> 在可计算性理论，如果一系列操作数据的规则（如指令集、编程语言、细胞自动机）可以用来模拟任何图灵机，那么它是图灵完备的。
> 这意味着这个系统也可以识别其他数据处理规则集，图灵完备性被用作表达这种数据处理规则集的一种属性。

### Monolithic kernel & Micro kernel

Unix, Linux: Monolithic kernel
MaxOS, Win: Micro kernel

前面就是整个 kernel 一起(single large process running entirely in a single address space)
后面的是分成若干块(the kernel is broken down into separate processes, known as server)

> https://stackoverflow.com/questions/4537850/what-is-difference-between-monolithic-and-micro-kernel
