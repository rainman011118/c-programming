#include <stdio.h>
#include <string.h>

void displayString(char str[]);

int main()
{
    char str[10];
    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);
    /*sizeof(str) is the same as just typing in the
    size value 10.*/
    printf("Length of string input is %ld\n", strlen(str));
    displayString(str);
    return 0;
}
void displayString(char str[])
{
    printf("String output: ");
    puts(str);
}
