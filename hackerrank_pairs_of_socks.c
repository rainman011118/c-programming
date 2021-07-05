#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sort(int*, int);
void display(int*, int);
void how_many_pairs(int*, int);

int main(int argc, char** argv) {
		srand((unsigned)time(NULL));
		int SIZE = 20;	
		int b[SIZE];
		int* p = b;
		for(int i=0;i<SIZE;i++) {
				b[i] = rand() % 10;
		}
		display(b, SIZE);
		sort(b, SIZE);
		display(b, SIZE);
/* This below loop counts how many of each element there is and also how many pairs of elements there are.  From a hackerrank challenge. This is my attempt at it.  Not sure it will pass all test cases. I had to sort the array first, because I just couldn't figure out a way to do it without sorting it. */
		how_many_pairs(b, SIZE);
		return 0;
}
void sort(int* arr, int size) {
		int swp;
		for(int i=0;i<size-1;i++) {
				if(arr[i] > arr[i+1]) {
						swp = arr[i];
						arr[i] = arr[i+1];
						arr[i+1] = swp;
						i = -1;
				}
		}
}
void display(int* arr, int size) {
		for(int i=0;i<size;i++) {
				printf("%d ", arr[i]);
		}
		printf("\n");
}
void how_many_pairs(int* b, int size) {
		int* p = b;
		int i = 0;
		int count = 0;
		int pairs = 0;
		for(i=0;i<size;i++) {
				if(b[i] == *p && p < (p+size)) {
						count += 1;
						if(count % 2 == 0) {
								pairs += 1;
						}
				}else {
						printf("%d: count = %d  pairs = %d\n", *p, count, pairs);
						count = 0;
						pairs = 0;
						p = &b[i];
						i--;
				}
		}
		//Had to put this last print statement here because it wasn't printing the final index results since if it ended in the 'if' statement and not the 'else', then no print was activated.
		printf("%d: count = %d  pairs = %d\n", *p, count, pairs);
}

