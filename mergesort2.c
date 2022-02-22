#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define MAXLIMIT 10

// Copied from: https://www.tutorialspoint.com/data_structures_algorithms/merge_sort_program_in_c.htm

// I removed these global arrays and just passed the pointer to a in both functions and made b local to merging fn. This was the original setup.
//char a[] = {10, 27, 19, 44, 14, 31, 90, 35, 18, 0};
//char b[10];			

void merging(char* a, int low, int mid, int high) {
		printf("merging...\n");
		char b[MAXLIMIT];					// magic number not great...better to set to FIXED SIZE VAR.
		int l, m, i;
		for(l = low, m = mid + 1, i = low; l <= mid && m <= high; i++) {
				if(a[l] <= a[m]) {
						b[i] = a[l++];
				}else {
						b[i] = a[m++];
				} 
		}
		while(l <= mid){  
			   b[i++] = a[l++];
		}
		while(m <= high) {   
				b[i++] = a[m++];
		}
		for(i=low;i <= high;i++) {
				a[i] = b[i];
		}
}
// Breaks up the array into smaller pieces: 
void sort(char* a, int low, int high) {
		int mid;
		if(low < high) {
				mid = (low + high) / 2;
				sort(a, low, mid);
				sort(a, mid+1, high);
				merging(a, low, mid, high);
		}else{ 
				 return;
		}
}
void display(char* a, int size) {
		for(int i=0;i<size;i++) {
				printf("%d ", a[i]);
		}
		printf("\n");
}

int main() { 
/**********************  Simple fixed array  **********************************
		char a[] = {10, 27, 19, 44, 14, 31, 90, 35, 18, 0};
		int SIZE = sizeof(a) / sizeof(a[0]);
		printf("size = %d\n", SIZE);
		printf("List before sorting\n");
		display(a, SIZE);
		sort(a, 0, SIZE-1);					// If using loops with <= then I guess is has to be size-1 to avoid going over...
		printf("List after sorting\n");
		display(a, SIZE);
*/
//  **************  Using random assignment and malloc  *****************************
//  Beware of stack smashing, when char b[] in merge fn is smaller than given array... #define MAXLIMIT should protect this.
		int max;
		int i;
		puts("Please set a number between 2-10 for the list");
		scanf("%d", &max);
		if(max > MAXLIMIT || max < 2) {
				printf("Number invalid, keep it between 2-10\n");
				exit(1);
		}
		char* randarr = malloc(max*sizeof(char));
		if(randarr==NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(1);
		}
		srand((unsigned)time(NULL));
		for(i=0;i<max;i++) {
				randarr[i]= rand() % 100;
		}
		display(randarr, max);
		sort(randarr, 0,max-1);
		display(randarr,max);
		free(randarr);

		return 0;
}
