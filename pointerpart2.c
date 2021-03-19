#include <stdio.h>

int sumofelements(int *x, int size)
/* 
int *A = int A = int A[] = int A[0] = &A?? not sure of this one
>> They are all pointers essentially.
*/
{
    int i, sum = 0;
    for (i = 0; i < size; i++)
    {
        sum += x[i];
    }
    return sum;
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    int size = sizeof(A) / sizeof(A[0]);
    int total = sumofelements(A, size);
    /*Alternative way to pass args would be:
    &A[0] or &A
    */
    printf("sumofelements = %d\n", total);

    return 0;
}