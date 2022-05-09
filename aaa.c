#include<stdio.h>
#include<stdlib.h>

void display(int** m, int rows, int cols) {
		int i, j;
		for(i=0;i<rows;i++) {
				for(j=0;j<cols;j++) {
						m[i][j] = i+j*2;
						printf("%02d ", m[i][j]);
				}
				printf("\n");
		}
}
void freeall(int** m, int rows) {
		int i;
		for(i=0;i<rows;i++) {
				free(m[i]);
				m[i] = NULL;
		}
		free(m);
		m == NULL;
		printf("all freed...\n");
}
				
int main(int argc, char** argv) {
		int ROWS = 5;
		int COLS = 5;
		int** matrix = malloc(ROWS*sizeof(int*));
		if(matrix==NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(1);
		}
		for(int i=0;i<ROWS;i++) {
				matrix[i] = malloc(COLS*sizeof(int));
		}
				
		display(matrix, ROWS, COLS);
		freeall(matrix, ROWS);


		return 0;
}
