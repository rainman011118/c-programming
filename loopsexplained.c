#include <stdio.h>

int main() {
    int c;
    puts("Enter a letter or number: ");
    while ((c = getchar()) != '\n') {
        //printf("Char is: %c\nASCII value is: %d\n", c, c);
		putchar(c);
		printf("\n");
    }
   
/*  do {
        c = getchar();
        //printf("Char value: %c\nASCII value: %d\n", c, c);
        putchar(c);
    } while (c != '\n');
*/
    return 0;
}

/*
    ORDER OF OPERATIONS: 
################################################
I think what may be happening in the do while loop is that, getchar loads the value, putchar writes it, then that SAME written value is tested (as opposed to the next value in the getchar buffer).  So if I input ABC, A is loaded, put to screen, tested. Then B is loaded, etc. This would explain why it all works and outputs as expected with prompt on new line.  Otherwise if '\n' was tested before being loaded in getchar, then loop would break, and prompt would be on same line as letter.
So overall, the while loop is actually better.  To test before doing anything is best*/
