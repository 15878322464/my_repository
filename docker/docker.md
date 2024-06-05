<div align="center">
<b> Docker Command </b>
</div>

### docker系统级命令
```cpp
// 关
sudo systemctl stop docker // 关闭docker(记得先关闭所有运行容器)
// 启动
sudo systemctl start docker // 启动docker
sudo systemctl restart docker
// 加载配置服务
systemctl daemon-reload // 重新加载docker配置
systemctl restart docker.service // 重新加载docker服务
// 清理
docker builder prune -f // 清理不再使用的构建缓存和构建者对象
docker system prune -f // 清理系统中不再使用的资源，包括未被使用的容器、镜像、网络和卷等
// 查看
docker system df // 显示Docker系统的磁盘使用情况摘要,主要包括images、containers、local volumes、build cache
```

### 镜像
```cpp
docker pull 镜像名称:tag标签 // 例如下载ubuntu镜像：docker pull ubuntu:noble-20240429
docker rmi 镜像名/ID // 删除镜像(只有该镜像的所有引用容器stop了才能删除，否则只能用-f强制删除)
docker rmi -f $(docker images -q) // 删除全部镜像
docker tag imageID imageName:tag // 镜像重命名(一般只在自己创建或者打包的镜像使用，下载其他人的镜像不建议重命名，会丢失该镜像的来源信息)
```

### 容器
```cpp
// 创建
docker run -it --net=host -v 主机挂载目录:容器挂载目录 --name 容器名 镜像名/ID /bin/bash // 创建容器、启动并进入容器，还有很多参数可使用：
/*
--gups all // 使用全部的gpu
*/

// 停
docker stop 容器名/ID
docker stop $(docker ps -aq) // 停止所有容器

// 删(只能删除已经stop的容器)
docker rm 容器名/ID
docker rm -f $(docker ps -aq) // 删除所有容器

// 查
docker ps // 查询正在运行的容器
docker ps -a // 查询所有容器(包括未运行的)

// 改
docker rename 旧容器名 新容器名 // 修改容器名(无需暂停容器)

// 进入已经正在运行的容器
docker exec -it 容器名/ID /bin/bash // 进入容器还有很多选项可以使用：
/*
-u 用户名 // 以哪个用户的身份进入
*/

// 启动已经创建好的但是停止了的容器
docker start 容器名/ID 

// 打包
docker commit -a "作者名" -m "说明" 容器id 新的镜像名:tag // 将容器打包为新的镜像(挂载目录下的文件不会被打包进去)

// 容器与宿主机的文件传递(临时性，如果需要长期持续性进行文件传递建议使用文件挂载)
docker cp 宿主机文件路径 容器id:容器内路径 //将宿主机文件拷贝到容器
docker cp 容器id:容器内路径 宿主机路径 // 将容器文件拷贝到宿主机

```

### 文件挂载