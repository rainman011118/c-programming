#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	
int main(int argc, char** argv) {
		char str[5]; //This is pretty much an empty string.

		//char str[] = ""; //This is also an empty string with 1 element which = \0. So you would NOT want to strcpy a larger string to this. It may be better off declaring it: const char str[] = ""; Tried this and it just said: conflict with strcpy.  When compiled without 'const', I get a warning: trying to copy 5bytes into size of 1.

		printf("strlen = %lu\n", strlen(str));
		strcpy(str, "Jack");
		printf("strcpy = %s\n", str);
		printf("strlen = %lu\n", strlen(str));

		
		return 0;
}

