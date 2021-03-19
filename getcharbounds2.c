#include <stdio.h>

#define LINE 20


int main()
{
    char str[LINE+1];
    int ch;
    int i = 0;

    printf("Enter a string: ");
    //ch = getchar();//A>>

    for (i = 0; (i < LINE) && ((ch = getchar()) != EOF) && (ch != '\n'); i++)
    /*This specifier of conditions along with DEFINE LINE prevents excess chars from being processed as  a '\0' is added as the 21st char, and any extra chars input are removed.*/
    {
        str[i] = ch;
        //i++;
        //ch = getchar();//B>>
    }
    /*A+B (and remove '= getchar()' from while) is alternative way of performing this loop.  But it is the longer way.
     * */
    str[i] = '\0';
    /*add NULL to 'str' variable.
    This is because str in this case is a char array,
    which is like 'a' 'b' 'c' 'd' 'e'. Therefore, we
    must add the NULL ourselves. 
    If it was a 'string' then it would already have 
    one added.*/
    printf("Entered string is: %s\n", str);
    printf("sizeof = %lu\n", sizeof(str));

    for(i = 0; i < sizeof(str); i++) {
	    printf("letter [%d] is: %c %d\n", i, str[i], str[i]);
    }
   /*When I enter > 20 characters, the loop still stops at 20.  What happens to the extra chars, I don't know....
    */ 
    return 0;

}
