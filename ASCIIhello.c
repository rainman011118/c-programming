#include <stdio.h>
int main()
/*Can use %c for the character or %d for the ASCII value*/
{
    int a[] = {'H', 'e', 'l', 'l', 'o', '\0'}; //"Hello";
    int i = 0;
    printf("%d\n", *a);
    /*Note how I don't have to declare a separate pointer and I can simply dereference the array by pointer method since all arrays are basically pointers.
*/
    while (a[i] != '\0')
    {
        printf("%c = %d\n", a[i], a[i]);
        i++;
    }
    return 0;
}
