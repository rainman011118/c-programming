#include<stdio.h>
#include<stdlib.h>
		
/*This was my first version but I never finished it (From youtube video mycodeschoool).
void merge_sort(int* arr, int size) {//SHOULD I BE PUTTING IN SIZE.....?? Video shows NO. But to calculate size of array inside fn, will only give me the pointer size....??
		if(size < 2) {
				return;
		int mid = size / 2;
		//Declare 2 separate arrays for the split.
		int left[mid];
		int right[size-mid];
		//assign the values to each array.
		for(int i=0;i<mid;i++) {
				left[i] = arr[i];
		}
		for(int j=mid;j<size;j++) {
				right[j] = arr[j];
		}
		//recursive calls to split in halves again.
		merge_sort(left, mid);//This gets called repeatedly first until smallest array (single digit) is created.  Then num is returned and below 'right' is called.
		merge_sort(right, (size-mid));
		//this below is the func to sort all the smaller arrays.
		merge(left, right, arr);
		}
}
void merge(int* l, int* r, int* arr) {
		int i = 0, j = 0, k = 0;
		while(i<len(l) && j<len(r)) {//How can I get the sizes of these array...????? THIS IS THE PROBLEM..
				if(l[i] < r[j]) {
						arr[k] = l[i];
						i++;
						k++;
				}else {
						arr[k] = r[j];
						j++;
						k++;
		//Adds the leftovers into the main array....
		}while(i<len(l)) {
				arr[k] = l[i];
				i++;
				k++;
		}while(j<len(j)) {
				arr[k] = r[j];
				j++;
				k++;
		}
		}
}
*/
//NOTE: arr[] or int* arr both work fine.
// SEE: https://www.mygreatlearning.com/blog/merge-sort/
void merge(int arr[], int start, int mid, int end); 
void mergesort(int arr[], int start, int end); 
void display(int arr[], int size); 

int main(int argc, char** argv) {
		int array[] = {3, 4, 3, 6, 1, 9, 3, 8, 6, 4};
		int SIZE = sizeof(array) / sizeof(array[0]);

		printf("Before sorting.....\n");
		display(array, SIZE);

		printf("Sorting array...\n");
		mergesort(array, 0, SIZE-1);
		display(array, SIZE);

		return 0;
}
//This just splits up the list into all the smaller sublists recursively, then calls merge().
void mergesort(int* arr, int start, int end) {
		if(start<end) {
				int mid = start+(end-start) / 2;
				mergesort(arr, start, mid);
				mergesort(arr, mid+1,end);
				merge(arr, start, mid, end);
		}
}
//Note: start(0), and end(size-1) are required.  Not sure why SIZE on its own is not enough....?
void merge(int* arr, int start, int mid, int end) {
		int len1 = mid - start+1;
		int len2 = end - mid;

		int leftArr[len1], rightArr[len2];
		for(int i=0;i<len1;i++) {
				leftArr[i] = arr[start+i];
		}
		for(int j=0;j<len2;j++) {
				rightArr[j] = arr[mid+1+j];
		}

		int i, j, k;
		i = 0;
		j= 0;
		k = start;

		while(i<len1 && j<len2) {
				if(leftArr[i] <= rightArr[j]) {
						arr[k] = leftArr[i];
						i++;
				}else {
						arr[k] = rightArr[j];
						j++;
				}
				k++;
		}
		while(i<len1) {
				arr[k] = leftArr[i];
				i++;
				k++;
		}
		while(j<len2) {
				arr[k] = rightArr[j];
				j++;
				k++;
		}
}
void display(int* arr, int size) {
		for(int i=0;i<size;i++) {
				printf("%d ", arr[i]);
		}
		printf("\n");
}
