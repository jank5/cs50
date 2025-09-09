#!/bin/sh
sudo apt install openssh 
ssh-keygen -t rsa -b 4096 -C "klevzhic5jank@gmail.com"
echo "Уже создал ssh-ключ, осталось лишь скопировать ~/.ssh/id_rsa.pub и в гитхабе добавить скопированное"

git config --global user.name "jank5"
git config --global uesr.email "klevzhic5jank@gmail.com"
git config --global core.editor vim
git config --global init.defaultBranch main
echo "Добавлено пользователь и эл. почта гита"


echo "В гитхабе заходить в настройки и в разделе \"SSH and GPG keys\", нажать \"New SSH key\" и там называть имя и вставить то что мы скопировали."
