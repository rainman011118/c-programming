#include <stdio.h>
#include<string.h>


int main() {
		char* arr[5];//Declared a pointer to 5 arrays (double pointer).
		/*Assigned strings to each array: */
		arr[0] = "hello";
		arr[1] = "what";
		arr[2] = "the";
		arr[3] = "hell";
		arr[4] = "bitch!";

		printf("add of arr = %p\n", arr);
		printf("add of *arr = %p\n", *arr);
		/* add of arr is the master pointer address. Hence add of *arr = arr[0].
		 */
		printf("add of arr[0] = %p\n", arr[0]);
		printf("add of arr[1] = %p\n", arr[1]);
		printf("add of arr[2] = %p\n", arr[2]);
		printf("add of arr[3] = %p\n", arr[3]);
		printf("add of arr[4] = %p\n", arr[4]);
		/*These add sizes are specific to their string size+1 for the NULL terminator. No padding...?
		 */
		printf("*arr = %s\n", *arr);
		printf("*arr+1 = %s (Value at arr, move up 1 letter)\n", *arr+1);
		printf("*(arr+1) = %s (locate arr, move along 1 to next array, get value)\n", *(arr+1));


	return 0;
}



