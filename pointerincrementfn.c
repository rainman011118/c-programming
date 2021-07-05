#include <stdio.h>
/*https://www.youtube.com/watch?v=zuegQmMdy8M*/

void increment(int a)
//This int a is not the same as the int a in main(). See the address values as proof.
{
    printf("Address of a(fn) is: %p\n", &a);
    a += 1;
    printf("value of a(fn) printed by fn: %d\n", a);
   // return a;
}
/*NOTE: uncomment the parts to return a value to the 
function caller and change void to int ^^.
*/
void increment2(int *p)
{
    *p = *p + 1;
}

int main()
{
    int a, b;
    a = 10;
    increment(a);
    printf("Even after fn call, a(main) is unchanged: %d\nThis is because we only pass a copy into the other fn, which doesn't affect our local a(main) value.\n", a);
    printf("Also, if I print 'increment(a)' instead of just 'a', then I will get the answer 11 as I am referencing a(fn) and not a(main).\nEven when I return a, printing a(main) is still unchanged.\n");
    //b = increment(a);
    //printf("Returning a from the fn: b = %d\n", b);
    printf("Address of a(main) is: %p\n", &a);
    increment2(&a);
    printf("a = %d\nThis a(main) value changes because we passed the pointer to a(main) and the fn outside of main directly changed it's value\n", a);

    return 0;
}
