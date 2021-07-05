#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sort(int* arr, int size) {
		int swap;
		int NEW_SIZE = size - 1;
		for(int i=0;i<NEW_SIZE;i++) {
				if(arr[i+1] < arr[i]) {
						swap = arr[i+1];
						arr[i+1] = arr[i];
						arr[i] = swap;
						i = -1;
				}
		}
}//This for loop seems simpler than the other while loop. (No need for the else clause);		
int main(int argc, char** argv) {

		srand((unsigned)time(NULL));
		printf("%d\n", rand()%100);
		printf("%d\n", rand()%100);
		printf("%d\n", rand()%100);

		int SIZE = 30;
		int arr[SIZE];
		int i;
		for(i=0;i<SIZE;i++) {
				int r = rand() % 100;
				arr[i] = r;
				printf("%d ", r);
		}
		printf("\n");
		printf("Sorting....\n");
		sort(arr, SIZE);
		for(i=0;i<SIZE;i++) {
				printf("%d ", arr[i]);
		}
		printf("\n");
		return 0;
}

