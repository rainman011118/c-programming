#include <stdio.h>

int main()
{
    int c;
    puts("Enter a letter or number: ");
    /* while ((c = getchar()) != '\n')
    {
        printf("Char is: %c\nASCII value is: %d\n", c, c);
        //putchar(c);
    }
    //printf("\n");
    */
    do
    {
        c = getchar();
        //printf("Char value: %c\nASCII value: %d\n", c, c);
        putchar(c);
    } while (c != '\n');

    return 0;
}
/*
    ORDER OF OPERATIONS: WHILE LOOP
################################################
PUTS() single char example: ('a', 'enter') FAULTY
1)character gets loaded into getchar() buffer
2)char is tested vs '\n'
3)if not '\n', putchar(c).
4)next char loaded into getchar() loop
5)'Enter' = '\n', therefore loop stops.
So 'enter' is consumed by getchar().
6)There will be no space between prompt since, '\n'
was consumed.  So printf('\n').

PRINTF() example (single char example): GOOD.
1)character gets loaded into getchar() buffer.
2)char is tested vs '\n'.
3)if not '\n', printf().
4)next char loaded into getchar() loop.
5)'enter' = '\n', therefore loop stops.

IT IS BETTER TO HAVE '(c = getchar())' inside
while loop condition rather than in block.
##################################################
    ORDER OF OPERATIONS: DO LOOP
PUTS: GOOD
1)'a' loaded into getchar() buffer.
2)'a' output by puts(). (automatic new line by puts).
3)next char ('enter') tested by condition = FAIL, loop stops.

PRINTF: FAULTY
1)'a' is loaded into getchar() buffer.
2)printf scans 'c' and outputs results.
3)'a' is tested by while loop = continue.
4)'enter' is loaded into getchar().
5)printf scans 'c' and outputs 'enter'.
6)'enter' is tested by while loop = STOP.

################################################
LOOKS LIKE PUTS 'CONSUMES' THE CHAR BEFORE IT CAN 
BE TESTED, SO ONLY NEXT CHAR IS TESTED = 'ENTER'.
WHEREAS, PRINTF DOESN'T CONSUME CHARS, ONLY SCANS 
THEM, SO CURRENT CHAR GETS TESTED = LOOP GOES AGAIN.

USE PRINTF WITH WHILE LOOP.
USE PUTS() WITH DO WHILE LOOP.

*/