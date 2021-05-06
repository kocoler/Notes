API
===

> original: https://kubernetes.io/docs/reference/generated/kubernetes-api/v1.21/



### objectmeta
> https://kubernetes.io/docs/reference/generated/kubernetes-api/v1.21/#objectmeta-v1-meta
>
> https://github.com/kubernetes/community/blob/master/contributors/devel/sig-architecture/api-conventions.md#metadata

元数据，所有 持久化的 资源都必须有的字段

- annotations *object*

  非结构化 k-v 非可查询参数

  修改资源时应保留

- clusterName *string*

  用来区分 不同集群上的相同命名空间

  以弃置(被 API 忽略)

- creationTimestamp *Time*

  在集群上创建的时间 不保证 happens-before 顺序

  Read-only

- deletionGracePeriodSeconds *integer*

  平滑删除时间 前提是设置 deletionTimestamp 只读

- deletionTimestamp *Time*

  删除时间

- finalizers *string array*

  删除前必须为空的字段 是所有管理此资源的登记

- generateName *string*

  只有 name 字段为空时起作用

  资源前缀

- labels *object*

  map[string]string

  作用于：replication controllers、services 的 match selectors 用于筛选 分类

-  managedFields *ManagedFieldsEntry array*

  > users typically shouldn't need to set or understand this field ...

- name *string*

- namespace *string*

- ownerReferences *OwnerReference]array*

- resourceVersion *string*

  不透明的，表明资源版本

- selfLink *string*

  指向自身的链接 已弃用

- uid *string*

  创建成功是设置

