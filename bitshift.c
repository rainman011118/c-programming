#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv) {
		unsigned int a = 5;
		
		printf("Left shifted by 1: %d\n", a << 1);
		printf("Left shifted by 2: %d\n", a << 2);
		printf("Left shifted by 3: %d\n", a << 3);

		int i;
		for(i=0;i<32;i++) {
				printf("Left shifted by %02d: %08x | %d\n", i, a<<i, a<<i);
		}

		return 0;

}
/* NOTE: at shift 29 and 31 the numbers go negative and this is because of the carry overflow.
 Before that, the number just doubles with each shift of 1. 
SEE: https://www.youtube.com/watch?v=lvjW-aUcbF0

Left shift multiplies the number by 2 to the power of the shift digit.
Right shift tends to divide the number by 2 to the power of the shift digit, up until we get to zero.
 ALSO: on the right shift, if the number stars with 0(positive), it adds a zero to the beginning. If the number starts with 1(negative) it adds a 1 at the beginning.
 */

