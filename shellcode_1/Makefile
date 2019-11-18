all:
	gcc evil_function.c -o shellcode -shared
	./gen_shellcode.sh
	gcc -g3 -O0 hello_world.c -o hello_world_no_execstack
	gcc -g3 -O0 hello_world.c -o hello_world_execstack -fno-stack-protector -z execstack

clean:
	rm hello_world_no_execstack hello_world_execstack shellcode
