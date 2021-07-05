#include<stdio.h>
#include<stdlib.h>


// RECURSIVE CALL FUNCTION: 
void binary_rep(unsigned q) {
		if(q>1) {
				binary_rep(q/2);
		}
		printf("%d", q % 2);		//this modulus seems to be the key....?  Remainder 1 for each recursive call: 7%2, 3%2, 1%2 = 111 = 7 in binary.
}

// displays all the bits specified e.g. 16, 32, 64: 
void bin_16(unsigned p) {
		unsigned i;
		for(i=1 << 15;i>0;i=i/2) {
				(p & i) ? printf("1") : printf("0");
/* I think what is going on here is that 1 << 15 = 2^15 = 32,768. When you 1/2 this 15 times you get down to 1.
7 & 4 = 0111 & 0001 = 1
7 & 2 = 0111 & 0010 = 1
7 & 1 = 0111 & 0001 = 1
All the others before these = 0.
*/
		}
		printf("\n");
}

int main(void) {
		binary_rep(7);
		printf("\n");
		binary_rep(4);
		printf("\n");

		bin_16(7);
		bin_16(4);


		return 0;

}


