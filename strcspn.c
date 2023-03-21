#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//strcspn stands for 'string character span'   It returns the number of bytes
//it basically checks for the "string character" (2nd arg) in the buffer(1st arg). NOTE: the string char must be in double quotes.

int main(int argc, char** argv) {
		char name[32];
		puts("Enter your name:");
		fgets(name, sizeof(name), stdin);

//		int nobytes = strcspn(name, "\n");
//		printf("No of bytes: %d\n", nobytes);
		//This is the alternative to the similar: name[strlen(name)-1] = 0.  Using strcspn is considered slightly better becuase it can account for the rare times a buffer starts with '\0'.
		name[strcspn(name, "\n")] = 0;
		printf("Your name is: %s\n", name);

		return 0;

}

		
