#include <stdio.h>

void sum(int x, int y)
/*This can't be a void datatype since it is passing
2 integers and returning an integer....lol
*/
{
    int sum = x + y;
    printf("Sum = %d\n", sum);
}
int main()
{
    sum(33, 79);
    sum(5, 5);

    int a, b;
    printf("Enter a number: \n");
    scanf("%d", &a);

    printf("Enter a second number: \n");
    scanf("%d", &b);

    sum(a, b);
}