#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// A simple program to use a pointer to iterate through each character in an array

int main(int argc, char** argv) {
		int SIZE = 32;
		int len;
		int i = 0;
		char array[SIZE];
		char* ptr = array;
		char* end;

		puts("Enter 3 words...");
		fgets(array, SIZE, stdin);
		array[strlen(array) -1] = 0;
		len = strlen(array);
		end = &array[len];
//
//		For this while loop can use either i vs strlen or ptr = endptr (i may be more straight forward)
		while(ptr != end) {
				if((isdigit(*ptr))) {
						printf("%d ", *ptr);
						ptr++;
				}else{
						ptr++;
				}
		}
		printf("\n");


		return 0;
}
