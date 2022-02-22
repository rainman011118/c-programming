#include<stdio.h>
#include<string.h>

void inputting_strncpy(char* array, int n) {
		int i = 0;
		printf("address array in strncpy: %p\n", array);//array here = Same as main.
		printf("address &array in strncpy: %p\n", &array);//&array = DIFFERENT....why? (ANSWER: address of array gets passed as copy to function, which then creates its own pointer, ince arrays decay to pointers, therefore the local pointer address will be different from main()).
		strncpy(array, "ABCDEFGHIJKLMNO", n);//strn copies all 12 but does not add a NULL....:S
		printf("in strncpy = %s\n", array);
}
void inputting_fgets(char* array, int n) {
		int i = 0;
		printf("address array in fgets: %p\n", array);//array here = Same as main.
		printf("address &array in fgets: %p\n", &array);//&array = DIFFERENT....why?
		puts("Enter something:");
		fgets(array, n, stdin);
		//array[strlen(array)-1] = 0;
		printf("in fgets = %s\n", array);
}
int main(int argc, char** argv) {
		int n = 12;
		char array[n];
		printf("Sizeof(array) = %ld\n", sizeof(array));
		printf("Sizeof(&array) = %ld\n", sizeof(&array));
		printf("Sizeof(array[0]) = %ld\n", sizeof(array[0]));
		printf("address array in main: %p\n", array); //both array and &array = SAME
		printf("address &array in main: %p\n", &array);
		inputting_strncpy(array, n);
		printf("in main = %s\n", array);

		inputting_fgets(array, n);
		printf("in main = %s\n", array);

		return 0;
}
