#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {
		char* string, *stopstring;
		// The stopstring pointer is automatically set to the position in the string where the numbers finish.
		// string can be also be an array.

		long l;
		int bs;

		string = "10110134932";
		printf("string = %s\n", string);
		//EXAMPLE USING A BASE 2 (i.e. will read all numbers 0-1.  BASE 4 will read 0-3 etc).
		//BASE4 = 4096 1024 256 64 16 4 0

		for(bs=2;bs<8;bs*=2) {
				l = strtol(string, &stopstring, bs);
				printf("	strtol = %ld (base %d)\n", l, bs);
				printf("	pointer stops at ...%s\n\n", stopstring);
		}

		// ERROR CHECKING
		/*
		if the beginning of the string doesn't contain any numbers, then what happens is that the position of stopstring == string, so we can use: 
				if(str == stopstr) {
						printf("number couldn't be parsed\n")
						return (1);
				}


		if number is too big, then normally 'max int' is returned.
		For this we can use the errno.h header and an if statement:
				if(errno == ERANGE) {
						printf("Number is too big to be stored in the variable\n");
						return (1);
				}

*/

		// SEE CODEVAULT YOUTUBE - how to parse and validate a number in C.
		// ALSO, SSCANF CAN BE USED. SCANS A STRING UPTO WHATEVER DELIMITER YOU CHOOSE, so this could also work on the time24hr.c file.	(sscanf(str, "%[^:];%[^:];%d;%d", name, city, &age, &hasdegree);

		return 0;
}

