### 100 Continue
表示目前为止一切正常, 客户端应该继续请求, 如果已完成请求则忽略.

1xx状态码是 **HTTP/1.1** 版本新定义的，用来表示请求被正常接受，会进行进一步处理。

> HTTP/0.9 版本的响应报文只包含实体部分，没有状态码或原因短语的存在

为了让服务器**检查请求的首部**, 客户端必须在发送请求实体前, 在初始化请求中发送 `Expect: 100-continue` 首部并接收 100 Continue 响应状态码.

### 101 Switching Protocol
表示服务器已收到客户端的请求, 并将切换到使用另一个协议。

情景:
- HTTP/HTTPS -> WebSocket
- HTTP 1.1 -> HTTP 2.0

HTTP 2.0 禁用了这个

需要头部 `Upgrade: protocol_name[/protocol_version]` 和 `Connection: upgrade`

### 201 Created
表示请求已经被成功处理，并且创建了新的资源。新的资源在应答返回之前已经被创建。同时新增的资源会在应答消息体中返回，其地址或者是原始请求的路径，或者是 Location 首部的值。

### 202 Accepted
表示服务器端已经收到请求消息，但是尚未进行处理。
对于请求的处理确实无保证的，即稍后无法通过 HTTP 协议给客户端发送一个异步请求来告知其请求的处理结果。
这个状态码被设计用来将请求交由另外一个进程或者服务器来进行处理，或者是对请求进行批处理的情形。

### 204 No Content
表示该请求已经成功了，但是客户端客户不需要离开当前页面。默认情况下 204 响应是可缓存的。
使用惯例是，在 PUT 请求中进行资源更新，但是不需要改变当前展示给用户的页面。

### 205 Reset Content
通知客户端重置文档视图，比如清空表单内容、重置 canvas 状态或者刷新用户界面。


### 301 Moved Permanently / 302 Found / 307 Temporary Redirect
- 301-表示资源（页面）已**永久移动到新位置**。 客户端/浏览器不应尝试请求原始位置，而是从现在开始使用新位置。

- 302-表示资源**暂时位于其他地方**，客户端/浏览器应**继续请求原始URL**。资源被移动到了`Location` 中指定的位置。

301 => 浏览器缓存， 302 => 不会缓存

仅在相应`GET`, `HEAD`时，用302，其他情况下用 307

307 状态码可以确保请求方法和消息主体不会发生变化。 => 在 Web 中，如果使用了 GET 以外的请求方法，且返回了 302 状态码，则重定向后的请求方法是不可预测的

### 303 See Other
通常作为 PUT 或 POST 操作的返回结果，它表示重定向链接指向的不是新上传的资源，而是另外一个页面，比如消息确认页面或上传进度页面。

### 304 Not Modified

### 501 Not Implemented
请求的方法不被服务器支持，因此无法被处理。服务器必须支持的方法只有 GET 和 HEAD。
可缓存。

### 504 Gateway Timeout
表示扮演网关或者代理的服务器无法在规定的时间内**获得想要的响应**。

