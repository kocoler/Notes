
- Client
- Propose(*)
- Learner(*)
- Leader
- Acceptor(*)

propose 给 acceptor 发信号，带有一个数量
如果这个 request 是当前最大的，那么就接受，否则就拒绝，同时告诉当前最高的是啥

https://www.cs.yale.edu/homes/aspnes/pinewiki/Paxos.html
