#include <stdio.h>
void main(void)
{
    int a = -1;
    switch(a)
    {
        case 0 : printf("a is equal to 0\n");
        break;
        case 1 : printf("a is equal to 1\n");
        break;
        default : printf("A is greater or less than 1\n");
    }    
}