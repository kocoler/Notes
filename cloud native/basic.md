
1. etcd
   服务发现，消息发布与订阅，负载均衡，分布式通知与协调，分布式锁

2. k8s
   源于 borg，容器集群管理系统，为容器化的应用提供部署运行、资源调度、服务发现和动态伸缩等一系列功能
   在集群管理方面，Kubernetes将集群中的机器划分为一个Master节点和一群工作节点Node。其中，在Master节点运行着集群管理相关的一组进程kube-apiserver、kube-controller-manager和kube-scheduler，这些进程实现了整个集群的资源管理、Pod调度、弹性伸缩、安全控制、系统监控和纠错等管理能力，并且都是全自动完成的。

   Kubernetes Master控制组件
   Kubernetes API Server、Kubernetes Scheduler、Kubernetes Controller、Replication Controller、Node Controller、Namespace Controller、Service Controller、EndPoints Controller、Service Account Controller、Persistent Volume Controller、Daemon Set Controller、Deployment Controller、Job Controller、Pod Autoscaler Controller

    The replica set are also known as next generation replication controller. The only difference between replica set and replication controller is the selector types.
    The replication controller supports equality based selectors whereas the replica set supports equality based as well as set based selectors.

    kube-proxy运行在所有节点上，它监听apiserver中service和endpoint的变化情况，创建路由规则以提供服务IP和负载均衡功能。简单理解此进程是Service的透明代理兼负载均衡器，其核心功能是将到某个Service的访问请求转发到后端的多个Pod实例上。

