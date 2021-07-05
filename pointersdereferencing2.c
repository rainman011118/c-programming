#include <stdio.h>

int main()
{
    char arr[64];
    printf("call arr: %p\n", arr);
    printf("call arr + 1: %p\n", arr + 1);
    arr[0] = 'Z';
    printf("cal arr[0]: %c\n", arr[0]);
    arr[5] = 'Q';
    printf("call *(arr + 5): %c\n", *(arr + 5));
    /* WORKS FINE:
    char *ptr = arr;
    printf("%p\n", ptr);
###############################################*/
    /*char *ptr = arr[5];//This most likely won't work and may be needs to be cast....????
    printf("%c\n", *ptr);
    THE ABOVE DOESN'T WORK, BUT THE BELOW DOES...*/
    char *ptr = &arr[5];
    printf("call *ptr: %c\n", *ptr);
    printf("call *ptr - 5: %c\n", *ptr - 5);    //Printed Q-5 = 'L'
    printf("call *(ptr -5): %c\n", *(ptr - 5)); //Prints the equivalent of arr[0]
    return 0;
}
