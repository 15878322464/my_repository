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