# alpine为基础的golang环境dockerfile示例
FROM alpine
WORKDIR /dataSetMaking
COPY ./datamake //dataSetMaking/

RUN wget https://dl.google.com/go/go1.17.8.linux-amd64.tar.gz && \
    tar -C /usr/local/ -xzf go1.17.8.linux-amd64.tar.gz && \
    rm go1.17.8.linux-amd64.tar.gz && \
    echo -e "export GOROOT=/usr/local/go \nexport GOPATH=/home/go/ \nexport PATH=$PATH:$GOROOT/bin" >> /etc/profile && \
    source /etc/profile && \
    go env -w GOPROXY=https://mirrors.aliyun.com/goproxy,direct GO111MODULE=on CGO_ENABLED=0 GOPRIVATE=git.gittai.cn,e.coding.net
    # 命令依次对应解析：
    # wget:下载golang压缩包
    # tar:解压golang包到/usr/local/
    # rm:删除压缩包
    # echo:设置系统环境变量
    # source:重启配置文件，使变量立即生效
    # go env:配置go环境变量

# 由于alpine镜像使用的是musl libc而不是gnu libc，/lib64/ 是不存在的。会存在not found的问题，但他们是兼容的，可以创建个软连接解决。
RUN mkdir /lib64 && ln -s /lib/libc.musl-x86_64.so.1 /lib64/ld-linux-x86-64.so.2
