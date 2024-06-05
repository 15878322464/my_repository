<div align="center">
<b> Git Command </b>
</div>

## 目录

* [命令大全](#mldq)
* [常用流程](#cylc)
<a id="mldq"></a>

## 命令大全
### 用户名与邮箱
```cpp
// 1.配置。用户名与邮箱如果不配置，那将无法提交到本地仓库，因为无法记录是谁提交的。
// 当你想所有项目提交记录都是一个用户名，则使用global全局的配置，当需要一个git项目一个用户名时，使用local配置。
git config --global user.name "UserName" 
git config --global user.email "UserEmail"
git config --local user.email "UserName"
git config --local user.email "UserEmail"

// 2.查询
git config --global user.name
git config --global user.email
```
### 记住账号密码
```cpp
git config --global credential.helper store // 配置 Git 使用 "store" 凭据帮助器,开启后git将会在你的用户主目录的.gitconfig文件中添加对应的新配置项，并生成.git-credentials文件来保存账号密码，不再需要每次都输入用户名和密码
git config --global --unset credential.helper // 取消使用凭据帮助器

// 当然，我们也可以只记住单个项目的账号密码
git config --local credential.helper store
```
### 最频繁使用的基础操作
```cpp
git init // 初始化git仓库，此时将会在当下文件夹里创建.git文件夹，如果已经有.git则git init会失败
git add . // 将所有未加入缓存区的更改加入缓存区，也可以指定单个文件
git commit -m "本次提交注释" // 将缓存区的东西提交到本地仓库
git status // 查看缓存区状态，还没有加入缓存区的有更改的文件为红色，在缓存区里但是没有提交的为绿色，没有要缓存的和要提交的则什么都没有,"Untracked files:" 部分列出了未被 Git 跟踪的新文件。
```
### 撤销
```cpp
git reset . // 它与git add是相对的，执行reset会撤回add操作 ，当然，如果是已经commit了的就无法撤回了
git reset HEAD^ // 撤回最近的一次commit操作，其使退回到缓存区(此时更改还存在，还可以重新commit)
git reset --hard HEAD^ // 撤销最近一次commit和add,并且删除所有更改,无法再commit,请谨慎使用
git reset commitID // 回到对应的commitID（commitID详见日志篇）状态，会将更改保留在工作区，可以供你重新add,也可以加--soft让它放入到缓存区，同样的--hard参数也适用，会删除所有更改
```
### 日志
```cpp
git log  // 简单列出所有commit相关信息记录，以倒序输出，先输出最近的记录，最后输出第一次记录，所以该命令更多的是查看前期的commitID
git log -数字 // 显示最近几次的commit记录，数字为1，就显示最近的，也就是倒数第一的记录，为二就显示倒数第一倒数第二两个的记录，该命令更多是查看后期的commitID
git log --graph // 以图形的形式展现提交记录以及分支合并情况，与git log的输出顺序一致
git log --stat // 详细显示提交记录，包括每次提交修改的文件以及对应行数显示，这时候一般终端会显示不完，我们按回车键就能一直往下看，按下q键退出
git log --author=作者名 // 按照作者名搜索，列出该作者(提交者)的所有commit记录，该项是模糊搜索，不是精准搜索，所以为了避免出现过多的干扰项，建议把名字打全
git log --grep=模式名 // 按照模式(就是commit的时候的注释类型，比如功能feat、文档docs等)搜索
git log --since="2023-01-01" --until="2023-12-31":显示从2023-1-1到2023-12-31的提交记录
git log -p:查看每次提交之间的详细差异信息
git log file // 只显示包含指定文件的记录
git log commitID // 从该commitID开始显示
```

### 远程仓库与本地仓库
```cpp
// 1.克隆远程仓库到本地
git clone http // http自己去代码托管平台，例如github上拷贝，使用克隆则会自动关联本地与远程
// 2.本地关联远程仓库(还没添加有远程仓库的情况下)
git remote add origin http/ssh 
// 3.修改远程仓库的连接(已添加有远程仓库地址的情况下)
git remote set-url origin http/ssh
// 4.查询已关联的远程仓库地址
git remote -v
// 5.拉取远程仓库分支代码，合并到本地分支，注意，能pull的前提是本地分支与远程分支建立了关联，就算建立了关联，如果是两个从没有任何共同提交历史的分支，那也会被拒绝，除非加上--allow-unrelated-histories参数，来允许不同历史记录的分支合并。
git pull oringin main:main // origin是要推送到的远程仓库的别名，如果没有改过的话，默认全都是origin，前一个main是本地要推送到的分支，第二个是远程仓库分支名，当名称相同时可只写一个main，省略冒号
// 6.推送本地仓库的修改到远程仓库,此时需要验证账号密码，无论库是否公开，还需要注意的是git push的时候远程仓库分支所有的东西对应的本地仓库分支一定都要有，否则它会判定本地分支落后于远程分支，这时我们需要git pull一下。
git push origin main:main // 与git pull不同的是前一个main是本地分支，后一个main是远程分支

```

### 分支
```cpp
// 当在空文件夹里git init 之后还不能创建分支，会提示没有"master主分支"，这是因为你还没有创建东西，还没有add和commit,connit后会自动一个本地仓库的master主分支
// 不同的分支名才能合并，相同分支名的本地分支和远程分支只能说是git push,不要搞混
// 增
git branch 新分支名 // 创建新分支，但是不会切换到创建的新分支
git switch -c 新分支名 // switch相关命令是git2.23及以上版本才有，为了解决git 
git checkout -b 新分支名 // 创建分支，并且切换到该新建分支（2.23及以上版本更建议用switch，checkout主要是用来恢复文件的，使用时可能会存在分支名与文件名重复，想切换分支确变成了恢复该文件上一次提交的状态，造成不可逆的后果，2.23已经用switch代替）
// 删
git branch -d 分支名 // 对该分支做各种检查，符合条件就给删除，也可以直接-D强制删除不做任何检查
// 查
git branch // 查询本地仓库的所有分支
git branch -r // 查询远程仓库的所有分支
git branch -a // 查询所有分支

// 改 
git branch -m 新的名称 //分支重命名，如果新名称分支已存在则会造成冲突，我们也可以用-M去强制覆盖冲突的旧分支，但太危险，不建议
git switch 分支名 // 切换分支
git checkout 分支名 // 同样的，2.23及以上版本更建议使用switch
// 合并分支
git merge 主分支名 // 合并当前分支到主分支，记得查看当前分支是否正确

// 本地仓库分支与远程仓库分支
// 关联分支，或者说是设置上游分支，前提是已经与远程仓库关联
git branch -u origin/远程分支名 本地分支名 // 选定远程分支做上游，-u也可以用--set-upstream-to替代
git branch -vv // 查询本地分支，并罗列出已关联的远程分支
```
### 标签
```cpp
// 标签一般是三位数：0.0.0
// 第一个数字为主版本号：主要的功能变化或重大更新，对之前的版本某些现有功能有较大影响
// 第二个数字为次版本号：一些新的功能、改进、更新，通常不会影响现有功能
// 第三个数字为修订版本：一些小的bug修复，补丁，通常不会添加新接口、新功能

// 增
git tag -a "v0.0.0" -m "版本说明" commitID// 没有指定commitID则默认是最近的一个提交，一个commit可以设置多个tag,但是不建议
// 删
git tag -d 标签名 // 同样的，-D是强制删除
// 改
git tag -f -a 标签名 新的commitID -m "新的标签注释" // -f是强制将该标签应用到该commit上，如果之前已有commit使用该标签，则旧者将被删除
// 查
git tag // 罗列出所有标签号，注意，一个标签号不代表一个commit,因为一个commit可以有多个tag
git show 标签名 // 查看特定标签详细信息
// 推
git push origin --tags // 推送所有标签到远程
git push origin 标签名 // 推送单个标签
```
### 忽略文件.gitignore(以c++为例)
```cpp
# Prerequisites
*.d

# Compiled Object files
*.slo
*.lo
*.o
*.obj

# Precompiled Headers
*.gch
*.pch

# Compiled Dynamic libraries
*.so
*.dylib
*.dll

# Fortran module files
*.mod
*.smod

# Compiled Static libraries
*.lai
*.la
*.a
*.lib

# Executables
*.exe
*.out
*.app
```

### git子模块管理(嵌套git)
```cpp
// 克隆有git子模块的仓库
git clone 父仓库URL
git submodule update --init --recursive // 递归的更新和初始化子模块
// 已有父仓库，添加第三方仓库为子模块
git submodule add <子模块仓库URL> <子模块在付仓库的存储目录> // 添加之后正常的把父仓库git commit和git push即可，其他开发者拉取更新的时候，用上面的git submodule ......即可。
```

### 权限管理 
```cpp
// 权限管理更多的是代码托管平台管理的，多数使用密钥进行控制，一个团队成员一个登录密钥，不同密钥开放不同的修改、获取远程仓库资源的权限
```

### 比不同 
```cpp
// git diff 分支名/标签名/哈希值/暂存区
git diff commit // 查看当前工作目录与指定commit之间的差异
git diff commit1 commit2 // 查看两个指定commit的差异
git diff --cached commit // 查看当前暂存区与指定commit的差异
git diff branch1 branch2 // 查看两个指定分支的差异
git diff --name-only commit1 commit2 // 仅查看两个指定commit之间发生变化的文件名(不显示具体内容)
git diff -p commit1 commit2 // 显示详细的差异信息
git diff commit1 commit2 -- 文件名 // 两次commit之间的单个文件差异
```

### 暂存
```cpp
// git stash 暂时保存当前工作目录中的未提交更改，并将工作目录恢复到干净的状态
git stash // 存当前工作目录中的所有未提交的更改（包括暂存区git add和未暂存的更改），并将工作目录恢复到最后一次提交的状态，当然，如果没有暂存区和未暂存区的更改，那git stash无效
git stash save "Your stash message" // 可以在stash时添加一条说明，剩下的与git stash 功能一致
git stash list // 列出所有保存的 stash。每个 stash 都会有一个唯一的标识符，例如 stash@{0},默认会列出其暂存时的最近一次commit的-m注释内容。如果使用了git stash save -"注释",来暂存，则显示的就是save -“注释的内容”
git stash apply 序号 // 这个数字就是git stash list 里面的stash@{0}序号，按照时间顺序，最新的git stash序号就是0。apply有可能会引发冲突，解决冲突后add,commit即可。该命令不删除记录
git stash pop // 恢复最近一次保存的更改，并将其从 stash 列表中删除
git stash drop stash@{1} // 删除特定的stash 
git stash clear // 清空所有stash
git stash push -m "Your stash message" -k // 保存未暂存的更改(不包括已暂存的)
```

<a id="cylc"></a>
## 常用流程
### 情形1：将本地git仓库推送到新建的空的远程仓库
```
git init // 如果还不是git仓库，也就是没有.git文件夹，记得git init初始化一下
git add .
git commit -m "注释"
git git remote add origin http
git push -u origin 上游分支名 // 设置当前分支的远程上游分支
```
### 情形2
```
......
```
