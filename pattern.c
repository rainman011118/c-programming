#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {
/*		char a = '-';
		char b = '/';
		char c = '\\';
		char d = '*';

		int ROWS = 10;
		int COLS = 10;
		int i, j;
		for(i=0;i<ROWS;i++) {
				for(j=0;j<COLS;j++) {
				//		if(i+j == 4 || i+j == 5 || i+j == 9 || i+j == 13 || i+j ==14) {
				//		printf("%c", d);				//superman s (with the 2 else if)
				//		if(i>=j) {						//bottom left triangle
				//		if(j>=i) {						//top right triangle
				//		if(i+j == 9 || i == j) {		//'X' diagonals
				//				printf("%c", d);
						if((i<5 && j==5) || (i + j == 5 || j - i == 5)) {	//prints arrow head
								printf("%c", d);
				//		}else if(i == 4 && j < 6) {
				//				printf("%c", b);
				//		}else if(i == 5 && j > 4) {
				//				printf("%c", b);
						}else {
								printf("%c", a);
						}
				}
				printf("\n");
		}
*/

		// Still trying to figure this one out..... :( ########################  HACKERRANK PROBLEM
		int x = 0;
		printf("Please enter a digit between 1 and 100:\n");
		scanf("%d", &x);
		int i = 0;
		int j = 0;
		int SIZE = (x*2-1);
		for(i=0;i<SIZE;i++) {
				for(j=0;j<SIZE;j++) {
						if(i==0 | j==0 | i==SIZE-1 | j==SIZE-1 ) { // I can't keep adding specific conditions, otherwise, I will have way too many to add if the number input(x) is large. So I need to find a formula which automatically adjusts it according to the value of x.
								printf("%d ", x);
						}else{
								printf("00 ");
						}
				}
				printf("\n");
		}
		printf("SIZE = %d\n", SIZE);// z doesn't change....
		
		return 0;
}
