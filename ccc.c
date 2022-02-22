#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 10

void printarray(char* arr, int size) {
		int i;
		for(i=0;i<size;i++) {
				printf("%d ", arr[i]);
		}
		printf("\n");
}
void merge(char* arr, int low, int mid, int high) {
		printf("calling merge with\n");
		printarray(arr, high);
		char barr[MAX];
		int l, m, i;
		for(l = low, m = mid+1, i = low;l <= mid && m <= high;i++) {
				if(arr[l] < arr[m]) {
						barr[i] = arr[l++];
				}else{
						barr[i] = arr[m++];
				}
		}
		while(l<=mid) {
				barr[i++] = arr[l++];
		}
		while(m<=high) {
				barr[i++] = arr[m++];
		}
		for(i=low;i<=high;i++) {
				arr[i] = barr[i];
		}
}
void sort(char* arr, int low, int high) {
		int mid;
		if(low<high) {
				mid = (high+low) / 2;
				sort(arr, low, mid);
				sort(arr, mid+1, high);
				merge(arr, low, mid, high);
		}else{
				return;
		}
}
void fillarray(char* arr, int size) {
		srand((unsigned)time(NULL));
		int i;
		for(i=0;i<size;i++) {
				arr[i] = rand() % 100;
		}
}

int main(int argc, char** argv) {
		int SIZE = MAX;
		char array[SIZE];
		fillarray(array, SIZE);
		printarray(array, SIZE);
		sort(array, 0, SIZE-1);
		printf("Final output\n");
		printarray(array, SIZE);

		return 0;
}

