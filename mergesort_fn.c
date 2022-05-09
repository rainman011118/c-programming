#include<stdio.h>
#include"mergesort_fn.h"

void merge(char* arr, int low, int mid, int high) {
		char barr[high]; //NOTE: don't need a '#define MAX
		int l, m, i;
		for(l=low, m=mid+1, i=low;l<=mid && m<=high;i++) {
				if(arr[l]<=arr[m]) {
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
				mid = low+(high-low)/2;
				sort(arr, low, mid);
				sort(arr, mid+1, high);
				merge(arr, low, mid, high);
		}
}

