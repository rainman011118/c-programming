#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//getline() is considered more favourable to use...over fgets() (although very similar).  Apparently it uses realloc() automatically if required....??  TESTED...And yes, it automatically adjusts it.
//Also, some say that the reason more ppl use fgets() is due to the fact that they are not comfortable with using pointers....

int main(int argc, char** argv) {
		char* buffer = NULL;
		size_t size = 32;
		size_t characters = 0;

		buffer = malloc(size*sizeof(char));
		if(buffer==NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(1);
		}
		printf("Type something here:\n");
		//getline() returns the number of chars read or -1 if failed or EOF
		characters = getline(&buffer, &size, stdin);
		//When the string is printed it, '\n' char is also read, (just like in fgets) so use same below method to remove it..
		buffer[strlen(buffer)-1] = 0;
		printf("%zu characters were read.\n", characters);
		printf("You typed: '%s'\n", buffer);

		free(buffer);

		return 0;
}

