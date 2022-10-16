#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ***** SIMPLEST TO USE ****** BUT NOT THE MOST TECHNICALLY CORRECT
//		eg. char* buffer = NULL (NULL is the important bit)
//			size_t = 0; (number here doesn't make a difference since realloc is called automatically)
// NOTE: getline automatically will call malloc and/or realloc as required

int main(int argc, char** argv) {
		FILE* fp = fopen("/home/rain/linuxlearning/generalcommands.txt", "r");
		if(fp==NULL) {
				perror("Unable to open file:");
				exit(1);
		}

		// You can set buffer to null and len to 0 and getline will assign them accodingly, but better to specify parameters from the start.
		char* buffer = NULL;
		size_t len = 256;
		ssize_t check;
		// 11/6/22 STACKOVERFLOW: I asked if using getline() in a while loop is bad practice.
		// Answer I got was that it is okay to use the while loop (as man page does), HOWEVER IT WILL BE BETTER TO SPECIFY A LENGTH WHICH WILL CONTROL HOW MANY TIMES REALLOC IS CALLED, and use fwrite instead of fputs, since fwrite will output lines from a file including null bytes, whereas fputs stops at null bytes. (However, normally text files don't contain null bytes, so it isn't normally an issue)

		buffer = malloc(len*sizeof(char));
		if(buffer==NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(2);
		}
		// While loop prints the whole file, if loop will just print the first line
		while((check = getline(&buffer, &len, fp)) != -1) {
//				fputs(buffer, stdout);
				fwrite(buffer, 1, check, stdout);
		}
		printf("strlen of buffer: %ld\n", strlen(buffer));
		printf("len of buffer: %ld\n", len);
		//printf("buffer = %s\n", buffer); // This will simply print the last string that was copied to buffer...

		fclose(fp);
		free(buffer);
		buffer = NULL;

		return 0;

}

