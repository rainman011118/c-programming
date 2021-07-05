#include<stdio.h>
#include<stdlib.h>

int** create_int_matrix(int nrows, int ncols) {
		int** m = malloc(nrows*sizeof(int*));//This creates a block of memory for 10 pointers (80bytes).
		if(m == NULL) {
				fprintf(stderr, "Memory allocation failed!\n");
				exit(1);
		}
		for(int i=0; i<nrows; i++) {
				m[i] = malloc(ncols*sizeof(int));//This creates another separate block of memory to hold 10 ints FOR EACH ELEMENT(40 bytes each).
/*Picture this whole thing as 10 large boxes(m**) laid out left to right. And then 10 smaller boxes(m[i]) stacked on top of each of the larger boxes. It is these 10 smaller boxes that actually form the 10x10 matrix.  The m** boxes are just like foundations for the matrix.*/
		}
		return m;
}
void free_int_matrix(int** m, int nrows) {
		for(int i=0; i<nrows; i++) {
				free(m[i]);//Clears the matrix (integers)
				m[i] = NULL;
		}
		free(m);//Clears the double pointers (10 x 8byte blocks...)
		m = NULL;
}
void print_int_matrix(int** m, int nrows, int ncols) {
		for(int i=0; i<nrows; i++) {
				for(int j=0; j<ncols; j++) {
						printf("%.2d ", m[i][j]);//the .2 evens out the array on the screen.
				}
				printf("\n");
		}
}
int main() {
		printf("sizeof(int): %lu\n", sizeof(int));
		int nrows = 10;
		int ncols = 10;
		int** m = create_int_matrix(nrows, ncols);

		for(int i=0; i<nrows; i++) {
				for(int j=0; j<ncols; j++) {
						m[i][j] = i*j;
				}
		}
		print_int_matrix(m, nrows, ncols);
		free_int_matrix(m, nrows);	

		return 0;
}

