#include <stdio.h>
#define MAX 10

// NOTE: binary search is best used on sorted arrays!  BUT can be used on unsorted arrays;

void merge(char *arr, int low, int mid, int high) {
	char b[MAX];
	int l, m, i;
	for(l = low, m = mid + 1, i = low; l <= mid && m <= high; i++) {
		if(arr[l] <= arr[m]) {
			b[i] = arr[l++];
		}else{
			b[i] = arr[m++];
		}
	}
	while(l <= mid) {
		b[i++] = arr[l++];
	}
	while(m <= high) {
		b[i++] = arr[m++];
	}
	for(i = low; i <= high; i++) {
		arr[i] = b[i];
	}
}
void sort(char *arr, int low, int high) {
	int mid;
	if(low < high) {
		mid = (low + high) / 2;
		sort(arr, low, mid);
		sort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}
// ********  Linear binary search method  *********************
int binarysearch(char *arr, int target, int start, int end) {
	int mid;
	while(start <= end) {
		mid = start + (end - start) / 2;
		if(target < arr[mid]) {
			end = mid - 1;
		}else if(target > arr[mid]) {
			start = mid + 1;
		}else{
			return mid;
		}
	}
	return -1;
}
void printarray(char *arr, int size) {
	int i;
	for(i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main(int argc, char **argv) {
	char array[] = {22, 54, 126, 34, 7, 8, 63, 90, 0, 45};
	int SIZE = MAX;
	printarray(array, SIZE);
	sort(array, 0, SIZE - 1);
	printarray(array, SIZE);

	//  *********** Binary search part  ***********************************
	int start = 0;
	int end = sizeof(array);
	int target;
	puts("Please enter a target value between 0-127");
	scanf("%d", &target);
	int ret;
	if((ret = binarysearch(array, target, start, end)) == -1) {
		printf("Num not found\n");
	}else{
		printf("target is at index %d\n", ret);
	}

	return 0;
}
