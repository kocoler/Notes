#### process & thread

just think of task, not process and thread

> http://lkml.iu.edu/hypermail/linux/kernel/9608/0191.html

上面是 linus 的解释，或者说他的观点。

只是复制 COE (context of execution)，一切都只是 COE，process 可能属性更多一点，取决于 CLONE 的是什么(文中说最简单的 vfork() 就是 clone(CLONE_VM);)

线程，也就是 LWP (light weight process) 轻量级进程

那么从我们这个层面来看，fork() 创建了一个新的 process，拥有新的 pid，tgid，而 new thread(pthread_creat)拥有新的 pid，相同的 tgid。
对于这两个的定义，在 top 和 ps 中是不一样的：ps 中的 PID 也就是 TGID，而 top 中的 PID 就是 PID，task 的标示。
其实这个 top 就是内核视角，而 ps 是用户视角。

> https://stackoverflow.com/questions/9305992/if-threads-share-the-same-pid-how-can-they-be-identified

这是关于 pid 和 tgid 比较好的解释，也解释了 process 和 thread 的一些区别。

#### Barrier

> any thread/process `must stop` at this point and cannot proceed until `all other` threads/processes reach this barrier.

```c
#include <pthread.h>

int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex); // set block condition => wil block until condition is true, and would release mutex
int pthread_cond_timedwait(pthread_cond_t *cond, 
    pthread_mutex_t *mutex, const struct timespec *abstime);  // ditto, but with abstime


int pthread_cond_signal(pthread_cond_t *cond); // wake up one block thread
int pthread_cond_broadcast(pthread_cond_t *cond); // wake up all block threads
// both has nothing to do with mutex
```

