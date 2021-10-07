Git 版本控制
===



Windows Git:  Cygwin, msysGit (Git bash here)

- 初始化

  ```bash
  $ git init
  ```

  

- 配置

  ```bash
  $ git config [user.name|user.email] "" // 配置 Git 信息
  
  $ git config [user.name|user.email] "" // 配置 Git 信息
  ```

  

- 日常命令

  ```bash
  $ git show [commit_id] // 查看特定提交的详细信息

  $ git diff [commit_id1] [commit_id2] // 查看差异
  
  $ git show-branch --more=10 // 查看分支信息，额外10个版本
  
  $ git commit -m "" --author="xx <xxx@xxx.com>" // 提交commit信息及作者
  
  $ git status // status
  
  $ git rm [file] // 要先 备份 防止本地也被删
  
  
  ```

 

