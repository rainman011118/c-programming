#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {
		char a = '-';
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
						if(i+j == 9 || i == j) {		//'X' diagonals
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

		return 0;
}
