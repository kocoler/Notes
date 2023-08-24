
### TCC

Try、Confirm、Cancel
最早是由 Pat Helland 于 2007 年发表的一篇名为《Life beyond Distributed Transactions:an Apostate’s Opinion》的论文提出。

TCC分为3个阶段
Try 阶段：尝试执行，完成所有业务检查（一致性）， 预留必须业务资源（准隔离性）
Confirm 阶段：如果所有分支的 Try 都成功了，则走到 Confirm 阶段。 Confirm 真正执行业务，不作任何业务检查，只使用 Try 阶段预留的业务资源
Cancel 阶段：如果所有分支的 Try 有一个失败了，则走到 Cancel 阶段。 Cancel 释放 Try 阶段预留的业务资源。

按照TCC的协议，Confirm和Cancel是只返回成功，不会返回失败。

DTM: https://github.com/dtm-labs/dtm

