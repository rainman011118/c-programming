#include <stdio.h>
#include <string.h>
void print_fn(char *);
/*In prototyping, the exact parameters/arguments
do not have to be included, HOWEVER, the type of 
parameter does (int, char, char*).
Generally speaking, if you include everything anyway,
it is sometimes easier.
*/
int main()
{
    char a[] = "Hello Bob";

    print_fn(a);
    return 0;
}

void print_fn(char *a)
{ /*2 different ways to perform the iteration:
with a[i] using int i.
Or with *a.
*/
    //int i = 0;
    //while (a[i] != '\0')
    while (*a != '\0')
    {
        //printf("%c", a[i]);
        //i++;
        printf("%c", *a);
        a++;
    }
    printf("\n");
}