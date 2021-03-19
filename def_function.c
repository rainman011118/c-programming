#include <stdio.h>
int addNumbers(int a, int b); //function prototype

int main()
{
    int n1, n2, sum;
    printf("Enter two numbers: ");
    scanf("%d %d", &n1, &n2);

    sum = addNumbers(n1, n2); //function call
    printf("Sum = %d\n", sum);

    return 0;
}
int addNumbers(int a, int b) //function definition
{
    int result = a + b;
    return result;
    //return a + b;
    //Which way is better...? returning the variable result, or the calculation.
}
/*Remember, since user defined fn is below main, 
it must be declared as prototype above main too.*/
