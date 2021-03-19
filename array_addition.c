#include <stdio.h>

int arraySum(int myArray[], int size)
/*How does the system know what 'size' is?? - ANSWER: the parameter names do not have to match the argument names passed through.  So int size, just expects an 'int' of some sort.  
I tried it without putting a [6] in and left it blank,
but the code still ran fine?? - ANSWER: int myArray is a pointer to the memory address, therefore the program automatically detects the size of it.*/
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += myArray[i];
        printf("%dTest...\n", i);
    }
    return sum;
    //printf("%d\n", sum);
}
int main()
{
    int myArray[6] = {10, 20, 30, 40, 50, 60};
    int sizearr = sizeof(myArray) / sizeof(myArray[0]);
    printf("sizeof(myArray) = %lu\nsizeof(myArray) / sizeof(myArray[0]) = %d\n", sizeof(myArray), sizearr);

    printf("Total sum of the array is %d\nThere are 2 ways to print this: 'return sum and print', or 'print sum and call fn.'\n", arraySum(myArray, sizearr));
    //arraySum(myArray, 6);

    return 0;
}
