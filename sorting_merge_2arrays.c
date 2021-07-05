#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* THIS SORTING DIDN'T WORK. IT OUTPUT FINE, BUT NOT CORRECT.....????? */
void merge(int arr1[], int arr2[], int size1, int size2);
void fill_array(int* a, int size); 

int main(int argc, char** argv) {
		srand((unsigned)time(NULL));
		int SIZE1 = 20;
		int SIZE2 = 15;
		int arrayA[SIZE1];
		int arrayB[SIZE2];
		fill_array(arrayA, SIZE1);
		fill_array(arrayB, SIZE2);
		printf("Merge sorting both arrays.....\n");
		merge(arrayA, arrayB, SIZE1, SIZE2);
	
		return 0;
}
void merge(int arr1[], int arr2[], int size1, int size2) {
		int finalArray[size1+size2];
		int i=0, j=0, k=0;
		while(i<size1 && j<size2) {
				if(arr1[i]<arr2[j]) {
						finalArray[k++] = arr1[i++];
				}else {
						finalArray[k++] = arr2[j++];
				}
		}
		while(i<size1) {
				finalArray[k++] = arr1[i++];
		}
		while(j<size2) {
				finalArray[k++] = arr2[j++];
		}
		for(int i=0;i<size1+size2;i++) {
				printf("%d ", finalArray[i]);
		}
		printf("\n");
}
void fill_array(int* a, int size) {
			for(int i=0;i<size;i++) {
					a[i] = rand() % 100;
					printf("%d ", a[i]);
			}
			printf("\n");
}



