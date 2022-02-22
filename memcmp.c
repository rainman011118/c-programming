#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv) {
		int arr1[] = {1, 2};// 0001(4 bytes representation of 1st digit(1))
		int arr2[] = {1, 3};
		short int arr3[] = {1, 2};// 0102(2bytes representation of both digits(1, 2))

		//memcmp compares elements one-byte-at-a-time.  Hence why arr1, arr3 do NOT match.	
		if(memcmp(arr1, arr3, 2*sizeof(int)) == 0) {
				printf("Arrays are the same\n");
		}else {
				printf("Arrays are NOT the same\n");
		}

		//memcpy:
		int arr4[] = {5, 6};
		memcpy(arr1, arr4, 2*sizeof(int));
		printf("arr1 values now: %d %d\n", arr1[0], arr1[1]);		
		
		//memset: set destination to 0
		memset(arr1, 1, 2*sizeof(int));//If you set the values to 1, then it gives odd results because it sets the bytes value to the number.  So if I put 1, this would be interpreted as 01010101 which is the value 1 for each of the 4 bytes of the integer.  But the computer will print the decimal representation of this 01010101 which is a huge number.
		//NOTE: Be careful with the limit/range specified, since it is quite easy to accidentally memset more than what you require.  eg. 2*sizeof(int) = 8 indexes of a char array, or 2 indexes of an int array. So if you accidentally put in a larger range than required, it could overwrite memory that you didn't want, AND you would not know about it either, as no warning or error will be raised.
		printf("arr1 values now: %d %d\n", arr1[0], arr1[1]);
		printf("arr1 values in hex: %08x %08x\n", arr1[0], arr1[1]);

		//memchr: finds a specific byte value e.g. in arr4{3, 4} = 00030004. Therefore '0' is found.  If '1' is input in memchr arguments, then it would say 'Did not find the byte'.
		if(memchr(arr4, 0, 2*sizeof(int)) != NULL) {
				printf("Found the byte\n");
		}else {
				printf("Did not find the byte\n");
		}

		return 0;

}

