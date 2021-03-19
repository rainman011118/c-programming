#include <stdio.h>
int main()
{
    int x = 5;
    char ch = 'a';

    printf("int x = %d, char ch = %c\n", x, ch);
    int z = x + ch;

    printf("Sum of int x and char ch = %d\n", z);
    printf("(char ch is automatically converted to it's ASCII No.)\n");

    double a = 1.5;
    int sum = (int)a + 1;
    printf("Sum of double and int (via typeconversion) = %d\n", sum);

    int result = 17, count = 5;
    double mean;

    mean = (double)result / count;
    printf("Type conversion of int into double:\nValue of mean = %f\n", mean);
    return 0;
}