#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge(char* a, int low, int mid, int high) {
		char b[high];
		int i, l, m;
		for(l=low,m=mid+1,i=low;l<=mid && m<=high;i++) {
				if(a[l]<=a[m]) {
						b[i] = a[l++];
				}else{
						b[i] = a[m++];
				}
		}
		while(l<=mid) {
				b[i++] = a[l++];
		}
		while(m<=high) {
				b[i++] = a[m++];
		}
		for(i=low;i<=high;i++) {
				a[i] = b[i];
		}
}
void sort(char* arr, int start, int end) {
		int mid;
		if(start<end) {
				mid = start+(end-start)/2;
				sort(arr, start, mid);
				sort(arr, mid+1, end);
				merge(arr, start, mid, end);
		}
}
int binarysearch(char* arr, int start, int end, int target) {
		int mid;
		while(start<=end) {
				mid = start+(end-start)/2;
				if(target==arr[mid]) {
						return mid;
				}else if(target<arr[mid]) {
						end=mid-1;
						binarysearch(arr, start, end, target);
				}else{
						start=mid+1;
						binarysearch(arr, start, end, target);
				}
		}
		return -1;
}
void display(char* arr, int size) {
		int i;
		for(i=0;i<size;i++) {
				printf("%d ", arr[i]);
		}
		printf("\n");
}
int main(int argc, char** argv) {
		char array[] = {23,56,26,22,68,3,6,1,89,41};
		int SIZE = strlen(array);
		int start = 0;
		int end = SIZE-1;
		puts("Original unsorted array");
		display(array, SIZE);
		sort(array, start, end);
		puts("Sorted array");
		display(array, SIZE);

		puts("now for the binary search bit:");
		int val, target;
		printf("Please enter a number betwwen 0-100\n");
		scanf("%d", &target);
		if((val=binarysearch(array, start, end, target)) == -1) {
				printf("Value not found in array\n");
				exit(-1);
		}else{
				printf("Value %d found at index %d\n", target, val);
		}

		return 0;
}

