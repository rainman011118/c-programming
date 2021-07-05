#include"sort.h"

void sort_ascending(int* arr, int size) {
		int swp;
		printf("Sorting in ascending order...\n");
		for(int i=0;i<size-1;i++) {
				if(arr[i] > arr[i+1]) {
						swp = arr[i+1];
						arr[i+1] = arr[i];
						arr[i] = swp;
						i = -1;
				}else {continue;}
		}
}
void sort_descending(int* arr, int size) {
		int swp;
		printf("Sorting in descending order...\n");
		for(int i=0;i<size-1;i++) {
				if(arr[i] < arr[i+1]) {
						swp = arr[i+1];
						arr[i+1] = arr[i];
						arr[i] = swp;
						i = -1;
				}else {continue;}
		}
}

