#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void second_biggest(int*, int);

int main(int argc, char** argv) {
		srand((unsigned)(time(NULL)));
		printf("%d\n", rand()%100);
		printf("%d\n", rand()%100);
		printf("%d\n", rand()%100);

		int SIZE = 20;
		int num[SIZE];
		for(int i=0;i<SIZE;i++) {
				num[i] = rand()%100;
				printf("%d ", num[i]);
		}
		printf("\n");
		int array[] = {52,52,-52,-52};
		second_biggest(array, 5);
		return 0;
}
void second_biggest(int* arr, int size) {
		int swp;// ############### sort first #####################################
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
/* NOTE: when negative values were present, if I didn't sort the list first, this function would not work to find the second biggest.  So is there a way to find the second biggest without having to sort it first....? 
 */
