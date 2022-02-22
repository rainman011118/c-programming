#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// NOTE: getline automatically will call malloc and/or realloc as required
//		eg. declare a char* buffer = NULL (NULL is the important bit) ***** SIMPLEST TO USE ******
//			or malloc the buffer yourself: char* buffer = malloc(size)

int main(int argc, char** argv) {
		FILE* fp = fopen("/home/rain/linuxlearning/generalcommands.txt", "r");
		if(fp==NULL) {
				perror("Unable to open file:");
				exit(1);
		}
		// buffer set to null and len set to 0 since getline will assign them accodingly
		char* buffer = NULL;
		size_t len = 0;
		ssize_t check;

		while((ssize_t check = getline(&buffer, &len, fp)) != -1) {
				fputs(buffer, stdout);
//				fputs("|*\n", stdout);
		}

		fclose(fp);
		free(buffer);

		return 0;

}

