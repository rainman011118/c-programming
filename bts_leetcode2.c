#include<stdio.h>
#define MAX 10

// ******************  Detecting order of array before selecting binary search  ***********************

void merge(char* arr, int low, int mid, int high) {
		char b[MAX];
		int l, m, i;
		for(l=low, m=mid+1, i=low;l<=mid && m<=high;i++) {
				if(arr[l] <= arr[m]) {
						b[i] = arr[l++];
				}else{
						b[i] = arr[m++];
				}
		}
		while(l<=mid) {
				b[i++] = arr[l++];
		}
		while(m<=high) {
				b[i++] = arr[m++];
		}
		for(i=low;i<=high;i++) {
				arr[i] = b[i];
		}
}
void sort(char* arr, int low, int high) {
		int mid;
		if(low<high) {
				mid = (low+high) / 2;
				sort(arr, low, mid);
				sort(arr, mid+1, high);
				merge(arr, low, mid, high);
		}
}
int isascending(char* arr, int start, int end) {
		if(end == MAX) {
				if(arr[start] < arr[end-1]) {
						return 1;
				}else{
						return 0;
				}
		}
		if(arr[start] < arr[end]) {
				return 1;
		}else{
				return 0;
		}
}
// *************  LINEAR METHOD  ************************************************
int binarysearch(char* arr, int target, int start, int end) {
		int mid;
		while(start<=end) {
				mid = start+(end-start) / 2;
				if(arr[mid] == target) {
						return mid;
				}
				if(isascending(arr, start, end)) {
						printf("ascending..\n");
						if(target < arr[mid]) {
								end = mid-1;
						}else if(target > arr[mid]) {
								start = mid+1;
						}
				}else{
						printf("descending..\n");
						if(target > arr[mid]) {
								end = mid-1;
						}else if(target < arr[mid]) {
								start = mid+1;
						}
				}
		}
		return -1;
}
//  ******************* RECURSION METHOD  *****************************************
//  Always have the stopping condition at beginning of recursion functions.
int binaryrec(char* arr, int target, int start, int end) {
		int mid, hit;
		mid = start+(end-start) / 2;
		if(arr[mid] == target) {
				return mid;
		}
		if(isascending(arr, start, end)) {
				printf("ascending..\n");
				if(target < arr[mid]) {
						mid = binaryrec(arr, target, start, mid-1);
				}else if(target > arr[mid]) {
						mid = binaryrec(arr, target, mid+1, end);
				}
		}else{
				printf("descending..\n");
				if(target > arr[mid]) {
						mid = binaryrec(arr, target, start, mid-1);
				}else if(target < arr[mid]) {
						mid = binaryrec(arr, target, mid+1, end);
				}
		}
		return mid;
}
void printarray(char* arr, int size) {
		int i;
		for(i=0;i<size;i++) {
				printf("%d ", arr[i]);
		}
		printf("\n");
}
int main(int argc, char** argv) {
		char array[] = {127,126,121,94,77,68,63,40,39,25};
		int start = 0;
		printf("address of array: %p\n", array);
		printarray(array, MAX);
		sort(array, 0, MAX-1);
		printarray(array, MAX);
		
// NOTE: When I sort the array, the binary searches doesn't work....... ARRRRGGGGHHHHHH!!!!!!!!!!!!!!!
// it can't find numbers: 
// 121 68 39 which are at indexes: 7, 4, 1....?????
// I have found where it is fucking up I think....
// first was in ISASCENDING FN: i was comparing to array[10] instead of array[10-1].
// 2nd was finding 68(4) led to start = 3, end = 4, mid = 3. When it checks for isascending (3rd run), end-1 == mid, therefore, this is fucking it up....SORTED!!

//  *********** Binary search part  ***********************************
		printf("MAX = %d\n array[MAX] = %d\narray[MAX-1] = %d\n", MAX, array[MAX], array[MAX-1]);
		int target;
		puts("Please enter a target value between 0-127");
		scanf("%d", &target);
		int ret;
/*		if((ret = binarysearch(array, target, start, MAX)) == -1) {
				printf("Num not found\n");
		}else{
				printf("target is at index %d\n", ret);
		}
*/
		if((ret = binaryrec(array, target, start, MAX)) == -1) {
				printf("Num not found\n");
		}else{
				printf("target is at index %d\n", ret);
		}

		return 0;
}
				
