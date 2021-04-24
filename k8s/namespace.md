Namespace
===

作用：多个虚拟集群由同一个物理集群支持(backed by)

建议避开 `kube-` 开头的 namespace

k8s 建立初期有4个命名空间

- default: 如果一个 object 没有命名空间，则为 default
- kube-system 由 k8s 自己创建的
- kube-public 公共访问的空间，不作要求
- kube-node-lease 暂定

可通过 kubectl config set-context --current --namespace=xxx 设置当前上下文



### Namespace Design

```go
type Namespace struct {
  TypeMeta   `json:",inline"`
  ObjectMeta `json:"metadata,omitempty"`

  Spec NamespaceSpec `json:"spec,omitempty"`
  Status NamespaceStatus `json:"status,omitempty"`
}
```

在服务中注册的Kind: *RESTScopeNamespace*

namespace 只有两种状态：avtive、terminating

k8s 设置字段 `ObjectMeta.DeletionTimestamp` 来确定 namespace 是否被删除，同时设置 NamespaceStatus.Phase 字段，这个字段是个 string 类型

阻止新资源创建，设计称为 `admission control`，好处是无须考虑 namespace 的生命周期

所有对象删除后 namespace controller 通知 namespace 删除 Namespace.Spec.Finalizers 中的值("kubernetes")，猜测这是个队列，用来记录应该删除的资源 来确定是否删除结束(最开始 先删除 "kubernetes" 这一value)

> finalizers model:
>
> ```go
> type FinalizerName string
> 
> // These are internal finalizers to Kubernetes, must be qualified name unless defined here
> const (
>   FinalizerKubernetes FinalizerName = "kubernetes"
> )
> 
> // NamespaceSpec describes the attributes on a Namespace
> type NamespaceSpec struct {
>   // Finalizers is an opaque list of values that must be empty to permanently remove object from storage
>   Finalizers []FinalizerName
> }
> 
> ```


如果namespace 的 DeletionTimestamp 字段已设置，并且 finalizers 字段为空，则永久删除(通过 DELETE API 设计的action 叫 finalize)

以上大部分是 namespace controller 做的事情，这玩意会做一个同步循环(sync loop)

#### In storage

在 etcd(或者其他的存储方式也是一样的) 中

> /{k8s_storage_prefix}/{resourceType}/{resource.Namespace}/{resource.Name}

这样设计的目的是便于跨命名空间监听( /registry/{resourceType} )

#### In kubelet

注册方式：namespace + cluster-id

