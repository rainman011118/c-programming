#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge(int* arr, int low, int mid, int high);
void sort(int* arr, int low, int high);
void printout(int* a, int size);
int binarysearch(int* a, int start, int end, int tar);

int main(int argc, char** argv) {
		int array[] = {22, 35, 1, 63, 77, 32, 73, 45, 7, 69};
		int size = sizeof(array) / sizeof(array[0]);
		int start = 0;
		int end = size-1;
		printout(array, size);
		puts("Now for the sorting....");
		sort(array, start, end);
		printout(array, size);
		puts("Now to search for a target");
		int target, val=0;
		puts("Please enter a number between 0-100");
		scanf("%d", &target);
		if((val = binarysearch(array, start, end, target)) ==-1) {
				fprintf(stderr, "target not found\n");
				exit(1);
		}else{
				printf("Target found at index %d\n", val);
		}

		return 0;
}

void merge(int* arr, int low, int mid, int high) {
		int barr[high];
		int i, l, m;
		for(l=low, m=mid+1, i=low;l<=mid && m<=high;i++) {
				if(arr[l] <= arr[m]) {
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
void sort(int* arr, int low, int high) {
		int mid;
		if(low<high) {
				mid = low+(high-low)/2;
				sort(arr, low, mid);
				sort(arr, mid+1, high);
				merge(arr, low, mid, high);
		}
}
int binarysearch(int* a, int start, int end, int tar) {
		int mid;
		while(start<=end) {
				mid = start+(end-start)/2;
				if(tar==a[mid]) {
						return mid;
				}else if(a[mid]<tar) {
						start = mid+1;
				}else{
						end = mid-1;
				}
		}
		return -1;
}
void printout(int* a, int size) {
		int i;
		for(i=0;i<size;i++) {
				printf("%d  ", a[i]);
		}
		printf("\n");
}


