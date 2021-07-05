#include <stdio.h>

int main()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    /*I added the && c != EOF bit because it is safer.
    Since getchar returns chars, '\n' has a value on ASCII, 
    (10), whereas EOF doesn't.*/
    {
        putchar(c);
    }
    printf("\n");
    return 0;
}
/*We can use int c or char c.
Int c is recommended because getchar() returns integer.
getchar() also accepts numbers since these are chars.
Both int c and char c will accept.*/
