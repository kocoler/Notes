MAE 设计文档
===

MAE(MUXI APP ENGINE) 主要分为两个部分：

- 基础业务
- 集群管理

> 对应 Github 上的 specs
> Github 上为英文版本

> 因为历史原因，项目基本结构并不是 DDD
> 但是大部分分包也是比较清晰的，虽然并不指望有人维护，这也是代码里要更多考虑 自恢复/差错容忍/其他外部运维因素 的原因
> 部分实现参考阿里成熟的开源项目 kubevela
> 项目代码清晰，符合普遍的社区标准
> 但是目前还未开源...
> 此介绍文档还在完善！！！！时间好紧

技术选用:
- Mysql 因为本项目大部分数据的数据模型都是关系模型，所以选用了较为熟悉的 RDB Mysql
- Redis 本项目需要最基本的 业务层缓存以及 轻量消息队列作为缓冲，所以选用了较为熟悉的 Redis
- Client-go 管理集群是本项目核心部分，目前团队基本所有服务都部署与 k3s 管理的集群上，所以选用 client-go 作为项目与集群的交互的 k8s SDK


### 基础业务

#### 用户系统

最基本的用户系统，以及鉴权
接入团队 OAuth2.0 接口，设计实现 **OAuth Interface**，符合规范，便于接入其他的 OAuth 认证平台
黑名单在服务启动时从 Mysql 数据库 **Fan-out** 到 Redis 缓存，便于后期使用
黑名单部分作为 协程(goroutinue) 加快项目启动速度
可以考虑讲 Redis 部分做成布隆过滤器，但是项目目前使用人数较少，未启用


#### 组织系统

用户可以成为相应组织的成员，组织是根据团队内的应用划分(application) 的
同时 application 也用于划分 k8s 集群上的 Namespace
用于隔离不同的 application 的资源
用于在不同操作时进行 RBAC 鉴权控制


#### **服务管理(部署)**

每一个服务都属于一个应用(因为基本都是微服务，以及一些单体小服务，都适用)

传统的部署方法：创建 NS(如果没有) -> 创建 Ingress(附带 SSL 相关资源) -> 创建 Deployment -> 创建 Service

这里将 Deployment 和 Service 聚合在一起，只给用户暴露一个 服务 的概念
还有一个 Ingress 路由的概念，其余逻辑内部实现

用户可以自定义模板(template)用于生成部署在服务器上的资源
有默认模板，适用于大部分业务

并且将通用配置的统一出来，填表部署

子模块：
- 部署记录，也根据路由和服务分为两个部分
特定的 ID 记录用于 **回滚** 特定版本(集群粒度的控制)，并且*实时*显示每个部署的服务在集群上的状态
> 简化为：部署中，已停止，部署成功，部署失败


#### 服务器、集群

- 服务器
    因为团队所需的服务器也不是很少，因此需要单一的服务器记录系统
    业务需要记录服务器的各种配置信息以及过期信息
    到期前若干天触发过期提示

    设计是：用户创建 RAM 用户(阿里云概念，可以是其他信息) -> RAM 自动导入服务器信息

    抽象 **ECS Interface** 用于从服务商导入服务器

- 集群

    目前采用的方式是使用集群内 ServiceAccount 的 Token + CA 证书，用于访问集群内的服务(一个集群一个)

    关于集群部分的权限控制需要在集群上改动其权限，从 MAE 中剥离开来，这也是初始化集群的时候应该做的


#### 流水线(CI pipeline)

关于团队自建的 Drone CI ，需要将 Build 部分接入到 基础业务 中
设计 **CI Interface**，用于兼容不同 CI 的 SDK
主要用于将服务的部署部分都集成到一起(用户通过 push gitea 的 tag 触发 drone ci 的 trigger，最后 MAE 一键部署)


#### 通知系统

    
具体的通知分发业务后迁移至 MUMS 项目
主要涉及 服务器到期，服务部署状态提示 等


#### 指标(metrics)

只做服务内各指标监控
暴露出用于监控该服务的内部信息，暴露到 Prometheus，然后接入 Grafana 监控整个服务情况
Tracing 部分正在完善中，可以更好的掌握服务性能等


### 集群管理(Cluster Management)

#### 概览

MKE(MUXI K8s Engine) 是独立于 MAE 存在的与 k8s api server 交互的，自己封装 libary(大概算是)

