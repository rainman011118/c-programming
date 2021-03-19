#include <stdio.h>
void Doublesum(int *A, int size)
/* This function doubles the values in the array A
*/
{
    int i, sum = 0;
    for (i = 0; i < size; i++)
    {
        A[i] = 2 * A[i];
    }
}
int main()
/*We declare variables, call the function Doublesum,
and loop - print the results.
*/
{
    int A[] = {1, 2, 3, 4, 5};
    int size = sizeof(A) / sizeof(A[0]);
    int i;
    Doublesum(A, size);
    /*Because doublesum has been called before this loop,
    the values from doublesum are used in the loop, 
    and printed.  Otherwise, it would be 1,2,3,4,5.
    */
    for (i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}