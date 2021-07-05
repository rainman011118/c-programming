#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv) {
		int arr1[] = {1, 2};// 0001(4 bytes representation of 1st digit(1))
		int arr2[] = {1, 3};
		short int arr3[] = {1, 2};// 0102(2bytes representation of both digits(1, 2))
//memcmp compares elements one-byte-at-a-time.  Hence why arr1, arr3 do NOT match.	

		if(memcmp(arr1, arr3, 2 * sizeof(int)) == 0) {
				printf("Arrays are the same\n");
		}else {
				printf("Arrays are NOT the same\n");
		}

		//memcpy:
		int arr4[] = {5, 6};
		memcpy(arr1, arr4, 2 * sizeof(int));
		printf("arr1 values now: %d %d\n", arr1[0], arr1[1]);		

		
		//memset: set destination to 0
		memset(arr1, 0, 2 * sizeof(int));//If you set the values to 1, then it gives odd results because it sets the bytes value to the number.  So if I put 1, this would be interpreted as 01010101 which is the value 1 for each of the 4 bytes of the integer.  But the computer will print the decimal representation of this 01010101 which is a huge number.
		printf("arr1 values now: %d %d\n", arr1[0], arr1[1]);

		return 0;

}

