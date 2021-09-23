### Hop-by-hop headers 逐跳传输消息首部
只作用于一个链接。
不被代理或者缓存。

### Transfer-Encoding
指明了将 entity 安全传递给用户所采用的编码形式。
即仅应用于两个节点之间的消息传递，而不是所请求的资源本身。一个多节点连接中的每一段都可以应用不同的Transfer-Encoding 值。如果整个链接: Content-Encoding。
**chunked**
数据以一系列分块的形式进行发送。 Content-Length 首部在这种情况下不被发送。
在每一个分块的开头需要添加当前分块的长度，以十六进制的形式表示，后面紧跟着 '\r\n' ，之后是分块本身，后面也是'\r\n' 。
终止块是一个常规的分块，不同之处在于其长度为0。终止块后面是一个挂载（trailer），由一系列（或者为空）的实体消息首部构成。
其他的: `compress`, `deflate`, `gzip`, `identity`

### ETag
ETagHTTP响应头是资源的特定版本的标识符。这可以让缓存更高效，并节省带宽，因为如果内容没有改变，Web服务器不需要发送完整的响应。
而如果内容发生了变化，使用ETag有助于防止资源的同时更新相互覆盖（“空中碰撞”）。

### If-Match
请求首部 If-Match 的使用表示这是一个条件请求。在请求方法为 GET 和 HEAD 的情况下，服务器仅在请求的资源满足此首部列出的 ETag值时才会返回资源。而对于 PUT 或其他非安全方法来说，只有在满足条件的情况下才可以将资源上传。
ETag 之间的比较使用的是强比较算法，即只有在每一个字节都相同的情况下，才可以认为两个文件是相同的。在 ETag 前面添加    W/ 前缀表示可以采用相对宽松的算法。
如果  ETag 无法匹配，那么需要返回 **416** (Range Not Satisfiable，范围请求无法满足) 响应。


### Content-Type

Query string data vs x-www-form-urlencoded content

这个 query 是放在 URL 中的，后者是放在 body 中的

form-data vs x-www-form-urlencoded content

一般大一点的有效载荷数据是用 form-data 的，因为 encode 需要把非 ascii 的编码成 三个字符
这样就会多很多冗余数据

multipart/form-data 还有一个问题就是 分割 不能出现在文件中

application/xml

data-size: XML very verbose, but usually not an issue when using compression and thinking that the write access case (e.g. through POST or PUT) is much more rare as read-access (in many cases it is <3% of all traffic). Rarely there where cases where I had to optimize the write performance
existence of non-ascii chars: you can use utf-8 as encoding in XML
existence of binary data: would need to use base64 encoding
filename data: you can encapsulate this inside field in XML

application/json

data-size: more compact less that XML, still text, but you can compress
non-ascii chars: json is utf-8
binary data: base64 (also see json-binary-question)
filename data: encapsulate as own field-section inside json

> https://stackoverflow.com/questions/4007969/application-x-www-form-urlencoded-or-multipart-form-data
