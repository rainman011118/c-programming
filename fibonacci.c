#include <stdio.h>

void fib(int x)
{
    int a = 0, b = 1, c = 0;

    if (x <= 0)
    {
        return;
    }
    if (x == 1)
    {
        printf("%d\n", a);
        return;
    }
    else if (x == 2)
    {
        printf("%d %d\n", a, b);
        return;
    }
    printf("%d %d", a, b);

    for (int i = 3; i <= x; i++)
    {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
    printf("\n");
}

int main()
{
    for (int i = 1; i <= 10; i++)
    {
        fib(i);
    }
    return 0;
}