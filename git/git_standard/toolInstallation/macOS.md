# macOS版代码提交规范工具安装
## 直接执行script文件夹下对应的sh脚本即可一键式安装
> 温馨提示：工具依赖node.js环境，如果已安装node.js可直接跳转到npm install......
* 脚本预览如下：
```
#!/bin/sh
cd ~
brew install node
npm install -g commitizen cz-conventional-changelog-zh conventional-changelog-cli standard-version
echo '{ "path": "cz-conventional-changelog-zh" }' >.czrc
echo 'alias genlog="conventional-changelog -p angular -i CHANGELOG.md -s"' >>.zshrc
echo 'alias stv1="standard-version -r major"' >>.zshrc
echo 'alias stv2="standard-version -r minor"' >>.zshrc
echo 'alias stv3="standard-version -r patch"' >>.zshrc
echo 'alias stvv="standard-version -r"' >>.zshrc
source .zshrc
```