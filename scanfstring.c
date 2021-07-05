#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv) {
/*		char* a = malloc(32 * sizeof(char));
		if(a==NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(1);
		}
*/
		char a[32];
		printf("Enter a name: ");
		fgets(a, 32, stdin);
		a[strlen(a) - 1] = 0;
		printf("The string is: %s\n", a);
		//NOTE: When you use the 'char* a', scanf will not work because memory needs to be allocated for 'a' first before scanning a string literal to it.

//		free(a);	
	
		return 0;
}


