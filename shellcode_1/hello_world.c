#include <stdio.h>

// typedef our function pointer (improves readability).  This makes a type called 
// MY_FUNCTION_POINTER which is a function pointer to a function that takes no 
// arguments (void) and returns an int.
typedef	int (*MY_FUNCTION_POINTER)(void);

// our shellcode.  does nothing but return 1.  this was compiled from evil_function.c
unsigned char evil_shellcode[] = {0x55,0x48,0x89,0xe5,0xb8,0x01,0x00,0x00,0x00,0x5d,0xc3};

// our innocent function - antivirus will scan this
int my_function(void)
{
    // print "hello world" to the screen
    puts("hello world");

    // return the value zero
    return 0;
}

//main function
void main(void)
{
    // declare a variable of type int (integer) and assign it the value -1
    int	ret = -1;

    // declare a variable of type MY_FUNCTION_POINTER.  This is typedef'd as a 
    // function pointer on line 5
    MY_FUNCTION_POINTER my_function_pointer;

    // print out the address of my_function() and the address of our shellcode
    printf("my_function address: %p, evil_shellcode address: 0x%x\n\n",
	    &my_function,
	    &evil_shellcode
    );
    
    // assign the address of my_function to be the value of my_function_pointer
    my_function_pointer = &my_function;
    
    // print our the value of my_function_pointer
    printf("function pointer value: %p\n", my_function_pointer);

    // print what we are about to do
    printf("calling function pointer:\n");

    // call my_function_pointer() and assign the returned value to the value of 
    // ret (declared on line 25)
    ret = my_function_pointer();

    // print out the value of ret 
    // (this is the value that got returned by our function call on line 47
    // and will be zero as my_function() just got called)
    printf("Function call returned: %d\n\n", ret);

    // change the value of my_function_pointer to the address of evil_shellcode.
    // (also cast the type to a MY_FUNCTION_POINTER as evil_shellcode is of 
    // type unsigned char)
    my_function_pointer = (MY_FUNCTION_POINTER)&evil_shellcode;

    // print our the value of my_function_pointer
    printf("function pointer value: %p\n", my_function_pointer);

    // print what we are about to do
    printf("calling function pointer:\n");

    // call my_function_pointer() and assign the returned value to the value of 
    // ret
    ret = my_function_pointer();

    // print out the value of ret 
    // this is the value that got returned by our function call on line 68
    // and will be 1 as evil_function() returns a 1
    printf("Function call returned: %d\n", ret);

    // end of main, return.
    return;
}
