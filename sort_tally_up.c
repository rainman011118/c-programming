#include<stdio.h>
#include<stdlib.h>

void sort(int* p, int size) {
void print_array(int* a, int size) {
void tally_up(int* a, int size) {

int main(int argc, char** argv) {

		int arr[] = {3,4,4,6,7,1,2,2,2,9,9,8};
		int SIZE = sizeof(arr) / sizeof(arr[0]);
		int* ptr = arr;
		
		printf("array before sorting.....\n");
		print_array(arr, SIZE);
		sort(arr, SIZE);
		printf("Sorted array....\n");
		print_array(arr, SIZE);
		printf("Now for finding the most common occurrence....\n");
		tally_up(arr, SIZE);
// AT LONG LAST MOTHER FUCKER!  GOT IT!!! ##################################

		return 0;
} 
void sort(int* p, int size) {
		int i = 0;
		int swap;
		for(i=0;i<size-1;i++) {
				if(p[i] > p[i+1]) {
						swap = p[i+1];
						p[i+1] = p[i];
						p[i] = swap;
				}else{continue;}
				i = -1;
		}
}
void print_array(int* a, int size) {
		for(int i=0;i<size;i++) {
				printf("%d ", a[i]);
		}
		printf("\n");
}
// ################### TALLYS UP EACH ELEMENT AND THE FREQUENCIES ##################
void tally_up(int* a, int size) {
		int* ptr = a;
		int counter = 0;
		int i = 0;
		while(i <= size) {
				if(*ptr == a[i]) {
						counter += 1;
						i++;
				}else {
						printf("%d: %d\n", *ptr, counter);
						ptr = &a[i];
						counter = 0;
				}
		}	
}
