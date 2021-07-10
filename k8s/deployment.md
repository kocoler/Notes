deployment
===

deployment 是一种 **controller**，用来控制 pod、replicaset(之前是 replicationcontroller 后被建议用 deployment.spec.replicas 替代，但其仍然存在)

### 使用场景：

- 创建 Deployment 以将 ReplicaSet 上线， ReplicaSet 在后台创建 Pods。 检查 ReplicaSet 的上线状态，查看其是否成功。

  deployment -> replicaset -> pod

  暴露出来的是一个由 replica 创建的 pod

- 通过更新 Deployment 的 PodTemplateSpec，声明 Pod 的新状态。 

  更新 所有 replicaset -> 更新所有的 pod

- 如果 Deployment 的当前状态不稳定，回滚到较早的 Deployment 版本。 每次回滚都会更新 Deployment 的修订版本。

  回滚

- 扩大 Deployment 规模以承担更多负载。

  扩容

- 暂停 Deployment 以应用对 PodTemplateSpec 所作的多项修改， 然后恢复其执行以启动新的上线版本。

  更新版本

- 使用 Deployment 状态 来判定上线过程是否出现停滞。

  状态判断

- 清理较旧的不再需要的 ReplicaSet。

  缩容

### CONFIG

```yaml
apiVersion: apps/v1
kind: Deployment  # API 对象
metadata:
  name: nginx-deployment  # deployment name
  labels:
    app: nginx  # -l app=nginx 和选择器一起使用才有用
spec:  # 说明
  replicas: 3
  selector:  # 选择器
    matchLabels: # 标签选择器
      app: nginx # 选择标签
  template:  # 资源模板
    metadata:  # 元数据
      labels:  # 标签
        app: nginx
    spec:
      containers:  # 容器
      - name: nginx
        image: nginx:1.14.2
        ports:
        - containerPort: 80  # 容器的端口
```


启动顺序：
![图 1](https://i.loli.net/2021/06/30/ilWNPnd3GbvB98t.png)  



