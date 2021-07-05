#include <stdio.h>
#include<string.h>

#define LINE 20

int main()
{
    char str[LINE+1];
    int ch;
    int i = 0;

    printf("Enter a string: ");
    for (i = 0; (i < LINE) && ((ch = getchar()) != EOF) && (ch != '\n'); i++)
    {
        str[i] = ch;
    }
    str[i] = '\0';
    /*add NULL to 'str' variable.
    This is because str in this case is a char array, which is like 'a' 'b' 'c' 'd' 'e'. Therefore, we must add the NULL ourselves.  If it was a 'string' then it would already have one added.*/
    printf("Entered string is: %s\n", str);
	printf("strlen: %lu\n", strlen(str));
    printf("sizeof = %lu\n", sizeof(str));

    for(i = 0; i < strlen(str); i++) {
	    printf("letter [%d] is: %c %d\n", i, str[i], str[i]);
    }
    return 0;

}
/*when I use sizeof(str) as the for loop condition, it will always print out all <20 elements, even if the entered string has less chars.  Therefore, the empty elements show garbage figures.  Using strlen is better. */
