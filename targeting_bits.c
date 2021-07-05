#include<stdio.h>
#include<stdlib.h>

/*Playing around with char and int sizes and their limits and also typecasting bits
 */

int main(int argc, char** argv) {

		char a = 'A';
		printf("%d\n%c\n", a, a);
		int A = 'A';
		printf("%d\n%c\n", A, A);

/* ASCII  goes upto 255 BUT, beyond 127, (higher ascii), it is all special chars only.
 */

		char b = 127; // 256 will create a warning of 'overflow'
		printf("c = %c\n",b); //using %c just prints blank space for numbers 0-127. And special symbol for 128-255.

		printf("d = %d\n",b); //using %d will print decimal upto 127....then negative after this. 
		
		printf("u = %u\n",b); /*using %u will print decimal upto 127 then after this, it will print unsigned values starting from 4294967168 (128) upto 4294967295 (255). 256 = overflow warning. HOWEVER, this is the maximum 32-bit unsigned value?? Why did it not goto 16-bit first??  
		11111111 11111111 11111111 10000000 = 128
		11111111 11111111 11111111 11111111 = 255 
		Is this an example of sign extension going wrong.....?
*/
		int c = 259; //this will print out 3 (256 + 0000 0011).
		char* p = (char*)&c;
		printf("%d\n", *p);

		return 0;

}

