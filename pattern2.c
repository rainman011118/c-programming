#include <stdio.h>
//Pyramid pattern

int main(void) {
		int i, space, rows, k = 0;
		printf("Enter the number of rows: ");
		scanf("%d", &rows);
		for (i=1;i<=rows;++i, k=0) {
				for (space=1;space<=rows-i;++space) {//Ever decreasing number of columns on left.
						printf("  ");
				}
				//Applying the 1 instead of the 0 in the for loops is essential, otherwise the usual 0 will interfere with the 'k' value in the while loop below and result in an infinate loop. Also, 'k=0' is KEY, because it resets k to 0 for each row.
				while (k != 2*i - 1) {//ever expanding number of columns for stars.
						printf("* ");
						++k;
				}
				//This while loop is what prints out the pyramid.  K is always starting at 0 due to the reset in the first for loop, and once the 'space' for loop ends, this while loop starts giving us our pyramid shape.
				printf("\n");
		}
		return 0;
}
		



