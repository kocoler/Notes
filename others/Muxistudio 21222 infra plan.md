目标：
1. 最近服务器网络不太稳定，经常有网络挂掉的情况，因为内部挂掉，不清楚是不是一个可用区挂掉还是云企业网挂掉。但是既然只有一个集群，我们要考虑做 master 节点跨可用区的高可用(即 multi-master/multi-control plane)。
2. 配置乱，很复杂，每个组件都有对应的配置文件
3. 构建 GitOps
4. 所有应用都使用 Helm Charts 方式管理，统一（这也是目前云原生的方向，也可以统一配置文件存放位置，方便迁移及备份，不存在配置文件丢失的情况）

步骤：
1. 合并集群
   monitor, single 两台机器 + 原集群一的一台机器 组建 admin cluster
   一台 原集群一机器 替代 原 CI(被封了qwq)机器
   两台 原集群一机器 合并至 集群二
   目前集群一服务，比较少：
   - 工作台(workbench-...)
   - 华师匣子(ccnubox-dataservice)
   - 木犀主页等(muxisite-fe, muxisite-auth)
2. 合并 monitor 机器到原生产1，三台机器，组建 admin 集群
3. 部署 prometheus-stack, Grafana, loki, ArgoCD, Vault ... 到新集群
4. 更改现有服务至 helm charts 格式，并且每个服务的配置文件都分离到另一个 config repo，用来做 CD 和统一管理
5. 使用 Vault 管理所有的 secret （注入到 pod env）
6. 使用 ArgoCD 管理所有 config-repo
7. 集成 ArgoCD 与 Grafana 图表

