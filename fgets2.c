#include <stdio.h>
int main()
{
    char input[64];

    printf("Instructions: ");
    fgets(input, 64, stdin);
    printf("Thank you, here are your instructions: %s\n", input);
    //puts("Thank you, here are your instructions:");
    //puts(input);
    return 0;
}