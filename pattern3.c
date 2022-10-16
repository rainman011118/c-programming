#include <stdio.h>
//Pattern to print Floyd's triangle.

int main(void) {
		int rows, i, j, number = 1;
		puts("Please enter the number of rows: ");
		scanf("%d", &rows);
		for(i=0;i<rows;++i) {
				for(j=0;j<=i;++j) {
						printf("%02d ", number);
						++number;
				}
				printf("\n");
		}
		return 0;
}
		



