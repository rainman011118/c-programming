#include <stdio.h>
/*Program to print all odd numbers between 1-20*/
int main()
{
    int i, n = 2;
    for (i = 1; i <= 20; i++)
    {
        if (i == n)
        {
            n = n + 2;
            continue;
        }
        printf("%d ", i);
    }
    //printf("\nOutside of loop block, hence we get: %d ", i);
    return 0;
}
/* i = 1, is this less than 20 - yes
    check if i == n...it is !=
    print i(1), increment i to 2, start loop again.
    i = 2, is this less than 20 - yes
    check if i == n...it is EQUAL.
    n = n + 2, so n is now 4..go to start(skips print)
    increment i to 3.
    
    NOTE: IF YOU REMOVE THE CONTINUE, THEN PRINTF
    IS EXECUTED EVERYTIME WHICH MEANS ALL NUMBERS
    BETWEEN 1-20 WILL BE PRINTED.
    
    NOTE: The commented out printf completely changes
    the output, where it will simply read '21'
    This is because it is sitting outside the 'if block'
    Therefore only executes after all the other
    blocks have completed.*/