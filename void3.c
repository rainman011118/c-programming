#include <stdio.h>

int main() {
    int a = 10;
    void *q = &a;
    printf("%d\n", *(int*)q);
    /* Value at *q should be a = 10.
BUT because I declared it as a void pointer, which is 
trying to access an 'int' address, you cannot call it
in the normal way (*q).
You have to typecast it as shown: *(int*)q.

VOID pointers can store any data types but you
cannot access them by dereferencing such as *q.
You would have to typecast them.
*/
    int arr[3] = {22, 33, 44};
    int *ptr = arr;
    printf("%p\n%d\n", ptr, *ptr);
    ptr = ptr + 1;
    printf("ptr+1 addr = %p\nvalue = %d\n", ptr, *ptr);

    return 0;
}
/*You can update the ptr with assignment as above, 
but you cannot do the same with arr.
e.g.
arr = arr + 1;  ERROR
*/
