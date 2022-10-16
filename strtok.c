#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
		char str[] = "Let's break\tthis string\tinto 3 pieces.";

		char* piece = strtok(str, "\t");//Read up to the first <tab>
		while(piece != NULL) {
				printf("%s\n", piece);
				piece = strtok(NULL, "\t");//Null means: just use the previous input(str) and read upto the next <tab>
		}
		return 0;
}
