#include <stdio.h>
int main()
{
    int a = 1;
    int b = 1;
    int c = ++a || b++;
    int d = b-- && --a;
    printf("%d, %d, %d, %d,\n", d, c, b, a);
    return 0;

    /*Explanation:
    ++a || b++
    a is incremented to 2 before completion
    b is incremented to 2 after completion.
    BUT because ||, when the first part completes,
    the process stops; no need to complete the rest.
    So int c = 2

    b-- && --a
    b will be decremented AFTER
    a will be decremented BEFORE
    Therefore b = 1 && a = (2-1) = 1
    b then becomes 0 overall.
    */
}