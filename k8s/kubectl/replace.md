### 关于 kubectl 的 replace 执行过程

> 起因：
> 线上用 replace 更新 env 不成功(但是重新创建了pod)，然后没查到什么相关的信息。
> 当然知道用 `force` 啦 ... 但是他确实有重新创建 Pod，所以猜测本身 container 并没有重启，只是重新更新了 env 和 annotation。然后换了 Pod 记录。

TODO: 流程图

预备:
- 大家都有的 xxxOptions
- 各种命令行判断，预处理，主要就是处理 config 文件

如果是 force 的话，就是 forceReplace(), 反而会简单一点。
> 他的 --force 选项是会转换成 DeleteOpinion 相关属性的

不考虑 DryRun 因为 DryRun 不是只在这里的。

然后借助一下 `k8s.io/cli-runtime/pkg/resource` 这个包的函数，处理一下请求。

整个 kubectl 的 replace 大概结构是这样的:
```go
// 主体函数原型
func (o *ReplaceOptions) Run(f cmdutil.Factory) error {
    //
    ...

    // check force
    if o.DeleteOptions.ForceDeletion {
        return o.forceReplace()
    }
    ...

    // build resource
    r := o.Builder./* ... */.Do()
    ...

    // visit resource
    return r.Visit(
        // visitFunc
        func() {
            ...
            // 1.compare config 
            util.CreateOrUpdateAnnotation(/* ...*/);
            // 2.record action
            o.Recorder.Record(info.Object);
            // 3.Dry run
            o.PrintObj(info.Object)
            // 4. Serialize: resource -> object
            obj := resource./* ... */.Replace(/* ... */)
        }
    )
}
```

Step1: compare config

> util.CreateOrUpdateAnnotation --> util.CreateApplyAnnotation

file: github.com/kubernetes/kubectl/pkg/util/apply.go
```go

// CreateApplyAnnotation 就是检查一下新的变化，只把新的绑定回去
func CreateApplyAnnotation(obj runtime.Object, codec runtime.Encoder) error {
    // modified 是检查改变后的序列化 annotation
    modified, err := GetModifiedConfiguration(obj, false, codec)
    if err != nil {
        return err
    }

    // 再放回去~
    return setOriginalConfiguration(obj, modified)
}
```
