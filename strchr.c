#include <stdio.h>
#include <string.h>

/* strchr(str, char) searches the occurrence of a 
specified character in a given string and returns
the pointer to it.*/
int main()
{
    const char str[] = "C programming is great!!";
    const char ch = 'm';
    char *ptr;
    ptr = strchr(str, ch);
    /*NOTE:
    strchr returns a pointer to the first occurrence
    of the char(m) in the string.  Hence it is equivalent
    of ptr = &'m'.
    */

    printf("String starting from %c is: %s\n", ch, (char *)ptr);
    puts("The reason ptr works as a call the same as (char*)ptr, is because ptr is essentially the starting address of an array beginning at 'm'");
    printf("The value at *ptr therefore should be 'm'.... %c\n", *ptr);
    return 0;
}
/* E.g if I wanted to target only the chars after '@'
in an email, I could use strchr(email, @).*/
