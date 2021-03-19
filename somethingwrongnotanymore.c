#include <stdio.h>

int main()
{
    /*int ch;
    for (int i = 0; i < 5; i++)
    {
        printf("Enter a single character: ");
        //printf("Enter a single character %d ", i);
        ch = getchar();
        //printf("Ch=0x%08X\n", ch);
        putchar(ch);
      */
    /*The above code is the original problem.
        It would output like follows:
        "Enter a single character: a
        aEnter a single character:
        Enter a single character:"
        [So it was printing an extra line for no reason].
        Stackoverflow explained that, there was 2 inputs:
        'a' and 'enter'.
        So getchar() records 'a' and 'enter' in a queue.
        putchar = 'a'
        loop goes back to start
        printf executes
        getchar() now processes 'enter'
        putchar = 'enter'
        loop starts over with printf again.
        getchar() waits for user input.
        USE OF THE COMMENTED OUT PRINTF STATEMENTS,
        DEMONSTRATE THE ISSUE WITH 'enter' input.
        'enter' = 0x0000000A.
        */

    //THIS IS HOW IT IS DONE!!!  13/3/2021
    int ch;
    printf("Please enter a single letter: ");
    while ((ch = getchar()) != EOF && ch != '\n')
    {
        //printf("%c", ch);
        putchar(ch);
        //either of these will work.
    }
    printf("\nDone\n");

    return 0;
}
/*I'm still having a problem with multiple inputs.
If I type 'aaaaaaa', all of them get printed to screen
on same line as 'enter a single character'???
USING THE COMMENTED OUT 'PRINTF("DONE")' SHOWS THAT
GETCHAR INPUT STAYS IN THE LOOP DEPENDING ON THE 
NUMBER OF CHAR INPUTS, BEFORE GOING BACK TO START.
But putchar isn't getting printed?????
*/
