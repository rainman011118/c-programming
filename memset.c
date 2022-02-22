#include<stdio.h>
#include<string.h>

//memset is best used only with 1byte chars, NOT so much ints.  (For ints, the best thing to do is simply create a loop to set/initialise it.

void print_arr(int* array, int SIZE) {
		for(int i=0;i<SIZE;i++) {
				printf("arr[%d]: %d\n", i, array[i]);
		}
}
int main(int argc, char** argv) {
		int SIZE = 5;
		int arr[SIZE];
		//Will print random shit, as I haven't initialised it.
		puts("arr before memset");
		print_arr(arr, SIZE);

		memset(arr, 0, sizeof(arr));
		//Each byte is changed to the specified figure.
		printf("sizeof(arr) = %ld\n", sizeof(arr[0]));
		puts("arr after memset");
		print_arr(arr, SIZE);

		return 0;
}

//sizeof(arr) = 20bytes
//sizeof(arr[0]) = 4bytes
//sizeof(int) = 4bytes
//sizeof(int)*SIZE = 20bytes

//NOTE: Careful with the limit/range specified with sizeof(), because if you accidentally input a larger range than required, it will still compile fine, but it means that it will overwrite other memory....and NO ERROR is raised...so you will never know about it.
