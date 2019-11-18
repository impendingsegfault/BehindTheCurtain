#include <stdio.h>

void main(void)
{
    char    c;
    char    *pointer_to_c;


    c = 'a';
    pointer_to_c = &c;

    printf("c:\t\t\t(0x%x (%c))\n"
	    "address of c (&c):\t(0x%x)\n"
	    "pointer_to_c:\t\t(0x%x)\n"
	    "*pointer_to_c:\t\t(0x%x (%c))\n\n", 
	    c,
	    c, 
	    &c,
	    pointer_to_c,
	    *pointer_to_c,
	    *pointer_to_c
    );

    c = 'z';
    
    printf("c:\t\t\t(0x%x (%c))\n"
	    "address of c (&c):\t(0x%x)\n"
	    "pointer_to_c:\t\t(0x%x)\n"
	    "*pointer_to_c:\t\t(0x%x (%c))\n\n", 
	    c,
	    c, 
	    &c,
	    pointer_to_c,
	    *pointer_to_c,
	    *pointer_to_c
    );


    *pointer_to_c = 'm';

    printf("c:\t\t\t(0x%x (%c))\n"
	    "address of c (&c):\t(0x%x)\n"
	    "pointer_to_c:\t\t(0x%x)\n"
	    "*pointer_to_c:\t\t(0x%x (%c))\n\n", 
	    c,
	    c, 
	    &c,
	    pointer_to_c,
	    *pointer_to_c,
	    *pointer_to_c
    );



    return;
}
