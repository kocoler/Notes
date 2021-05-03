Pod
===

> *Pod* 是可以在 Kubernetes 中创建和管理的、最小的可部署的计算单元。
>
> 相对临时，用后就销毁的实体

一个 Pod 中的所有资源都是一起的，也共享 context

两种应用方式：

- 单容器单pod
- 多容器

一般是通过 负载资源(workload resources) 来管理: deployment, statefulset, deamonset。叫 Pod template，在 spec.template 中

但独操控 pod 有限制: https://kubernetes.io/docs/concepts/workloads/pods/#pod-update-and-replacement

每个pod在每个地址族都有个唯一地址

TODO: 容器的特权模式

### Static Pod

静态 Pod，直接由 kubelet 管理，kubelet 自动创建镜像 Pod，所以无法通过API server 管理，但是可见

### Init Containers

为 app containers 准备一定的环境，也可用于推迟容器部署

- 总是运行至 completion，无`lifecycle`、`livenessProbe`、`readinessProbe` 和 `startupProbe`

- 每个 init container 都必须成功，才可进行下一个

  如果失败，k8s 会不断重启直至成功(在restartPolicy != never的情况下)，否则整个pod失败

  Pod 重启，重新 init

出现形式:  pod: spec: initContainers[...]

将不必要的容器隔离开(limit the attack surface) -> Init 容器可以安全地运行工具，避免这些工具导致应用镜像的安全性降低。

具有和普通 containers 不同的 view of the filesystem -> 可以访问 secrets

只能修改 image 字段，后重启

### 如何安全删除一个节点

`k8s version > 1.5`

##### 同时确保服务高可用

搭配 PodDisruptionBudgt

