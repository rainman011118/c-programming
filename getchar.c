#include <stdio.h>
#include <ctype.h>

int main()
{
    int ch = 'a';

    printf("Big %c\n", toupper(ch));
    printf("Little %c\n", tolower(ch));
    printf("Anaconda begins with %c\n", ch);

    int c;
    puts("Enter a name of something: ");
    do
    {
        c = getchar();
        c = toupper(c);
        putchar(c);
    } while (c != '\n');

    return 0;
}
