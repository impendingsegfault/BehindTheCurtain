#!/bin/bash

sc=$(echo x/11bx evil_function|gdb -q ./shellcode |cut -f2 -d':'|grep 0x|tr -d '\n'|tr '\t' ','|sed -e s%,%%)

sed s%^unsigned.*evil.*$%unsigned\ char\ evil_shellcode[]\ =\ {${sc}}\;% < hello_world.c > hello_world.c.new

mv hello_world.c.new hello_world.c
