#include <stdio.h>
#include <string.h>
int main()
{
    char a[20] = "Hello ";
    char b[40] = "World!";
    char c[50];

    strcpy(c, a);
    strcat(c, b);
    printf("c is now: %s\n", c);

    return 0;
}