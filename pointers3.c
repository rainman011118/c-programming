#include <stdio.h>
/*When you declare an array, you are basically 
declaring a pointer to a string of chars.*/
int main(void)
{
    int a[5];
    *a = 10;
    printf("%d\n", a[0]);
    printf("Address of a = %p\n", &a);

    *(a + 1) = 20;
    printf("%d\n", a[1]);
    printf("Address of a = %p\n", &a[1]);
    *(a + 2) = 30;
    printf("%d\n", a[2]);
    printf("Address of a = %p\n", &a[2]);

    int arr1[] = {11, 22, 33, 44, 55, 66};
    printf("Address of arr1 is %p\n", arr1);                    //address
    printf("Value at [0] is %d\n", arr1[0]);                    //Value at...
    printf("Value at [3] is %d\n", arr1[3]);                    //Value at...
    printf("Value at start of arr1 is %d\n", *arr1);            //Value at start
    printf("Modifying the value at arr1: %d\n", *arr1 + 2);     //ADds '2' to the value at arr
    printf("increment by 1 address of arr1 is %p\n", arr1 + 1); //increments address
    printf("increment by 2 address of arr1 is %p\n", arr1 + 2);
    printf("We cannot do arr1++ because this is trying to change the address by 1 which is not allowed.\n");
    printf("Instead we use an alternative way which is to declare another pointer which points to arr1\n");
    int *p = arr1;
    printf("increment p(address) and read the value: %d\n", *(++p));
    puts("Note how *(p++) gives 11, instead of 22.  Which must mean it reads the value of p, then increments p.");
    return 0;
}