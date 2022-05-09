#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ***** SIMPLEST TO USE ******
//		eg. char* buffer = NULL (NULL is the important bit)
//			size_t = 0; (number here doesn't make a difference since realloc is called automatically)
// NOTE: getline automatically will call malloc and/or realloc as required

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

		while((check = getline(&buffer, &len, fp)) != -1) {
				fputs(buffer, stdout);
//				fputs("|*\n", stdout);
		}

		fclose(fp);
		free(buffer);
		buffer = NULL;

		return 0;

}

