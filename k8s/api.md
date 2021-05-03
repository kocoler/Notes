API
===

> original: https://kubernetes.io/docs/reference/generated/kubernetes-api/v1.21/



### [objectmeta](https://kubernetes.io/docs/reference/generated/kubernetes-api/v1.21/#objectmeta-v1-meta)

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

- 