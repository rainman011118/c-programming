#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void getString(char* str) {
	strcpy(str, "test");
}

int main(int argc, char** argv) {
	char s[16]; 
	getString(s);
	printf("strlen: %lu\n", strlen(s));
	s[0] = 'p';
	printf("%s\n", s);

	return 0;
}

