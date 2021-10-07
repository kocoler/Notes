GOX
===

Go 打包工具

Github：https://github.com/mitchellh/gox

比较好的博客：https://blog.csdn.net/jinjianghai/article/details/85293380

```bash
$ go get github.com/mitchellh/gox

$ gox -h
```

```bash
$ gox # 全系统 很大 不建议直接全部生成

$ gox -os="linux" # 指定系统

$ gox -osarch="linux/amd64" # 指定系统+架构

$ gox -output "{{.Dir}}_{{.OS}}_{{.Arch}}/app" # 分别放在不同的文件夹
```

GOOS: darwin freebsd linux windows android dragonfly netbsd openbsd plan9 solaris

GOARCH: arm arm64 386 amd64 ppc64 ppc64le mips64 mips64le s390x

linux: chmod 777 xxx

