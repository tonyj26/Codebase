#!/bin/bash
#update git in one command

git status
git add .
git commit -m $1
git push origin master
echo "complete"
echo $1
