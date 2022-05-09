#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// C equivalent of '.join' using isspace()

#define SIZE 32

int main(int argc, char** argv) {
		int i = 0;
		char array[SIZE];
		puts("Enter 1 word");
		fgets(array, SIZE, stdin);
		array[strcspn(array, "\n")] = 0;
		int LEN = strlen(array);

		for(i=0;i<LEN;i++) {
				//isspace checks for all white space chars(space, tab, newline etc)
				//Removing space from input (like .join in python), also ignores all digits too.
				if(isspace(array[i]) || isdigit(array[i])) {
						;
				}else {
						printf("%c", array[i]);
				}


				//Below checks for digits entered:
/*				if(isdigit(array[i])) {
						printf("[%d] %c INVALID CHAR ENTERED\n", i, array[i]);
						continue;
				}else {
						printf("[%d] %c\n", i, array[i]);
				}
	*/	}
		printf("\narray = %s\n", array);


		return 0;


}


