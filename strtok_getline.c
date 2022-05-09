#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//USING STRTOK TO BREAK A LINE INTO ITS INDIVIDUAL COMPONENTS
//THEN USING GETLINE TO TAKE INPUT AND THEN STRTOK TO PARSE

int main(int argc, char** argv) {
		int i;
		char array[] = "john_smith@hotmail.com, janedoe@yahoo.com, misterbig@gmail.com, carrieann@aol.com, jonny777@hotmail.co.uk, funny_bunny@hotmail.com, tennisdragon@gmail.com, isawthedevil@outlook.com";
		printf("%s\n", array);

		char* name = strtok(array, "@");
		printf("pointer points to everything before the delimeter '@' = %s\n", name);
		puts("Splitting up the emails to separate the names....");

	// THINK OF STRTOK LIKE THIS: 'READ EVERYTHING UP TO THE DELIMITER'/READ EVERYTHING, IGNORING ALL DELIMITERS'
		while(name != NULL) {
				printf("%s\n", name);
				name = strtok(NULL, " ");// This bit stores everything after '@ to the space'.
				name = strtok(NULL, "@");// From the space to the next '@'.
				//IS THERE A WAY TO JUST SKIP THE MIDDLE BIT....?
		}

//##########################################################################################
//TRYING NOW WITH TAKING INPUT, THEN SPLITTING/PARSING THE EMAILS.....
		char* emails = malloc(256*sizeof(char));
		if(emails==NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(1);
		}
		size_t len = 0;
		ssize_t check;
		puts("Lets try entering some emails manually and using getline, then strtok");
		if((check = getline(&emails, &len, stdin)) == -1) {
				fprintf(stderr, "getline failed\n");
				exit(2);
		}
		emails[strcspn(emails, "\n")] = 0;
		printf("emails: %s\n", emails);
		printf("total no. of chars = %ld\n", check);

// NOW TO SPLIT THE INPUTTED EMAILS UP.....
		puts("Now to try and split these strings up....");
		char* ptr = strtok(emails, "@");
		while(ptr != NULL) {
				printf("%s\n", ptr);
				ptr = strtok(NULL, " ");
				ptr = strtok(NULL, "@");
				//IS THERE A WAY TO JUST SKIP THE MIDDLE BIT....?
		}

		free(emails);
		emails = NULL;

		return 0;
}
