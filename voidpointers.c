#include <stdio.h>
int main()
{
    int n = 10;
    void *ptr = &n;

    printf("%d", *(int *)ptr);
    /*The pointer when called must be typecasted (int *).
This is because we declared a void pointer and are 
calling the pointer to return an 'int' value.
If you just call *ptr, then it will lead to error.
Now in normal circumstances we would just declare a 
int pointer and keep it simple. However, void pointers
come into their own when malloc and calloc are used.
These datatypes return void pointers.
Therefore they can allocate memory for any type of data.
Hence, it becomes easier to typecast later.


*/
    return 0;
}
