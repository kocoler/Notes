#### Assign Extended Resources to a Container

如何给容器添加附加资源

```yaml

```

#### Advertise Extended Resources for a Node

如何控制 node 粒度的 pod 资源分配

比如最多允许一个 node 上有 x 个 pod

```curl
curl --header "Content-Type: application/json-patch+json" \
--request PATCH \
--data '[{"op": "add", "path": "/status/capacity/example.com~1dongle", "value": "4"}]' \
http://localhost:8001/api/v1/nodes/<your-node-name>/status
```
