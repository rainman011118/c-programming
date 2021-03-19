#include <stdio.h>
/*WARNING!!
Watch where you put the 'int sum' line of code.
Because if you declare it at the top with the others, 
then it doesn't call properly in the print as it
does not contain the values of x and y, just the 
memory address'.
If it is put, following the scanf code lines, 
then it calls properly.
ALSO##################
If you scanf 2 numbers at once, DO NOT PUT A COMMA
BETWEEN THE 2 FORMAT CHARS: '%d, %d'
This affects the user input so that only the 1st
input is recorded (even if you input 2 figures separated
by a space.  If you press enter, it doesn't allow you to
enter the second figure.)
*/
int main()
{
    int x;
    int y;

    puts("Enter 2 numbers here:");
    scanf("%d %d", &x, &y);
    //puts("Enter a second number here:");
    //scanf("%d", &y);
    int sum = x + y;

    printf("The sum of %d and %d is %d\n", x, y, sum);
    return 0;
}