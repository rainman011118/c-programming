#include <stdio.h>
#include <string.h>
/*This one took me ages to get to work.
The placement of code segments makes a HUGE 
difference. e.g. ret = strcmp(name1, name2).
If I placed this with the other declarations up top,
it didn't work.  It worked if I placed it after the
stdin was input.  And also worked BEST when within the 
conditional loop.*/
int main()
{
    char name1[20] = "Jonny";
    char name2[20];
    int ret;

    printf("Your name is %s\n", name1);
    printf("length of chars in %s is: %ld\n", name1, strlen(name1));

    puts("Please enter your first name:");
    /*Scanf works well without need for getch()
    to eat the null or 'enter'. BUT
    it let's me write more than 20 chars!!????*/
    //scanf("%s", name2);
    fgets(name2, 20, stdin);
    name2[strlen(name2) - 1] = 0;
    /*fgets doesn't work properly without the
    'strlen -1' following it.  Seems the NULL ch, 
    causes the names not to match.*/

    if ((ret = strcmp(name1, name2)) != 0)
    {
        printf("You guessed %s. This is not a match, guess again.\n", name2);
    }
    else
    {
        printf("Bravo! It's a match! %s and %s\n", name1, name2);
    }

    return 0;
}
