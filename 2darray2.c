#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv) {
		const int ROWS = 10;
		const int COLS = 10;
		int arr[ROWS][COLS];

		//fills up the matrix:
		for(int i=0; i<ROWS; i++) {
				for(int j=0; j<COLS; j++) {
						arr[i][j] = (i+j) + 1;
						printf("%.2d ", arr[i][j]);
				}
				printf("\n");
		}
		printf("sizeof(arr): %lu\n", sizeof(arr));

	return 0;

}

