#include<stdio.h>
#include<stdlib.h>

#define ROW 3
#define COL 10

int main(int argc, char** argv) {
		int array[ROW][COL] = {
		{1,2,3,4,5,6,7,8,9,10},
		{11,12,13,14,15,16,17,18,19,20},
		{21,22,23,24,25,26,27,28,29,30}
		};/*Can be declared like this or simply in the normal linear array way. OR better still, just loop fill the array :) like in 2darray2.c */

		printf("sizeof(int): %lu\n", sizeof(array));
		int i, j;
		for(i=0; i<ROW; i++) {
				for(j=0; j<COL; j++) {
						//printf("array[%d][%d]: %d\n", i, j, array[i][j]);
						printf("%d ", array[i][j]);
				}
				printf("\n");
		}

		return 0;

}

