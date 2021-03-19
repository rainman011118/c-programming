#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int x, r;

    srand((unsigned)time(NULL));
    /*This initializes the random number generator*/

    x = 10;
    while (x > 0)
    {
        r = rand();
        printf("%d\n", r % 100);
        x--;
    }
    return 0;
}
/*The modulus operator means that only numbers,
between 0 - 99 will be shown.
% 50 = 0-49 */