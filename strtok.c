#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
		char str[] = "Let's break this string into pieces.";

		char* piece = strtok(str, " ");//Read up to the first <space>
		while(piece != NULL) {
				printf("%s\n", piece);
				piece = strtok(NULL, " ");//Null means: just use the previous input(str) and read upto the next <space>
		}
		return 0;
}
