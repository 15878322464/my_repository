# windows版代码规范工具安装
> windows版本还未有一键式脚本，需要手动安装，步骤如下
## 一、安装node.js环境
> 温馨提醒：如已安装该环境可直接跳到第二步
* 1.1.下载script文件夹下的node_download.bat脚本，双击运行,可下载node安装程序到当前目录，双击运行安装程序，根据自己安装习惯安装即可（也可以自己去官网下载安装）
## 二、使用npm安装相应包
* 2.1.下载script文件夹下的windows_git_standard.bat脚本并将其放入自己当前c盘的用户根目录下,双击运行即可。
![image](../images/%E7%94%A8%E6%88%B7%E5%BD%93%E5%89%8D%E7%9B%AE%E5%BD%95.png)
* 脚本预览如下：
```
npm install -g commitizen cz-conventional-changelog-zh conventional-changelog-cli standard-version
echo { "path": "cz-conventional-changelog-zh" } > .czrc
```