最终流程：
1. git push source repo
2. ci triggered
3. ci auto update config repo([git push](https://plugins.drone.io/plugins/git-push) stage on success)
4. cd triggered

or
1. push config repo
2. cd triggered

其他的回滚（自带）、监控、日志等操作都可以通过 ArgoCD 内嵌 external URL 实现

PS:
1. 所有场景都是多租户(multi tenant)场景
2. admin cluster 的搭建主要是为了契合 “全部使用 helm charts 格式，并用 ArgoCD 管理” 以及增加 prometheus 等性能（之前指标多的时候会挂）
3. prometheus 使用 [kube-prometheus-stack](https://github.com/prometheus-community/helm-charts/tree/main/charts/kube-prometheus-stack) 管理
   使用 [multiple-releases](https://github.com/prometheus-community/helm-charts/tree/main/charts/kube-prometheus-stack#multiple-releases) 限制某集群部署内容
   更改 [values.yaml](https://github.com/prometheus-community/helm-charts/blob/main/charts/kube-prometheus-stack/values.yaml) 其实和单机没区别
4. [WIP] Vault 可能较为复杂(鉴权及性能消耗)，计划先使用 config-map template 管理，达到配置(secret)分离的效果，再引入

目前最大问题：
1. 机器性能问题
   随着这些组件的完善及发展，1核 CPU 有点非常不够，2G 内存对性能影响也比较大
2. 机器来源问题
   阿里云暂时没有特价的服务器，服务器扩展是问题
   腾讯云服务器一直都不特价，但是轻量型会很便宜，而且性能很高，但是局限性是无法跨账号组云联网(相当于阿里云企业网)，这样就没有意义了，其他云(azure, amazon, google, vultr 等就更不是我们考虑的内容了)
   并且一旦考虑到高可用，那么就需要额外的服务器来支持，目前可以通过准许在 master 上运行小型的服务来减缓这个问题
3. 最好可以使用 minio 组建块存储，但是后期再说


multi-project -> multi-application
config-monorepo -> application-path -> values.prod.yaml/values.yaml

迁移流程：
1. 需要手动的：
   - gitea
   - 安装 ci
   - 备份 mongodb
   - 安装 k3s
   - 安装 argocd
2. 新的 argo
   （确实有 argocd manage argocd 的办法，但是我觉得这个方法更简单一点）
   - gitea clone `argocd/configs` 下来
   - apply 顺序: 
     - /chores/argocd/core/install.yaml
     - /chores/gitea
     - /chores/clusters
     - /chores/argocd/init.yaml
   - 结束
   需要注意的是，按照我们的模式， argocd-server 需要运行在 `--insecure` 模式下，以及其他一些镜像问题，我都在脚本里修改好了
3. 新的集群
   - 修改 argocd config repo，commit 新的 cluster 或者修改配置文件
   - admin cluster 上 pull 新的文件，apply /chores/clusters

问题解决方法：
1. 如何解决单应用多集群问题
   refs: 1, 7
   使用 cluster-generator 的 files 模式创建 ApplicationSet
   通过其中的 [label selector](https://github.com/argoproj/argo-cd/blob/master/docs/operator-manual/applicationset/Generators-Cluster.md#label-selector) 可以实现对集群的选择，例如 cluster-type: prod / cluster-name: prod-1
   通过其中的 [values](https://github.com/argoproj/argo-cd/blob/master/docs/operator-manual/applicationset/Generators-Cluster.md#pass-additional-key-value-pairs-via-values-field) 字段，可以实现不同集群应用不同配置文件，并且可以实现细粒度到应用中 单一/多个 服务的摘取
   ->
   后改为最外层目录 Helm Charts 模板来让 argocd 生成多 Applicaitons，避免了使用 ApplicationsSets 的复杂性
2. 如何使用 config 管理 config(s)
   refs: 6, 7
   使用 ApplicationSet 管理 ApplicationSet (directories)
   完成循环
   即，根目录中的 ApplicationSet.yaml 需要手动 apply
   他会发现所有的 application，并且创建，这个创建出来的也是一个 applicaitonset，是用来管理多集群的
   最后就是目标集群上的 application
   **更改同上**
3. 如何解决安装顺序问题
   refs: 2, 8， 9
   我们这里大多数情况就是：Certificate -> redis ... deploy/svc -> services deploy/svc -> ingress
4. helm template
   replace 就行
   如果有新的子服务，那么需要加，按照格式复制替换
   如果需要被外界访问，则完善 ingress
   更多可以参考 values.complex.yaml
   并且根据 argocd 使用 helm charts 的原理，并不需要考虑 charts 命名冲突问题
5. 更新了 config 如何更新 deployment
   因为 argocd 的原理是比较两个版本之间的 manifest，只对 manifest 发生改变了的
   流程是：先根据 argocd-server 
6. k8s resource api compatibility
   如第 5 点所说，生成 manifest 的过程是用 argocd 所在集群生成的（这也是为什么 argocd 一定需要部署在集群上，因为他需要一个 k8s context 来进行很多操作）。
   所以需要统一，对我们的环境来说，有比较大版本差异的就是 cert-manager、networking

Refs:
1. argocd manage multi environment: [
      https://codefresh.io/blog/pains-gitops-1-0/,
      https://github.com/argoproj/argocd-example-apps/issues/57,
   ]
2. helm v3 install order: https://github.com/helm/helm/blob/release-3.0/pkg/releaseutil/kind_sorter.go#L27
3. argocd backup and migrate: [
      https://argo-cd.readthedocs.io/en/stable/operator-manual/disaster_recovery/ ,
      https://github.com/argoproj/argo-cd/issues/993m,
   ]
4. argocd cluster bootstrapping: https://argo-cd.readthedocs.io/en/stable/operator-manual/cluster-bootstrapping/#cluster-bootstrapping
5. argocd manage cluster config without local-context(cli strong dependency): https://argo-cd.readthedocs.io/en/stable/operator-manual/declarative-setup/#clusters
6. argocd-git-generator-directories: https://github.com/argoproj/argo-cd/blob/master/docs/operator-manual/applicationset/Generators-Git.md#git-generator-directories
7. argocd-git-generator-files: https://github.com/argoproj/argo-cd/blob/master/docs/operator-manual/applicationset/Generators-Git.md#git-generator-files
8. argocd-resource-hook: https://argo-cd.readthedocs.io/en/stable/user-guide/resource_hooks/
9.  argocd sync-phases and waves: https://argo-cd.readthedocs.io/en/stable/user-guide/sync-waves/#sync-phases-and-waves
10. gitea push mirror to github(as a backup): https://docs.gitea.io/en-us/repo-mirror/#setting-up-a-push-mirror-from-gitea-to-github
11. argocd application specification: https://argo-cd.readthedocs.io/en/stable/operator-manual/application.yaml
12. argocd with ingress: https://argo-cd.readthedocs.io/en/stable/operator-manual/ingress/


--------


很容易发现，我们这里有过多的 regex-replace 操作
以及其他需要手操的问题，需要对这些比较熟悉才能完成
所以搞一下新的自动化小工具

**muxi-cli**

```
$ muxi-cli muxiyun generate --argocd --cluster-info /path/to/dir
or with alias
$ muxiyun generate --argocd --application ...
```

- package repo host
   maintain homebrew tap: https://docs.brew.sh/How-to-Create-and-Maintain-a-Tap
   maintain deb apt repo: https://earthly.dev/blog/creating-and-hosting-your-own-deb-packages-and-apt-repo/
   maintain yum repo: https://www.percona.com/blog/2020/01/02/how-to-create-your-own-repositories-for-packages/
   maintain chocolate repo: https://docs.chocolatey.org/en-us/features/host-packages

   or just go/npm/shell/...

- design
   主要是 go
   然后配置一下调用子目录下的脚本或者可执行文件之类的吧
   这样也可以后面统一账户管理呀啥的，还有多语言
   比如工作台 cli
   metadata 放 ~/.muxi/ 下

- 需求
工具上的：
  - multi service
  - auth

功能上的：
  - convert docker container from one registry to another registry
  - generate argocd config
  - open portals
  - sync config with config-center
  - 
  - ...
