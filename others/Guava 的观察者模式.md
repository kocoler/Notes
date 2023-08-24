## Guava 的观察者模式

> 关于 Guava 的 EventBus 部分主要在：com.google.common.eventbus 中

### 简单介绍

**观察者模式：**
允许定义一种**订阅机制**，可在对象事件发生时**通知**多个 "观察" 该对象的其他对象。

**两个角色：**
Publisher 和 Listener/Subscribers

**接受事件：**
接受时间的对象应该暴露一个 public 的方法，用 @Subscribe 注解标注，该方法可以接受一个参数，该参数就是 Event 的类型。
当他注册到 EventBus 之后，就可以开始接受事件了。

**发送事件：**
实现 Post(object) 方法，EventBus 会自动将这个时间路由到注册的 Listeners 中。
订阅者将顺序收到这条事件，如果这个需要异步处理，可以使用 AsyncEventBus。

**休眠事件：**
如果一个事件没有订阅者，那么会被认为是 "dead"，这个事件会被封装到一个 DeadEvent 实例中，然后再重新发送回来。


### 抽象：

下图是应用 EventBus 的大致 UML 图
我们可以看到 eventbus 具有 post 方法，负责发送 eventObject 具体事件
然后这个 EventBus 中具有 register 和 unregister 方法，负责注册和取消注册这个 Event Listener
然后 Guava 根据具体放进来的 eventObject 去调用通知 Listener 的 handler


![图 9](https://s2.loli.net/2021/12/19/IwyRKZqsp3V4JBi.png)  


分发的流程：

已经注册了的事件经过 EventBus 分发到监听了对应对象的订阅者哪里（Super Object）
![图 5](https://s2.loli.net/2021/12/19/gsZT9j5tqP3V7MF.png)  



### 更具体一点：

> 以 [huaweicloud/spring-cloud-huawei](https://github.com/huaweicloud/spring-cloud-huawei/) 中的服务治理配置更新的观察者模式为例

这里摘抄了一些代码片段，只抽出与观察者模式相关的代码设计实现

#### EventManager
他先是把 EventBus 封装成自己的 EventBus
也就是 `com.google.common.eventbus.EventBus` to `com.huaweicloud.common.event`，前者就是 `Guava` 的 EventBus
订阅者和发送者都只和这个 EventManager 交互，两者直接并不会有直接的耦合关系

```java
package com.huaweicloud.common.event;

import com.google.common.eventbus.EventBus;

public class EventManager {
  private static EventBus eventBus = new EventBus();

  public static EventBus getEventBus() {
    return eventBus;
  }

  // Post 方法，发送事件，这里用的是 Object，所有的事件的超类
  public static void post(Object event) {
    eventBus.post(event);
  }

 // Register 方法，将订阅者注册到 EventBus 中
  public static void register(Object subscriber) {
    eventBus.register(subscriber);
  }
}
```

#### GovernanceProperties(服务治理属性类)

这个类(的实例)就相当于一个订阅者，他将收到所有 `ConfigRefreshEvent` 相关事件的通知

```java
......

public abstract class GovernanceProperties<T extends Configurable> implements InitializingBean {
  ......

  // 我们来看这个服务治理的属性类，它是一个抽象类
  // 这里的 EventManager.register(this); 将这个类(现实中就是他的某一个实例)注册到了 EventBus 中
  protected GovernanceProperties(String key) {
    configKey = key;
    representer.getPropertyUtils().setSkipMissingProperties(true);
    EventManager.register(this);
    entityClass = getEntityClass();
  }

  ......

  // 上文提到过的 Subscribe 注解
  // 这说明了，这个 GovernanceProperties 的具体实现类将会接受到 EventBus 中的事件
  // 这个事件的类型是 ConfigurationChangedEvent
  @Subscribe
  public void onConfigurationChangedEvent(ConfigurationChangedEvent event) {
    // 接收到事件变化后的处理细节
    for (String key : event.getChangedConfigurations()) {
      if (key.startsWith(configKey + ".")) {
        String mapKey = key.substring((configKey + ".").length());
        parsedEntity.remove(mapKey);
        T entityItem = parseEntityItem(mapKey, environment.getProperty(key));
        if (entityItem != null) {
          parsedEntity.put(mapKey, entityItem);
        }
      }
    }
  }
  ......
}
```

```java
......

// 这个就是其中 ConfigRefreshEvent 事件的定义
public class ConfigRefreshEvent extends ApplicationEvent {
  private Set<String> change;

  // 这段注解也说明了这个是在这个发生时将要被调用的
  // this.change = change; 保存了这次事件的内容
  /**
   * Create a new ApplicationEvent.
   * @param source the object on which the event initially occurred (never {@code null})
   */
  public ConfigRefreshEvent(Object source, Set<String> change) {
    super(source);
    this.change = change;
  }

  // 这里的 getChange 就将返回事件中 change 的内容
  public Set<String> getChange() {
    return change;
  }

  public void setChange(Set<String> change) {
    this.change = change;
  }
}

......
```

#### GovernanceConfiguration(服务治理配置)

这里是一个发布者的角色，他只需要将配置变更的通知发布出去，再由订阅者们去进行具体的处理

```java
......

@Bean
  public ApplicationListener<ConfigRefreshEvent> governanceApplicationListener() {
    // 这里调用了 EventManager 的 post 方法，发送了 configRefreshEvent，也就是配置刷新事件
    return configRefreshEvent -> EventManager
        .post(new ConfigurationChangedEvent(new HashSet<>(configRefreshEvent.getChange())));
  }

......
```


#### UML 图


![图 8](https://s2.loli.net/2021/12/19/27jvRACs9bOiNyc.png)  


只要发布者通过同样的接口(EventBus)与所有订阅者进行交互， 那么在程序中新增订阅者时就无需修改已有发布者类的代码。

可以看出订阅者和发布者是解藕了的


### 为什么要用 EventBus（订阅者模式）？

开闭原则：你无需修改发布者代码就能引入新的订阅者类，反之亦然。

可以将 事先未知的或动态变化的 实际对象通知给其他对象。并且可以解耦合开那些相互协作的类之间的“协作”关系比较复杂的类。

