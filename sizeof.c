#include <stdio.h>
#include <limits.h>

int main()
{
    int two = 2, three = 3, six = 6;
    int result = (two + three) * six / three;
    printf("The result of this expression is: %d\n", result);

    printf("%zu\n", sizeof(int));
    printf("%zu\n", sizeof(char));
    printf("%zu\n", sizeof(double));
    printf("%zu\n", sizeof(float));
    printf("%zu\n", sizeof(long));

    // '#include<limits.h> is needed
    short int var1 = SHRT_MIN;
    short int var2 = SHRT_MAX;
    int var3 = INT_MIN;
    int var4 = INT_MAX;
    unsigned var5 = 0;
    unsigned var6 = UINT_MAX;
    printf("range of short signed integer is from: %d to %d\n", var1, var2);
    printf("range of signed integer is from: %d to %d\n", var3, var4);
    printf("range of unsigned integer is from: %u to %u\n", var5, var6);

    return 0;
}
/*Signed and Unsigned:
Signed means it can hold negative and positive.
(hence the range tends to be half of unsigned)
Unsigned can only hold positive.*/