- **MKE with client-go**

    MKE 内嵌于 MAE 中的部分
    通过 k8s 官方的 SDK client-go 与目标 集群上的 api-server 交互
    这一部分主要这几了最基本的(也是业务需要的) 创建，更新，删除 等等功能

- **MKE CRD**

    因为单纯使用 clinet-go 与集群交互对于一些监控状态操作不是那么直接(如：Deployment 的具体状态，同时涉及 Deployment 与 ReplicaSet)
    并且在测试场景遇到了一些 BUG(已经忘了是什么了，好像是在 服务重启是会重复触发事件) 于是直接选择了最开始就想的集群 CRD 方案，让这一部分作为 CRD 运行在各个集群上去帮助我们得知 Deployemnt 的状态，反馈回来

    还有一个原因就是，我们的 MAE 与 集群 交互是走公网的，因为可能会与不同的集群不在同一个地域，所以也要尽可能的**减少与集群间的网络流量**，并且学生机性能并不好，尤其要**减少单个服务器的处理任务**（均摊）



#### 详细资源

接下来是根据 k8s 中我们需要用到的具体的资源

##### Namespace

Namespace 作为 K8s 中最直接的隔离资源的概念，非常适合对应到我们业务中的 Application

- 新的 Application

    先根据 Application 的 name(符合 RFC 规定的) 在**所有**的集群上创建 Namespace

- 新的 Cluster

    根据**所有**存在的 Application 在新的集群上创建 Namespace


这样就保证了所有的 Application 在不同集群上的迁移部署等等（因为这里的集群对所有的服务都是可用的，所以是所有的集群，如果涉及到其他粒度的控制问题，则需要再加详细的控制逻辑）


##### Ingress

Ingress 作为内部服务暴露到集群与外界交互的一部分，需要用户自定义每个 Route 的细节，并且可以引入 SSL

- 创建流程：

    新的 Ingress 资源 -> 在目标集群上 Apply -> 如果有错误，直接 Callback

- 如何收集目标集群

    因为这里的集群分为 Test 和 Product 两种，每次的部署需要同时考虑这两种
    对应关系为：
    ns -> services, ns -> ingresses, service -> clusters
    =>
    ingresses -> clusters

同时，所有的 Ingress 资源在集群中由 name(version) 来区分
Ingress 的 更新，创建，新版本发布，在不同的 版本之间是分开的，但是在不同的集群（生产/测试）上是可以不同的


#####  Service + Deployment => version

讲 K8s 中的 Service 和 Deployment 组合在一起，形成本项目中的 版本（version） 的概念，也就是向用户暴露的概念，用户的所有操作都是对 version 的操作，其中的信息也是直接编写对应 version 的 service template

- 状态

    分为两个部分：
    - 部署（deploying）到集群上的状态
    - 已经在集群上的状态
        Pending，Success 或者 Failed
        并且把这些日志集成到对应部署记录的日志中，通过特定的部署记录访问相关的部署日志

- 流程
  
    关系：一个版本对应多个资源对应多个集群
    one version -> multiple resources --> multiple clusters
    > on the cluster: new deployment -> replicaset(s) -> pod(s)

    new version -> apply on target clusters(service && deployment) ->

    - service

        因为 service 也是只涉及一个单独的创建资源过程，所以这里采用的方法是直接 callback 触发相关流程，也不需要重试等等

    - deployment

        pre-design:

            goto deploymentStatusWatcher -> replicasetsWacher -> podWacher -> callback

        now:
            对于创建资源状态阶段 是可以直接 callback 的
            对于在集群上的具体状态是要通过 deploymentWatcher 会报来的状态更新

具有默认模板给用户使用


### 一些讨论

#### Callback

很明显，各种因素（主要是响应时间），导致了这里的所有与 集群 的交互过程基本都是异步的，这里使用了 Callback 机制来完成所有的异步回调，更新状态机状态


#### 持久化

作为保障一致性最有效的手段就是持久化
每一部分关于资源的一些状态，都需要持久化，并且需要一些策略来保证每个事件对每个状态机的影响，同时需要保证每次交互的 幂等性


#### 为什么把 deployment-operater 剥离出来

上文讨论过具体的思考
同时也是为了方便后面更多的 CRD 资源出现


...
TO BE CONTINUE
