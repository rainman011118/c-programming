#include <stdio.h>
#include <ctype.h>

int main()
{
    int x;
    do {
        x = getchar();
        if (isalpha(x)) {
			putchar(x);
		}
	}while (x != '\n');

    printf("\ndone\n");

    return 0;
}
/*Gets the characters that are input and 
outputs the ones which are letters of the
alphabet only.*/
