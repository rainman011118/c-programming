#include <stdio.h>
#include <ctype.h>

int main()
{
    int acter;

    do
    {
        acter = getchar();
        if (isalpha(acter)) //isupper, isblank et al
        {
            putchar(acter);
        }

    } while (acter != '\n');

    printf("\n");

    return 0;
}
/*Gets the characters that are input and 
outputs the ones which are letters of the
alphabet only.*/
