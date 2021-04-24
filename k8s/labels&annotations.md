Labels
===

- 用来用户层 根据标签筛选集合

  支持集合和单元素

  无法使用 ||

  但是可以使用`,`来取并集

- 可以作为控制器的选择器

  旧的资源类型(service, replicationcontroller)不支持 set

  新的资源类型(job, deployment, replicaset, deamonset)支持 set

  ```yaml
  selector:
    matchLabels:
      component: redis
    matchExpressions:
      - {key: tier, operator: In, values: [cache]}
      - {key: environment, operator: NotIn, values: [dev]}
  ```

- 可以作为node的选择标准

### 推荐使用的标签

带有 app.kubernetes.io 前缀的是共享的，不带的是用户私有的

app.kubernetes.io/[name | instance | version | component | part-of | managed-by]

> 但是这些标签都并不会被(硬性)使用



Annotations
===

用于客户端即k8s-client识别的

例子：

- 配置里写的
- 构建，发布，镜像信息
- 日志，监控点(这个我也很模糊)...
- 可用于调试的信息
- 生态组件...
- 负责人信息
- 可以开启非标准选项等用户参数

前缀是可选的。如果指定，则前缀必须是DNS子域。

`kubernetes.io/` and `k8s.io/` 为 k8s core 预留

