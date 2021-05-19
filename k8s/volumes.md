Volumes
===

解决问题：

- 状态
- 同 pod 多 container 共享

分类：

- ephemeral 短期
- persistent 长期

### ConfigMap

先创建再使用

挂载到容器目标目录: mountPath/items.path

默认 UTF-8，其他格式需要 `binaryData`

无需修改每个pod的

明文存储

### downwardAPI

查看 downwardAPI 下面的 items 数组。 每个数组元素都是一个 DownwardAPIVolumeFile 对象。



> 如果容器以 subPath卷挂载方式来使用 Downward API，则该容器无法收到更新事件。

