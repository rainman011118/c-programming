#include <stdio.h>
#include <stdlib.h>
/*https://overiq.com/c-programming-101/the-malloc-function-in-c/

SYNTAX: void *malloc(size_t size);
p = (datatype *)malloc(size);

Malloc always returns a void pointer.
size_t (it's own datatype) is equivalent to unsigned int.

int main()
{
    int *p;                //declares p = pointer to int
    p = (int *)malloc(20); //allocate 20 bytes

    int *ptr;
    ptr = (int *)malloc(5 * sizeof(int)); //allocate sufficient memory for 5 ints.
                                          /*This method, using sizeof gives flexibility to 
    our program i.e. makes it portable.
    
    It is GOOD PRACTICE to always check the value
    returned by malloc() in case the heap runs out
    of free space:
    
    if (p == NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }
}*/
int main()
{
    float *p, sum = 0;
    int i, n;

    printf("Enter the number of students: ");
    scanf("%d", &n);
    p = (float *)malloc(n * sizeof(float));
    if (p == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (i = 0; i < n; i++)
    {
        printf("Enter marks for %d student: ", i + 1);
        scanf("%f", p + i);
    }
    for (i = 0; i < n; i++)
    {
        sum += *(p + i);
    }
    printf("\nAverage marks = %.2f\n", sum / n);
    free(p);
    return 0;
}