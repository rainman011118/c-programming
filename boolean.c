#include <stdio.h>
int main()
{
    int raining = 1;
    int has_umbrella = 1;

    if (!raining && !has_umbrella)
    {
        printf("Go out\n");
    }
    else
    {
        printf("Stay in\n");
    }

    return 0;
}
/*1 = TRUE
0 = FALSE
for(;;) = same as for(1) = while(1) = TRUE
*/