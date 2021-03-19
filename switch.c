#include <stdio.h>
int main()
{
    int x = 2;
    printf("Switch with no breaks:\n");
    switch (x)
    {
    case 1:
        printf("Choice is 1\n");
    case 2:
        printf("Choice is 2\n");
    case 3:
        printf("Choice is 3\n");
    case 4:
        printf("Choice is 4\n");
    default:
        printf("Choice other than 1, 2, 3 and 4\n");
    }
    printf("Outside of x switch\n\n");

    printf("Switch with breaks:\n");
    int y = 2;
    switch (y)
    {
    case 1:
        printf("Choice is 1\n");
        break;
    case 2:
        printf("Choice is 2\n");
        break;
    case 3:
        printf("Choice is 3\n");
        break;
    case 4:
        printf("Choice is 4\n");
        break;
    default:
        printf("Choice other than 1, 2, 3 and 4\n");
    }
    printf("Outside of y switch\n");

    return 0;
}