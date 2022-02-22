#include <stdio.h>
#include <string.h>
/*SSCANF fucked me up for ages!!!
I initially had it as scanf.
So everytime I ran it, i would type in a number,
press enter, then it would be waiting for another
input...?  I type in the same number then it would
default to one of the if statements.
And never completed properly.
I eventualy saw that it should have been Sscanf, 
and that sorted it.
SSCANF takes 3 arguments:(source, %d, &num)
This means, scan the data from source, into these
format specifiers and store at &num) */


//NOTE: This still isn't error free - If I input '5j', it completes fine, when it clearly shouldn't.  So the sscanf part is not checking each individual character, and only scans the first digit. So if it is an integer, it works fine, but if it is a non-integer, it fails.
int main()
{
    char userInput[8];
    int num = 0;
    puts("Program start...");

    while (num == 0)
    {
        printf("Please enter a number between 1 and 99: ");
        fgets(userInput, 8, stdin);

        if (strlen(userInput) < 2 || strlen(userInput) > 3)
        {
            printf("Invalid strlen()\n");
            continue;
        }
        if (sscanf(userInput, "%d", &num) != 1)
        /*THIS CAUSED ME SO MANY PROBLEMS!!
        IT WAS SSCANF NOT SCANF */
        {
            num = 0;
            printf("Invalid scanf()\n");
            continue;
        }
        if (num < 1 || num > 99)
        {
            num = 0;
            printf("Invalid range\n");
            continue;
        }
        printf("Number ok: %d\n", num);
    }

    puts("Program end...");
    return 0;
}
