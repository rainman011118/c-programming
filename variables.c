#include <stdio.h>
int func();

int var = 10;

int main()
{
    int var = 3;
    printf("%d is printed since it is the local var\n", var);
    func();

    return 0;
}
int func()
{
    printf("%d is printed here because it accesses the global var\n", var);
}