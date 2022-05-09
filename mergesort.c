#include<stdio.h>
#include<stdlib.h>
#include"mergesort_fn.h"

//compile:		gcc -c mergesort_fn.c
//				gcc mergesort.c mergesort_fn.o -o merge


void display(char*, int);

int main(int argc, char** argv) {
		char array[] = {23,63,13,36,78,32,11,2,66,8,1,88,7,46};
		int SIZE = sizeof(array);
		int start = 0;
		int end = SIZE-1;
		display(array, SIZE);
		sort(array, start, end);
		display(array, SIZE);
		

		return 0;
}
void display(char* arr, int size) {
		int i;
		for(i=0;i<size;i++) {
				printf("%d ", arr[i]);
		}
		printf("\n");
}
