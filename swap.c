#include <stdio.h>

int main()
{
    int a, b, temp;
    a = 5;
    b = 10;
    printf("a is %d and b is %d\n", a, b);
    temp = a;
    a = b;
    b = temp;
    printf("After the swapping, a is now %d and b is now %d\n", a, b);
	
    return 0;
}
