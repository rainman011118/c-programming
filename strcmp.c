#include <stdio.h>
#include <string.h>

//strcmp returns 3 different ints:
//	<0 if size of string1 is less than string2
//	>0 if size of string1 is more than string2
//	0 == match.

int main()
{
    char name1[20] = "Jonny";
    char name2[20];

    printf("Your name is %s\n", name1);
    printf("length of chars in %s is: %ld. strlen automatically discounts the NULL terminator here.\n", name1, strlen(name1));

    puts("Please enter your first name:");
    /*Scanf works well without need for getch()
    to eat the null or 'enter'. BUT
    it let's me write more than 20 chars!!????*/
    //scanf("%s", name2);
    fgets(name2, 20, stdin);
	printf("len = %ld. strlen counts the new line char because it was included by fgets. NULL terminator is automatically appended by fgets too but is not counted by strlen.\n", strlen(name2));
    name2[strlen(name2) - 1] = 0;

	int ret = strcmp(name1, name2);
    if(ret != 0) {
        printf("Wrong! %s is not a match, guess again.\n", name2);
    }else{
        printf("Bravo! It's a match! %s and %s\n", name1, name2);
    }

    return 0;
}
