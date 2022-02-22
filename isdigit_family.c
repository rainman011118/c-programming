#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Just practicing random stuff

int fibonacci(int x) {
		if(x == 0) {
				return 0;
		}else if(x == 1) {
				return 1;
		}else {
				x = fibonacci(x-1) + fibonacci(x-2);
		}
		return x;
}
//factorial of n = n*fact(n-1) WRITTEN: n! = n(n-1)!
int factor(int n) {
		if(n==0) {
				return 1;
		}else if(n==1) {
				return 1;
		}else {
				n = n*factor(n-1);
		}
		return n;
}
int main(int argc, char** argv) {
//NOTE ###############   Overall, I may as well just use the 'ch = getchar()' method since that automatically retrieves the char version and assigns it to the int ch. And isdigit(ch) then works fine.
		char num = 0, fib = 0;
		puts("(Fibonacci) Enter a number between 1-10");
		scanf("%c", &num);
		printf("num = %c (dec: %d)\n", num, num);
//		int ch = isdigit(num);
//		printf("ch = %d\n", ch);
		if(!isdigit(num)) {
				printf("Error: '%c' is not a digit\n", num);
				return 1;
		}else {
		//Fibonacci sequence
		// NOTE: I cannot put '<=num' as the condition because it gets interpreted as the decimal version.  Even if I (char)num, it doesn't work (but this is going to give me the same result...Dur!...).
				for(int h=0;h<=10;h++) {
						fib = fibonacci(h);
						printf("The %d: fib is: %d\n", h, fib);
				}
		}

/*		//Factorials
		int z = 0, fact = 0;
		puts("(Factorial) Enter a number between 1-10:");
		scanf("%d", &z);
		fact = factor(z);
		printf("Factor of %d = %d\n", z, fact);

		int i, j, SIZE = 8, len;
		i = 0, j = 0;
		int array[SIZE];
		printf("sizeof(array) = %ld\n", sizeof(array));
		len = (sizeof(array) / sizeof(array[0]));
		printf("len of array = %d\n", len);
*/
		//Pointer targeting specific byte values
//		int x = 65535;//should read 00-1-1 (this is essentially 0 0 255 255 in decimal, Which is -1 in signed)
//		int x = 65536;//All should be 0100
//		int x = 65537;//should read 0101
//		int x = 65540;//should read 0104
		int x = 65536+255;//should read 010-1
		int y = 1;
		char* p = (char*)&x;
		printf("sizeof(x) = %ld\nsizeof(p) = %ld\nx = %d and char: %c\n", sizeof(x), sizeof(p), x, x);
		printf("Bit order: (MSB->LSB) %d %d %d %d\n", *(p+3), *(p+2), *(p+1), *p);

/*		//bit shifting
		printf("y = %d\ty << 1 = %d\n", y, y << 1);
		printf("y = %d\n", y);
		for(int l=0;l<8;l++) {
				y = y << 1;
				printf("y is now: %d\n", y);
				if(y == 256) {
						y -= 1;
						printf("256 - 1 = %d\nwhich is in binary: %08x\n", y, y);
				}
		}
		//Printing out hexadecimal values of chars
		printf("hexa 'A' = %0x\n", 'A');
		printf("hexa 'm' = %0x\n", 'm');
		printf("hexa '1' = %0x\n", '1');
		printf("hexa '48' = %0x\n", 48);

*/		
		//fizzbuzz:
/*		puts("Fizzbuzz...");
		int max = 30;
		for(int p = 0;p <= max;p++) {
				if(p != 0) {
						if(p % 5 == 0 && p % 3 == 0) {
								printf("%d: FizzBuzz\n", p);
						}else if(p % 3 == 0) {
								printf("%d: Fizz\n", p);
						}else if(p % 5 == 0) {
								printf("%d: Buzz\n", p);
						}else {printf("%d:\n", p);}
				}else {printf("%d:\n", p);}
		}
*/		


		return 0;
}




