# Linux版代码提交规范工具安装
## 直接执行script文件夹下对应的sh脚本即可一键式安装
> 温馨提示：工具依赖node.js环境，如果已安装node.js可直接跳转到sudo npm install......
* 脚本预览如下：
```
#!/bin/sh
cd ~
curl -fsSL https://deb.nodesource.com/setup_18.x | sudo -E bash - &&\
sudo apt-get install -y nodejs
sudo npm install -g commitizen cz-conventional-changelog-zh conventional-changelog-cli standard-version
echo '{ "path": "cz-conventional-changelog-zh" }' >.czrc
echo 'alias genlog="conventional-changelog -p angular -i CHANGELOG.md -s"' >>.bashrc
echo 'alias stv1="standard-version -r major"' >>.bashrc
echo 'alias stv2="standard-version -r minor"' >>.bashrc
echo 'alias stv3="standard-version -r patch"' >>.bashrc
echo 'alias stvv="standard-version -r"' >>.bashrc
source .bashrc
```