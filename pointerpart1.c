#include <stdio.h>
/*https://www.youtube.com/watch?v=zuegQmMdy8M*/

int sumofelements(int *A)
{
    int i, sum = 0;
    int size = sizeof(A) / sizeof(A[0]);
    printf("int size (fn): %d\n", size);
    printf("sizeof(A) = %lu\n", sizeof(A));

    printf("sizeof(A[0]) = %lu\n", sizeof(A[0]));
    puts("I think pointers are 8 bytes long....???");
    /*
    Whereas in MAIN, because the array is declared there,
    it gets passed here as an int (Since it can access
    the whole array.)
    This means the address value is passed in the 
    external fn rather than the int value.  Hence why
    it will not work as expected.
    */
    for (i = 0; i < 5; i++)
    {
        sum += A[i];
    }
    printf("Sum of array A = %d\n", sum);

    //return sum;
}

int main()
{
    int A[] = {1, 9, 3, 4, 5};
    int size = sizeof(A) / sizeof(A[0]);
    /*When computed within the main fn:
    sizeof A = 20
    size of A[0] = 4
    */
    printf("int size (main): %d\n", size);
    //int total = sumofelements(A);
    sumofelements(A);

    return 0;
}