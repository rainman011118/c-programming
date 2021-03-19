#include <stdio.h>

int main()
{
    int array1[] = {44, 56, 67, 89, 100};
    int *ptr;
    ptr = array1;
    printf("ptr = %p\n", ptr);
    printf("array1 = %p\n", array1);
    printf("&array1 = %p\n", &array1);

    printf("*ptr = %d\n", *ptr);
    printf("&*ptr = %p\n", &*ptr);
    printf("&(*ptr) = %p\n", &(*ptr));
    printf("&ptr = %p (8-bits behind)\n", &ptr);

    printf("&array1[0] = %p\n", &array1[0]);
    printf("&array1[1] = %p\n", &array1[1]);
    //printf("array1[1] = %p\n", array1[1]);
    /*The above won't work because %p expects a 
    void*, and array[1] is returning an 'int'
    */
    printf("array1[0] = %d\n", array1[0]);
    printf("array1[1] = %d\n", array1[1]);

    printf("*(ptr + 1) = %d, *(array1 + 1) = %d\n", *(ptr + 1), *(array1 + 1));
    printf("ptr = %p\n", ptr);
    printf("(ptr + 1) = %p\n", (ptr + 1));
    printf("*array1 = %d\n", *array1);
    printf("*array1 + 1 = %d\n", *array1 + 1);

    return 0;
}