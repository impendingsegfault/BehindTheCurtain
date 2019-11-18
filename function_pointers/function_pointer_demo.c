#include <stdio.h>

typedef	void (*MY_FUNCTION_POINTER)(void);

void my_function(void)
{
    printf("hello world\n");
    return;
}

void main(void)
{
    MY_FUNCTION_POINTER my_function_pointer = &my_function;

    printf("function address:\t(0x%p)\nfunction pointer value:\t(0x%p)\n\n", 
	    &my_function,
	    my_function_pointer
    );

    printf("calling function:\n");
    my_function();
    
    printf("\ncalling function pointer:\n");
    my_function_pointer();

    return;
}
