#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Comparing strings char by char

int main(int argc, char** argv) {
		int SIZE = 24;
		char arr1[] = "This town isn't.";
		char arr2[SIZE];
		int len1 = strlen(arr1);

		puts("Please enter a sentence");
		// fgets
		fgets(arr2, sizeof(arr2), stdin);
		int len2 = strlen(arr2);
		if(len2 < SIZE) {
				arr2[strlen(arr2)-1] = 0;
		}
//  ***************************************************************************
/*		// getline
		char* buffer = NULL;
		size_t bufsize = 0;
		int ret;
		if((ret = getline(&buffer, &bufsize, stdin)) == -1) {
				fprintf(stderr, "getline error\n");
				return 1;
		}else{
				buffer[strcspn(buffer, "\n")] = 0;
				printf("ret = %d and buffer = %s\n", ret, buffer);
		}
*/
		int i = 0;
		printf("Comparing the two strings...letter by letter\n");
		while(arr1[i] == arr2[i] && i < len1) {
				printf("Match %c\n", arr1[i++]);
		}

//		free(buffer);

		return 0;
}

