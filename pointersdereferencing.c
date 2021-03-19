#include <stdio.h>
int main()
{
    int a = 10;
    int *p;
    p = &a; //&a = address of a
    printf("a = %d, address of a = %p\n", a, &a);
    *p = 12; // dereferencing
    printf("a = %d, address of a = %p\n", a, p);
    *p = 24; // dereferencing
    printf("a = %d, address of a = %p\n", a, p);

    int **q = &p;
    int ***r = &q;
    /*Dereferencing the pointers */
    printf("*p = %d\n", *p);
    printf("*q = %p\n", *q);
    printf("*(*q)) = %d\n", *(*q));
    printf("*(*r)) = %p\n", *(*r));
    printf("*(*(*r))) = %d\n", *(*(*r)));
    /*Each star is like a hop.
    ***r for example:
    * points to &q
    ** points to &q > &p
    *** points to &q > &p > &a = VALUE
    */
    return 0;
}