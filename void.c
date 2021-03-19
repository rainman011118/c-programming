#include <stdio.h>
void myfunc()
{
    printf("Sum = %d\n", 5 + 25);
    printf("1 - Void function is called 'void' since it doesn't return a value like int main, which returns an 'int'\n");
}

void myfunc2();
int main()
{
    myfunc();
    myfunc2();
}
void myfunc2()
{
    printf("2 - When a void fn is placed beneath the int main, then it must be declared above int main separately too\n");
}