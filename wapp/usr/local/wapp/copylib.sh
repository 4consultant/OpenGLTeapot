#!/bin/sh

if [ ! -d "./dep" ]; then
  mkdir ./dep
else : then
  rm -rf ./dep
  mkdir ./dep
fi

ldd ./**wapp**|cut -d ">" -f 2|grep lib|cut -d "(" -f 1|xargs tar -chvf ./dep/**wapp**.tar
echo "ok"

