#!/bin/bash

ps
echo "AAA:" $AAA
echo "my first script"
echo "args:" $0 $1 $2 $3 $4 $5
echo '$! $$:' $! $$
read
echo '$* $@:' $* "---" $@
echo "argc:" $#
echo "last:" $_
echo "shell setting on:" $-
