#include <stdio.h>
#include <string.h>

/* Strings automatically add the NULL char.
You must allow for it in the [5] or leave it [].*/
int main()
{
	int Length;
	char ch[20] = {'J', 'o', 'n', 'a', 't', 'h', 'a', 'n', '\0'};
	printf("Length of string is: %ld\n", strlen(ch));

	return 0;
}
/*WAYS TO INITIALIZE STRINGS:
char c[] = "abcd";

char c[50] = "abcd";

char c[] = {'a', 'b', 'c', 'd', '\n'};

char c[5] = {'a', 'b', 'c', 'd', '\0'};

THIS IS WRONG:
char c[5] = "abcde"
specified 5 but there are 6 in 'abcde' due to the NULL character.
*/
