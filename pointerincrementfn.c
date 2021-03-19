#include <stdio.h>
/*https://www.youtube.com/watch?v=zuegQmMdy8M*/

void increment(int a)
//This int a is not the same as the int a in main(). See the address values as proof.
{
    printf("Address of a(fn) is: %p\n", &a);
    a += 1;
    //printf("%d\n", a);
    //return a;
}
/*NOTE: uncomment the parts to return a value to the 
function caller and change void to int ^^.
*/
void increment2(int *p)
{
    *p = (*p) + 1;
}

int main()
{
    int a, b;
    a = 10;
    increment(a);
    printf("Even after fn call, a is unchanged: %d\n", a);
    //b = increment(a);
    //printf("Returning a from the fn: b = %d\n", b);
    printf("Address of a(main) is: %p\n", &a);
    increment2(&a);
    printf("a = %d\t", a);

    return 0;
}
