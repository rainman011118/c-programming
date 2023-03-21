#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int** makearray(int rows, int cols);
void fillmatrix(int** arr, int rows, int cols);
void printmatrix(int** arr, int rows, int cols);
void freematrix(int** arr, int rows);
int diagonals(int** arr, int rows, int cols);

int main(int argc, char** argv) {
		int ROWS = 3;
		int COLS = 3;
		
		//HACKERRANK PART ---------------------------------
		int mat[3][3] = {
				{11, 2, 4},
				{4, 5, 6},
				{10, 8, -12}
		};

		for(int i=0;i<ROWS;i++) {
				for(int j=0;j<COLS;j++) {
						printf("%.02d ", mat[i][j]);
				}
				printf("\n");
		}
		int rd = 0;
		int ld = 0;
		int diff = 0;
		int p, q;
		for(p=0;p<ROWS;p++) {
				for(q=0;q<COLS;q++) {
						if(p==q && p+q == ROWS-1) {
								ld += mat[p][q];
								rd += mat[p][q];
						}else if(p+q == ROWS-1) {
								ld += mat[p][q];
						}else if(p==q) {
								rd += mat[p][q];
						}
				}
		}
		diff = rd-ld;
		printf("%d \n", diff);
		// -----------------------------------------


		/* My own practice with matrices
		
		int** arr = NULL;
		arr = makearray(ROWS, COLS);
		//printf("address of arr in main = %p\n", arr);

		fillmatrix(arr, ROWS, COLS);
		printmatrix(arr, ROWS, COLS);

		printf("diff = %d\n", diagonals(arr, ROWS, COLS));


		freematrix(arr, ROWS);
*/

		return 0;
}


int** makearray(int rows, int cols) {
		int** arr = malloc(rows*sizeof(int*));
		if(arr==NULL) {
				fprintf(stderr, "ERROR ALLOCATING MEMORY\n");
				exit(1);
		}
		for(int i=0;i<rows;i++) {
				arr[i] = malloc(cols*sizeof(int));
		}
		printf("matrix successfully created\n");
		//printf("address of arr = %p\n", arr);
		return arr;
}

void fillmatrix(int** arr, int rows, int cols) {
		//printf("address of arr fill = %p\n", arr);
		int i, j, r;
		srand((unsigned)time(NULL));
		for(i=0;i<rows;i++) {
				for(j=0;j<cols;j++) {
						r = rand();;
						arr[i][j] = r % 10;
				}
		}
}

void printmatrix(int** arr, int rows, int cols) {
		//printf("address of arr print = %p\n", arr);
		int i, j;
		for(i=0;i<rows;i++) {
				for(j=0;j<cols;j++) {
						printf("%d ", arr[i][j]);
				}
				printf("\n");
		}
}

void freematrix(int** arr, int rows) {
		int i, j;
		for(i=0;i<rows;i++) {
				free(arr[i]);
				arr[i] = NULL;
				printf("row freed\n");
		}
		free(arr);
		arr = NULL;
		printf("Matrix fully freed\n");
}

int diagonals(int** arr, int rows, int cols) {
		int rd = 0;
		int ld = 0;
		int diff = 0;
		int i, j;
		for(i=0;i<rows;i++) {
				for(j=0;j<cols;j++) {
						if(i==j) {
								rd += arr[i][j];
						}else if(i+j == 2) {
								ld += arr[i][j];
						}
				}
		}
		diff = abs(rd-ld);
		return diff;
}


