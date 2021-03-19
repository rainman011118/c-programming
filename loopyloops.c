#include <stdio.h>
int main()
/*Can use %c for the character or %d for the ASCII value*/
{
    char a[5] = "Hello";
    int i = 0;
    printf("a = %p\n&a = %p\n*a = %c or %d(ASCII)\n *(a+1) = %c or %d(ASCII)\n", a, &a, *a, *a, *(a + 1), *(a + 1));

    puts("while loop...");
    while (a[i] != '\0')
    /*You can use individual letters 'H', 'l' as conditions too.*/
    {
        printf("%c", a[i]);
        i++;
    }

    puts("\nfor loop...");
    char b[5] = "Jonny";
    int j;
    for (j = 0; j < 5; j++) /*The full condition must be provided. Can declare 'int j = 0;' inside loop condition but cleaner to declare separate.*/
    {
        printf("%c", b[j]);
    }

    puts("\ndo-while loop...");
    char c[5] = "Magic";
    int k = 0;
    do
    {
        printf("%c", c[k]);
        k++;
    } while (k < 5);
    return 0;
}