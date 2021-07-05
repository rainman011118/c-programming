#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"sort.h"

// ############## Remember to compile this file using the header and object files #############
// creates the object file: 		gcc -c sort_functions.c
// compiles the program:			gcc new.c sort_functions.o -o new_program

void display(int* arr, int size) {
		for(int i=0;i<size;i++) {
				printf("%d ", arr[i]);
		}
		printf("\n");
}
int main(int argc, char** argv) {
		srand((unsigned)(time(NULL)));
		int SIZE = 20;
		int num[SIZE];
		//fill the list #######################################
		for(int i=0;i<SIZE;i++) {
				num[i] = rand()%100;
				printf("%d ", num[i]);
		}
		printf("\n");

		sort_ascending(num, SIZE);
		display(num, SIZE);
		sort_descending(num, SIZE);
		display(num, SIZE);

		return 0;
}

