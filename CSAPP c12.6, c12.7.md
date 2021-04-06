CSAPP c12.6, c12.7
===

> 这个我上礼拜日看的...
>
> 现在都有点不记得了...
>
> 老实说 这个玩意挺少的

### 12.6

这一节讲的就是并行（进程/线程/协程 都叫并行）

并行嘛，肯定有竞争，这是个人都知道，然而不同的处理方法有不同的效率

主要展示的是各种不同的 操作/处理/设计 会对最后的效率产生比较大的影响

**同步开销巨大，要尽可能避免。如果无可避免，必须要用尽可能多的有用计算来弥补这个开销**

这就是说 mutex 这个玩意大家不要轻易用，如果用了，那么就要在单个锁持有的时间内尽可能多的做非常重要的处理

看一下实际运行吧～

~~有很多概念性的就不在这里提了，比如软拓展硬拓展，因为就算提了也会忘，而且感觉没啥太大用处~~

- 这能带给我们什么思考？

  并发操作避免会在一个协程中用到同一个变量

  不要滥用锁

  不要通过共享内存的方式进行通信，而是应该通过通信的方式共享内存 ->

  在 go 中 尽可能的用 channel 通信，而不是用信号量

  尽量不要秀操作，90%都会有问题

  如果有，请控制并发量

  ~~团队来说的话，1个就够了~~

  ```go
  var res []int
  res = make([]int, len(list)+1)
  
  var wg sync.WaitGroup
  for index, item := range list {
    // some preparation ...
    
    // add wait group
    wg.Add(1)
    // start goroutinue
    go func(index int, item Item){
      // done goroutinue
      defer wg.Done()
      // add to result
      res[index] = afterHandle(item)
    }(index, item)
    
    // other actions
  }
  
  wg.Wait()
  
  // continue
  ```

  

### 12.7

#### 线程安全

线程不安全函数

其实线程不安全都是源自于竞争

竞争同一块 资源

所以其实书上的四类都是这个意思

- 不保护共享变量的函数

  这个很好理解，就是同时修改一个变量

- 保持跨越多个调用的状态的函数

  书上举的例子是 rand

  啥意思呢，就是rand的结果依赖于前一个状态 seed 可是这个状态很有可能被另外一个线程调用的时候覆盖/修改掉

  这样就不安全了

  和第三类差不多

- 返回指向静态变量的指针的函数

  两个同时调用

  另一个调用时，会覆盖第一个

- 调用线程不安全函数的函数

还有一点和死锁有关的，这个就比较基本了，大家都很熟了



### 对前一段时间的一点小解释

> 这一部分也大部分都不是给 20 讲的

#### Print Buffer

首先是之前的 `printf buffer` 的问题

这确实是 `printf buffer` 的问题

> http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf
>
> https://www.gnu.org/software/libc/manual/html_node/Buffering-Concepts.html

**全缓存、行缓存和无缓存**

磁盘上的文件 用标准I/O打开 默认是全缓存的，当缓存区填满或者进行flush操作时候才会进行磁盘操作。

标准输入和标准输出都是行缓存。

标准错误是无缓存

- 解决

  这里介绍一个函数 setbuf

  摘录了 POSIX 的说明

  ~~这个确实高级，但是我也确实弟弟~~

  <img src="CSAPP%20c12.6,%20c12.7.assets/image-20210326093421724.png" alt="image-20210326093421724" style="zoom: 43%;" />

  这里面又有一个 `setvbuf`

  <img src="CSAPP%20c12.6,%20c12.7.assets/image-20210326093727820.png" alt="image-20210326093727820" style="zoom:50%;" />

  ```c
  setbuf(stdout, NULL);
  setvbuf(stdout, NULL, _IONBF, 0);
  ```



#### channel 到底有没有 lock

> 应该是有的，但是仅限于某些地方，这个下面再说
>
> 但是其实我这两天玩多了，没研究完这部分的

go 在14年提出了一个无锁的 channel 实现方案，当然这个提案的目的也不是实现完全无锁的队列，只是在一些关键路径上通过无锁提升 Channel 的性能。

> 更多参考：
>
> https://github.com/golang/go/issues/8899
>
> https://docs.google.com/document/d/1yIAYmbvL3JxOKOjuCyon7JhW4cSv1wy5hC0ApeGMV9s/pub
>
> https://blogtitle.github.io/go-advanced-concurrency-patterns-part-2-timers/



#### scp sftp

> 这个是给 20 级讲的
>
> 但是大部分人估计也不会用到吧

> https://www.openssh.com/txt/release-8.0

<img src="CSAPP%20c12.6,%20c12.7.assets/image-20210327143812092.png" alt="image-20210327143812092" style="zoom:50%;" />

2019年的时候我尬吹 scp 不被推荐用了

但是 scp 速度还是最快的！sftp 功能挺多的，嗯

大家可以研究一下 rsync 这个参数还是比较多的，外面一般来做备份，全量和增量

这玩意也不一定只有一个GUI，所以怎么用都行

