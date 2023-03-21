#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Use of either getline() or fgets().  Both work, and can get rid of the lingering '\n' with either strlen or strcspn
//Personal opinion: getline may be better since use of malloc allows for flexible input.
// NOTE: MAN PAGES SAY THAT GETLINE BUFFER SHOULD BE FREED, EVEN IF IT FAILS...

int main(int argc, char** argv) {
		int len = 32;
		char array[len];

		char* buffer = NULL;
		size_t len2 = 0;
		ssize_t characters;
		puts("Enter some text");

		if((characters = getline(&buffer, &len2, stdin)) == -1) {
				fprintf(stderr, "Error with getline\n");
				free(buffer);
				buffer = NULL;
				return 1;
		}
		printf("Number of chars read: %d\n", characters);
		buffer[strcspn(buffer, "\n")] = 0;
		printf("data read: %s\n", buffer);

/*		fgets(array, len, stdin);
		array[strlen(array)-1] = 0;
		printf("data read: %s\n", array);
*/
		free(buffer);
		buffer = NULL;

		return 0;
}


