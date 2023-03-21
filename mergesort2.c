#include<stdlib.h> 
#include<stdio.h> 

// ************ Copied from: https://www.techgeekbuzz.com/merge-sort/ *******************

// Merges two subarrays of arr[]. 
// // 1st subarray is arr[l..m] 
// // 2nd subarray is arr[m+1..h] 
 void merge(int arr[], int l, int m, int h) { 
		 int i, j, k; 
		 int n1 = m - l + 1; 
		 int n2 = h - m; 
		 /* To create temp arrays */
		 int L[n1], R[n2]; 
		 /* This will copy data to temp arrays L[] and R[] */
		 for (i=0;i<n1;i++) {
				 L[i] = arr[l + i]; 
		 }
		 for (j=0;j<n2;j++) {
				 R[j] = arr[m + 1+ j]; 
		 }
		 /* Merge the temp arrays back into arr[l..r]*/
		 i = 0; // starting index of first subarray 
		 j = 0; // starting index of second subarray 
		 k = l; // starting index of merged subarray 
		 while (i < n1 && j < n2) { 
				 if (L[i] <= R[j]) { 
						 arr[k] = L[i]; 
						 i++; 
				 }else{ 
						 arr[k] = R[j]; 
						 j++; 
				 } 
						 k++; 
		 } 
 /* Copy the remaining elements of L[], if there is any */
		 while (i < n1) { 
				 arr[k] = L[i]; 
				 i++; 
				 k++; 
		 } 
 /* Copy the remaining elements of R[], if there is any */
		 while (j < n2) 
		 { 
				 arr[k] = R[j]; 
				 j++; 
				 k++; 
		 } 
 } 
 /* l meant for left index and r is right index of the 
// sub-array of arr to be sorted */
 void mergeSort(int arr[], int l, int h) { 
		 if(l < h) { 
		 // Same as (l+r)/2, but avoids overflow for 
		 // large l and h 
				 int m = l+(h-l)/2; 
		 // Sort first and second halves 
				 mergeSort(arr, l, m); 
				 mergeSort(arr, m+1, h); 
				 merge(arr, l, m, h); 
		 }else{
				 printf("return\n");
		 }
 } 
 /* Function to print an array */
 void printArray(int A[], int size) { 
		 int i; 
		 for (i=0; i < size; i++) {
				 printf("%d ", A[i]); 
		 }
		 printf("\n"); 
 } 
 /* This program to test above functions */
 int main() { 
		 int arr[] = {21, 11, 43, 5, 19, 7}; 
		 int arr_size = sizeof(arr)/sizeof(arr[0]); 
		 printf("Given array is \n"); 
		 printArray(arr, arr_size); 
		 mergeSort(arr, 0, arr_size - 1); 
		 printf("\nSorted array is \n"); 
		 printArray(arr, arr_size); 
		 return 0; 
 }
