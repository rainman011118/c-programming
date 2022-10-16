#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv) {
		int characters;
		char* buffer = NULL;
		size_t n = 256;
		//PERHAPS IT IS BETTER TO SET THE BUFFER, SO EVERYTHING IS MEASURED.  JUST LET GETLINE FOCUS ON REALLOC()
		buffer = malloc(n*sizeof(char));
		if(buffer == NULL) {
				perror("Memory allocation failed\n");
				exit(1);
		}
		puts("Enter some shit:");
		//Can be done both ways: with a return variable to hold the number of chars (or -1) if fails. Or using the if loop to check for failure.
		if((characters = getline(&buffer, &n, stdin)) == -1) {
				printf("Error with getline\n");
				free(buffer);
				buffer = NULL;
				return 1;
		}
		//Pick either one of the below (strlen or strcspn) BOTH WILL REMOVE THE LINGERING '\n'.
//		buffer[strlen(buffer)-1] = 0;

		// returns the number of chars upto chosen selector eg '\n'
		int check = strcspn(buffer, "\n");
		printf("num of chars with strcspn(counts everything upto '\\n' which is NOT included): %d\n", check);
		
		buffer[strcspn(buffer, "\n")] = 0; // this works just like the fgets way...:)
		printf("num of chars with strcspn(after chop): %d\n", check);
		printf("Inputted buffer: %s\n", buffer);
		printf("Number of chars (which includes the '\\n'): %d\n", characters);

		free(buffer);
		buffer = NULL;

		return 0;
}
		
