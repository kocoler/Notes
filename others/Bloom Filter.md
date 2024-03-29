布隆过滤器(Bloom Filter)
===

判定 **`“可能已存在和绝对不存在”`** 两种情况

### 1. 优点

- 迅速判断一个元素是否在一个集合中

- 比哈希表更节省空间

  1亿数据量 -> 1G

- 查找/插入: O(n) -> n 为所有准备的哈希函数 ～ O(1)

- 不支持删值操作



### 2. 缺点

- **有一定的误识别率（false-positive，假阳性）**

  但是在生产环境中可以被接受



### 3. 实现

GO：

Create: new bitset -> hashFuncA(num) hashFuncB(num) ... -> setbit(hashedNumA) setbit(hashedNumB) setbit(hashedNumC) ... -> done!

Use: Has: bitset.Has(hashedNumA) && bitset.Has(hashedNumB) && ... = true -> else -> Doesn't has



### 4. 场景

- 黑名单
- 防止缓存击穿
- 查询加速
- 集合元素重复的判断
- 爬虫的URL过滤



ref: 

- https://www.jianshu.com/p/7ce887ab4089
- https://www.cnblogs.com/rinack/p/9712477.html
- https://www.cnblogs.com/Hollson/p/12031692.html