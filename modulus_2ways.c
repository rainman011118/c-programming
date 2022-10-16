#include <stdio.h>
int main()
{
    int num;
    printf("please enter a 2 digit number: ");
    scanf("%d", &num);
    if (num % 2 == 0)
    {
        printf("%d is even\n", num);
    }
    else
    {
        printf("%d is odd\n", num);
    }
    /*Alternative way is using the Ternary operator:
    */
    int num2;
    printf("please enter another 2 digit number: ");
    scanf("%d", &num2);

    (num2 % 2 == 0) ? printf("%d is even\n", num2) : printf("%d is odd\n", num2);

    return 0;
}
