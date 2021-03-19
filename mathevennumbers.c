#include <stdio.h>

int main()
{
    int x;
    for (x = 1; x <= 20; x++)
    {
        if (x > 0 && x % 2 == 0)
        {
            printf("%d\n", x);
        }
        else
        {
            continue;
            //printf(" ");
        }
        //continue;
    }
    return 0;
}
