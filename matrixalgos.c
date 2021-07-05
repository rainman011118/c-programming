#include<stdio.h>
#include<stdlib.h>

void print_matrix(int (*m)[5], int rows, int cols) {
/* I can pass (int m[5][5]) without rows and cols, it still works.  But I think good practice is to pass the sizes for rows and cols anyway. */
		for(int i=0; i<rows; i++) {
			for(int j=0; j<cols; j++) {
					m[i][j] = i+j;
					printf("%d ", m[i][j]);
			}
			printf("\n");
		}
}		
/* https://stackoverflow.com/questions/11428526/passing-a-matrix-in-a-function-c
 * There are a few ways to pass the args to this void fn:
 * (int m[5][5], int rows, int cols)
 * (int (*m)[5], int rows, int cols)
 * (int** m, int rows, int cols) - This will work if the dimensions are not fixed.
 * When passing the 'empty_matrix' through in main, it would error with: this is a 'int (*)[5]'. And would not work with int** m OR int* m[] in void.
NOTE: int** and int (*)[5] ARE NOT THE SAME - the first specifies a pointer to pointer-to-ints.(So contains pointers).  The 2nd does not specify: pointer to an array of...ints, and SO NOT pointers.  The brackets() are read first (a pointer), then [](to an array of 5), then ints..
*/
 
int main(int argc, char** argv) {
		int rows = 5, cols = 5;
		int matrix1[5][5] = {0};

		int matrix2[5][5] = {
		//		 0 1 2 3 4
				{1,1,1,1,1},// 0
				{2,2,2,2,2},// 1	
				{3,3,3,3,3},// 2	
				{4,4,4,4,4},// 3	
				{5,5,5,5,5} // 4
		};
		print_matrix(matrix1, rows, cols);

		//Algo variations:
		int i, j, n = 5;
		for(i=0; i<n; i++) {
				for(j=0; j<n; j++) {
						if(i + j == n - 1) {
							printf("%d ", matrix1[i][j]);
						}
				}
				printf("\n");
		}
		return 0;
}
/* SEE: https://www.youtube.com/watch?v=a3ropbfIpw4&list=PLfqABt5AS4FmErobw8YyTwXDUE5nPH5lH&index=18
The output should be in little endian. */
/* Different algo's:
 * j<=i	This prints lower left triangle of matrix.
 * j>=i	SEGFAULT!!!!
 * j>=0 && j<n	This prints the top row only. (But this can be done with just a single loop i).
 * if(i == j) nested loop. This prints out diagonal numbers.
 * if(i + j == n - 1). This prints opposite diagonal from top right - bottom left.(uses row and cols indexes for algo - so both added upto 4).
 */
 
