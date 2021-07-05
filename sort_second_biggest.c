#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*These are all the prototypes in my program.  I think I can make these into header files and then 'include them externally......? */
void display(int*, int);
void find_max(int*, int);
void sort_ascending(int*, int);
void sort_descending(int*, int);
void sort_then_second_biggest(int*, int);

int main(int argc, char** argv) {
		srand((unsigned)(time(NULL)));
		printf("%d\n", rand()%100);
		printf("%d\n", rand()%100);
		printf("%d\n", rand()%100);

		int SIZE = 20;
		int num[SIZE];
		//fill the list #######################################
		for(int i=0;i<SIZE;i++) {
				num[i] = rand()%100;
				printf("%d ", num[i]);
		}
		printf("\n");

		sort_ascending(num, SIZE);
		display(num, SIZE);
		sort_descending(num, SIZE);
		display(num, SIZE);

		find_max(num, SIZE);

		sort_then_second_biggest(num, SIZE);

		return 0;
}
void find_max(int* arr, int size) {
		int max = arr[0];
		printf("Finding max...\n");
		for(int i=0;i<size;i++) {
				if(arr[i] > max) {
						max = arr[i];
				}else {continue;}
		}
		printf("Max = %d\n", max);
}
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
void sort_then_second_biggest(int* arr, int size) {
		int swp;// ############### sort first #####################################
		printf("Sorting and then finding second biggest...\n");
		for(int i=0;i<size-1;i++) {
				if(arr[i] > arr[i+1]) {
						swp = arr[i+1];
						arr[i+1] = arr[i];
						arr[i] = swp;
						i = -1;
				}else {continue;}
		}// ###################### then find 2nd biggest ##########################
		int max = arr[0];
		int next_max = 0;
		for(int i=0;i<size;i++) {
				if(arr[i] > max) {
						next_max = max;
						max = arr[i];
				}else if(arr[i] == max) {
						continue;
				}else if(arr[i] > next_max) {
						next_max = arr[i];
				}
		}
		printf("max = %d\nnext_max = %d\n", max, next_max);
}
void display(int* arr, int size) {
		for(int i=0;i<size;i++) {
				printf("%d ", arr[i]);
		}
		printf("\n");
}
