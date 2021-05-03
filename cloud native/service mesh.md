Service Mesh
===

> Service Mesh是微服务时代的TCP协议。

大家的文章大多会设计到 [Pattern: Servive Mesh](https://link.zhihu.com/?target=http%3A//philcalcado.com/2017/08/03/pattern_service_mesh.html) 在这里有介绍一个(微)服务的发展史：

最开始的网络(除了业务逻辑外，还夹杂着对网络传输问题的处理逻辑) -> TCP 出现，网络层剥离 -> (网络通信发展)微服务出现 -> 微服务框架产生 -> Service Mesh 出现(取消微服务框架限制) -> 以 Istio 为代表的第二代 service mesh 集中管控 service mesh

service mesh 个人认为是一种 管控(网络调用、限流、熔断和监控) 大规模(微)服务的网络代理->集中管理的设计

将 service mesh 一般以 sidecar 的形式部署，是作为微服务的中间层，最后是若干服务代理所组成的错综复杂的网格

Service Mesh 作为 sidecar 运行，对应用程序来说是透明，所有应用程序间的流量都会通过它，所以对应用程序流量的控制都可以在 serivce mesh 中实现。

简介就这么多。