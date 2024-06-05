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