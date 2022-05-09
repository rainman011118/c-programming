#include<stdio.h>
#include<stdlib.h>

//strtol(const char* str, char** endptr, int base)
//takes a string, converts the intial part(usually a number) to a long, returns a char* to the remaining part of the str, following the number, use this <base> (eg 10 for decimal, 2 for binary etc).
//Returns a long if successful, otherwise, NULL.
//WILL STOP AT ANY NON-DIGIT CHAR.
//WILL IGNORE LEADING WHITESPACE, BUT WILL NOT IGNORE LEADING ALPHA CHARS.
//SEEMS ATOI RESPONDS IN THE SAME WAY

int main() {
		char* port = "32765 This is it!";
		char* ptr = NULL;
		long ret;
		short ret2; // Seems like I can choose int, short, long or whatever. Just have to make sure that the number returned is within the size parameters e.g. short = max 32768 (which = 0, otherwise 32767 is highest). (unsigned short = max 65536, which will print 0, otherwise 65535 is highest).
		printf("port = %s\n", port);
		ret = strtol(port, &ptr, 10);
		ret2 = strtol(port, &ptr, 10);
		printf("strtol = %ld\n", ret);
		printf("strtol2 = %d\tNOTE: 2 BYTE MAX BEFORE TURNING NEGATIVE = 32767 = 0111 1111 1111 1111\n", ret2);
		printf("strtol string part = %s\n", ptr);
		printf("sizeof ret = %lu\n", sizeof(ret));
		printf("sizeof ret2 = %lu\n", sizeof(ret2));

		//for atoi(), it will convert any string starting with a number, up until a non-number is reached.  If the string starts with a non-number, it will return 0.
		short x = atoi(port);
		printf("x = %d\n", x);
		printf("sizeof(x) = %lu\n", sizeof(x));

		return 0;

}
