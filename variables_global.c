#include <stdio.h>
int main()
{
    int var1 = 99;
    {
        printf("Welcome to the jungle\n");

        int var1, var2, var3;
        var1 = 5;
        var2 = 3;
        var3 = 7;

        printf("%d\n", var1);
        printf("%d\n", var2);
        printf("%d\n", var3);
        printf("%d, %d, %d are all local variables\n", var1, var2, var3);
    }
    printf("%d is a global variable (outside of the block)\n", var1);
    return 0;
}