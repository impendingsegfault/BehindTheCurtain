#include <stdio.h>

//typedef int (*PUTS_PTR)(const char *);

//int evil_function(void *puts_ptr, void*msg_ptr)
int evil_function(void)
{
//    PUTS_PTR puts_fp = (PUTS_PTR)puts_ptr;
//    puts_fp((const char *)msg_ptr);

    puts("I am an evil function");
    return 1;
}


