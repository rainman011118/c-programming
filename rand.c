#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	printf("%d to %d\n", 0, RAND_MAX);
	printf("Before seed is used:(these numbers never change)\n%d\n", rand());
	printf("%d\n", rand());
	printf("%d\n", rand());

    srand((unsigned)time(NULL));/*This initializes the random number generator*/

	printf("Now after the seed is used:(these numbers are different each run)\n%d\n", rand());
	printf("%d\n", rand());
	printf("%d\n", rand());

    int x, r;
    x = 10;
	puts("Now a loop of random numbers between 0-100");
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
