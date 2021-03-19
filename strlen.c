#include <stdio.h>
#include <string.h>

int main()
{
    char a[] = "Hello Bob";
    int len = strlen(a);
    puts("What is the length of this string? ");
    printf("char a is %d characters in length\n", len);
    printf("char a is %lu characters in length\n", strlen(a));
    puts("Notice that strlen normally takes 'lu' format but when declared as 'int len', it takes 'd'");

    return 0;
}