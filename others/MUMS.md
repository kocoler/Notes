Muxi Unify Message System(MuxiUMS)
===

核心(core) 主要分为两个部分：
一个是服务系统内的与不同的 目标通知系统(钉钉、飞书、邮箱、或许还有木犀工作台消息系统hh 等等)交互的功能。
另一部分是模板，即用户自定义模板的功能

使用上主要也分为两个部分：
部署了 MUMS 的 Server 端
以及使用时的 Client 端，前期就暴露一个 API，后期可以封装成 Go/TS SDK

拓展：
```go
```

鉴权：
通过木犀 OAuth 流程，获取 AccessToken
请求需要加在 header 中的 Authorization: Bearer {AccessToken}

暴露接口
1. Send Message
2. Check message status
3. Add 

功能模块：
1. user
2. clients(register)
3. message template
4. message handle(send, records ...)
5. third-part-interface
