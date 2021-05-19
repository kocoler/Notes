### Resources

```shell
> kubectl api-resources # 查看所有api资源
```

### Feature stages

feature 有三种状态：

- Alpha: 默认不设置，可短期测试
- Beta: 默认设置
- GA: stable，不能关闭

### Obj Name & UID

每个 资源类型 唯一 name

k8s 自动生成 UID

### 监控

cAdVisor

k8s 通过 Metrics Server 将信息报露出来

返回信息是 kubelet 的 Summary API （即 <kubelet_ip>:<kubelet_port>/stats/summary）（是 cAdVisor info + kubelet info）

Metrics Server 是以 Aggregator 插件的形式对外服务（通过 kube-aggregator 代理）

>在具体的监控指标规划上，我建议你**遵循业界通用的 USE 原则和 RED 原则。**
>
>其中，USE 原则指的是，按照如下三个维度来规划资源监控指标：
>
>1. 利用率（Utilization），资源被有效利用起来提供服务的平均时间占比；
>
>2. 饱和度（Saturation），资源拥挤的程度，比如工作队列的长度；
>
>3. 错误率（Errors），错误的数量。
>
>而 RED 原则指的是，按照如下三个维度来规划服务监控指标：
>
>1. 每秒请求数量（Rate）；
>2. 每秒错误数量（Errors）；
>3. 服务响应时间（Duration）。

### API 健康端点

Kubernetes API 服务器提供 3 个 API 端点（非资源端点 nonResourceURLs: `healthz`、`livez` 和 `readyz`）来表明 API 服务器的当前状态。

healthz 已被弃用 k8s v1.16+

> kubectl get --raw='/readyz?verbose'

### 设计理念

<img src="others.assets/2018-11-25-kubernetes-design.png" alt="kubernetes-design" style="zoom:33%;" />

