#include <stdio.h>
#include <string.h>
int main()
{
    char a[20] = "Hello ";
    char b[40] = "World!";
    char c[50];

    strcpy(c, a);
    strcat(c, b);
    printf("c is now: %s\n", c);

    return 0;
}
/*strcpy will copy the NULL byte.  However, if when using STRNCPY(dest, src, no.bytes) you decide to copy less bytes than the full src string, then obviously no NULL will be included.  This may cause some issues with printf.  So you could append the NULL manually...? b[strlen(b) - 1] = 0; BUT this will chop off the last letter.  Otherwise, make sure you leave room for the NULL when copying.  e.g. no. bytes + 1
 */
