#include <stdio.h>

int main(void)
/*comment out each prior P to avoid conflict
     with ones below.*/
{
    int arr[] = {10, 20};
    int *p = arr;
    //++*p;//same as ++(*p)
    printf("arr[0] = %d, arr[1] = %d, *p = %d\n", arr[0], arr[1], *p);

    //*p++;//same as *(p++)
    printf("arr[0] = %d, arr[1] = %d, *p = %d\n", arr[0], arr[1], *p);

    *++p; //same as *(++p)
    printf("arr[0] = %d, arr[1] = %d, *p = %d\n", arr[0], arr[1], *p);
    /*Don't know why this one is not 20,20,20???
    ...because ++p targets next addr, leaving arr[0],
    as it is.*/
    return 0;
}
/* Precedence:
prefix and *(derefernce) are the same. 
Associativity reads from RIGHT to LEFT.
11,20,11
10,20,20
21,20,21
postfix is HIGHER than prefix and *(dereference).
Associativity is LEFT to RIGHT.
*/
