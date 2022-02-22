#include<stdio.h>
#include<stdlib.h>

//Playing around with char and int sizes and their limits and also typecasting bits

int main(int argc, char** argv) {
		printf("sizeof(int): %lu\nsizeof(char): %lu\nsizeof(char*): %lu\n", sizeof(int), sizeof(char), sizeof(char*));
		char a = 'A';
		printf("%d\t%c\n", a, a);
		int A = 'A';
		printf("%d\t%c\n", A, A);

// ASCII  goes upto 255 BUT, beyond 127, (higher ascii), it is all special chars only.

		char b = 128; // 256 will create a warning of 'overflow'
		printf("char value of %u = %c\n",(unsigned)b, b); //using %c just prints whatever char is located  from 0-127. And special symbol for 128-255.
		printf("decimal value of %u = %d\n",(unsigned)b, b); //using %d will print decimal upto 127....then negative after this. BECAUSE CHAR B = 1BYTE = MAX127 BEFORE SIGN BECOMES NEGATIVE(if b was int, it would print all numbers valid upto 4bytes worth. I could also declare b as an unsigned char and then 0-255 would work too.)
		
		printf("unsigned value of %u = %u\n",(unsigned)b, b); /*using %u will print the unsigned integer upto 127 then after this, it will print unsigned 4byte values starting from 4294967168 (128) upto 4294967295 (255). 256 = overflow warning. HOWEVER, this is the maximum 32-bit unsigned value?? Why did it not goto 16-bit first??  
		11111111 11111111 11111111 10000000 = 128
		11111111 11111111 11111111 11111111 = 255 
		Is this an example of sign extension going wrong.....? SEE BELOW FOR ANSWER!!!
*/
		int c = 259;
		char* p = (char*)&c;
		printf("using char* to target lowest 8bits of int: %d\n", *p); //this will print out 3 since it is only referencing the lowest 8bits of the number. (256 + 0000 0011).
		p = (char*)&c+1;
		printf("targeting the 2byte of the int with (char*)&c+1: %d\n", *p);

		return 0;

}
/*	10000000 = -128 in char(8bits)
 * 	unsigned int form should be: 00000000 00000000 00000000 10000000 (which should be 128) since sign is 0.
 * 	BUT IT ISN't BECAUSE....sign extension!!!
 * 	In signed extension, the MSB is extended into the higher bits.
 * 	Instead it is: 11111111 11111111 11111111 10000000 = huge number (positive since it is unsigned)
 * 	Hence char 255 = -1 decimal = 11111111
 * 	Unsigned int form (just add 1's to other bits) = 11111111 11111111 11111111 11111111
 */
