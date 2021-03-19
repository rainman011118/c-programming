#include <stdio.h>

void display(char arr[])
{
    printf("String: ");
    puts(arr);
}

int main()
{
    char one[30];
    printf("Enter a short string here: ");
    fgets(one, 30, stdin);
    display(one);
    return 0;
}