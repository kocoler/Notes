### BASE

基本可用（Basically Available）

软状态（Soft state）

最终一致（Eventually consistent）

### ISR(In-Sync Replicas)

因为 paxos 和 raft 都需要 2f+1 个节点来保证 f 个节点的容错。
但是对于消息队列 kafuka 来说，这样有些浪费，isr 的机制可以 f+1 的容错。

将所有次级副本数据分到两个集合，其中一个被称为ISR集合，这个集合备份数据的特点是即时和主副本数据保持一致，而另外一个集合的备份数据**允许其消息队列落后于主副本的数据**。
在做主备切换时，只允许从ISR集合中选择主副本，只有ISR集合内所有备份都写成功才能认为这次写入操作成功。

ISR 集合为 f+1，可以容错 f 个节点。
