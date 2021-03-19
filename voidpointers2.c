#include <stdio.h>
/*https://overiq.com/c-programming-101/void-pointers-in-c/
Typecasting and dereferencing void pointers
*/
int main()
{
    int i = 10;
    float f = 2.35;
    char ch = 'k';

    void *vp;

    vp = &i;
    printf("Value of i is: %d\n", *(int *)vp);

    vp = &f;
    printf("Value of f is: %.2f\n", *(float *)vp);

    vp = &ch;
    printf("Value of ch is: %c\n", *(char *)vp);

    return 0;
}
/*A void pointer is declared which can point to any 
data type.
But when a specific data type is being returned in an
expression, you must typecast it so the compiler knows
what type is expected.
*/