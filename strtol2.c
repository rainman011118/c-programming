#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {
		char* string, *stopstring;
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


		return 0;
}
