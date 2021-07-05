#include <stdio.h>

void Doublesum(int *A, int size)
{
    int i, sum = 0;
    for (i = 0; i < size; i++)
    {
        A[i] = 2 * A[i];
    }
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    int size = sizeof(A) / sizeof(A[0]);
    int i;
	printf("Before fn call...\n");
	for (i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
	printf("\n");
    Doublesum(A, size);
    /*Because doublesum has been called before this loop,
    the values from doublesum are used in the loop, 
    and printed.  Otherwise, it would be 1,2,3,4,5. Because A is essentially a pointer to the array of ints, the values at the address' were directly changed by the function.  So even though they were not returned to the caller, the original values were changed. 
    */
	printf("After fn call...\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
	printf("\n");

    return 0;
}
