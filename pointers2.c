#include <stdio.h>
//https://www.youtube.com/watch?v=zuegQmMdy8M
int main()
{
    int a = 10; //declared int a
    int *p;     //declared pointer to int
    p = &a;     //points to address of a
    printf("Address at p = %p\n", p);
    printf("Value at *p = %d\n", *p);
    printf("size of integer is %ld bytes\n", sizeof(int));
    printf("Address at p+1 is %p\n", p + 1); //incrementing the pointer by 4 bytes
    printf("Address at p+2 is %p\n", p + 2);
    printf("Value at p+1 is %d - this is a garbage value\n", *(p + 1));
    //
    printf("\n");

    char *p0;
    p0 = (char *)p0; //typecasting
    /*Typecasting or Typeconversion is when you need
    to convert one data type into another.
    e.g. int('abc')
    it was not working before because the video showed
    'p0 = (char *)p;' AND THE 'p'WAS WRONG!!!
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    It made the output show that p and p0 had 
    the same address and *p had the 
    same value 10.
    ALSO VIDEO USES %d FOR ADDRESS' AND IT DOESN'T WORKa
    */

    printf("size of char is %ld bytes\n", sizeof(char));
    printf("Address = %p, value = %d\n", p0, *p0);
    printf("Address = %p, value = %d\n", p0 + 1, *(p0 + 1));
}