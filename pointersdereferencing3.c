#include <stdio.h>

int main()
{
    int x = 5, y = 10, z = 20;
    int *p0 = &x;
    printf("x = %i and *p0 = %i and addr of p0 = %p\n", x, *p0, p0);
    puts("declaring '*p0 = &x' is the same as saying the value at p0 = 5\nBUT, it literally says *p0 = &x which is confusing\nbecause p0 = &x, while *p0 = 5\n");
    *p0 = 6;
    printf("update of *p0 is now %i\n", *p0);
    printf("x is now also changed to %i\n", x);

    int **p1 = &p0;
    printf("&x = %p\np0 holds address x = %p\np1 holds address of p0 = %p\n*p1 = the address that p0 holds(i.e. x's addr) %p\n", &x, p0, p1, *p1);
    printf("1 star = value of p1 is the addr that p0 points to\n2 stars = the value at the addr that p0 points to: %i\n", **p1);

    **p1 = 7; //Dereferencing: basically says: 'x is 7'
    printf("\np0 = %p and &x = %p\n", p0, &x);
    printf("*p0 = %i\n", *p0);
    printf("p1 = %p\n", p1);
    printf("*p1 = %p and this should be the addr of p0\n", *p1);
    printf("**p1 = %i\n", **p1);
    //int *p1 = &y;
    //printf("y = *p1 = %i\n", *p1);

    return 0;
}