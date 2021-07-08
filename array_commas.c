#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv) {
		char letter[] = "A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z";
		for(int i=0;i<strlen(letter);i++) {
				if(letter[i] != ',') {
		/*The bloody commas are included as individual elements in the array...! */
						printf("char = %c\tdecimal = %d\thex = %0x\n", letter[i], letter[i], letter[i]);
				}else {continue;}
		}
		int array[] = {1,2,3,4,5,6,7,8,9,10};
		for(int j=0;j<10;j++) {
				printf("%d\n", array[j]);
		}




		return 0;
}



