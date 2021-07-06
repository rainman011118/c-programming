#include<stdio.h>
#include<stdlib.h>

/*Playing around with char and int sizes and their limits and also typecasting bits
 */

int main(int argc, char** argv) {

		char a = 'A';
		printf("%d\n%c\n", a, a);
		int A = 'A';
		printf("%d\n%c\n", A, A);

		char b = 255; // 256 will create a warning of 'overflow'
		printf("c = %c\n",b); //using %c just prints blank space.....for all numbers 0-255..
		printf("c = %d\n",b); //using %d will print upto '127' (128 returns -128) and each successive number after this goes all the way down to -1 (255). 
/*NOTE: unsigned char will print all the way upto 255 value ##################################### */
		printf("c = %u\n",b); //using %u will print upto 127 as '127' then after this, it will print unsigned values upto 4294967295 (255 = 2^16). 256 = overflow warning.

		int c = 259; 		
		char* p = (char*)&c;//this will print out 3 (256 + 0000 0011) since it is targeting 8bits only.
		printf("%d\n", *p);

		return 0;

}

