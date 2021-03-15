Redis
===

### 基本数据类型

1. string

   Redis 的字符串是动态字符串，是可以修改的字符串，内部结构实现上类似于 Java 的 ArrayList，采用预分配冗余空间的方式来减少内存的频繁分配，如图中所示，内部为当前字 符串实际分配的空间 capacity 一般要高于实际字符串长度 len。当字符串长度小于 1M 时， 扩容都是加倍现有的空间，如果超过 1M，扩容时一次只会多扩 1M 的空间。需要注意的是 **字符串最大长度为 512M**。

2. list

   链表实现，无元素之后自动删除，内存被回收。时间复杂度与链表一致

   `rpush` `lpop` `rpop` `lpush`

   `lrange` `lindex` `llen`

   **ziplist** **quicklist**

3. set

   内部键值对是 **无序的** **唯一的** -> 自动去重

   `sadd` `smembers` `sismember` 

   `scard` `spop`

4. hash

   数组+链表

   value 只能是字符串

   渐进式rehash -> 并不一次迁移，保留新旧两个hash结构，查询同时查询两个hash结构，后续逐渐迁移

   `hset` `hgetall` `hlen` `hmest`

   `hincrby`

5. zset

   保证内部value的唯一性(set)

   为每个value赋予一个score -> 排序权重

   `zadd` `zrange` `zrevrange` `zcard` `zscore` `zrank`

   `zrangebysco` `zrem`

   **跳跃列表**



### 容器型数据结构的通用规则

- 容器型数据结构

  list / set / hash / zset

1. create if not exists
2. drop if no elements 
3. expire 时间作用整个对象
4. expire 会覆盖 (**set 会取消**)

