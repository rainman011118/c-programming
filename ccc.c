#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv) {
		int SIZE = 32;
		char* A = malloc(SIZE*sizeof(char));
		if(A==NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(1);
		}
		const char* B = "Captain America";
		char C[] = "Incredible Hulk";
		puts("Enter your hero name:");
		fgets(A, SIZE, stdin);
		A[strlen(A)-1] = 0;

		printf("A malloc = %s\n", A);
		printf("const char* B = %s\n", B);
		A[0] = 'Z';
		printf("A = %s\n", A);
		printf("C array = %s\n", C);
		C[0] = 'Q';
		printf("C array= %s\n", C);
		free(A);


		puts("Lets try using getline");
		char* buffer = malloc(64*sizeof(char));
		if(buffer==NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(2);
		}
		size_t len = sizeof(buffer);
		int characters;
		FILE* fp = fopen("/home/rain/cfolder/file.txt", "r");
		if(fp==NULL) {
				perror("Error: ");
				exit(1);
		}
		if((characters = getline(&buffer, &len, fp))==-1) {
				perror("Error: ");
				exit(3);
		}else{
				printf("characters = %d\n", characters);
				printf("Buffer = %s\n", buffer);
		}

		fclose(fp);
		free(buffer);
		return 0;
}
