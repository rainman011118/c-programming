#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>


// Am I really converting something...? I'm just printing out hex using printf...

int main(int argc, char** argv) {
		int characters, i = 0;
		size_t SIZE = 256;
		
		char* p = malloc(SIZE*sizeof(char));
		if(p==NULL) {
				perror("Memory allocation failed: ");
				exit(1);
		}
		if((characters = getline(&p, &SIZE, stdin)) != -1) {
				printf("Number of characters read: %d\n", characters);
				p[strcspn(p, "\n")] = 0;
				printf("%s\n", p);
				//printf("\\x%x\n", *p);
				puts("Now converting the string to hex...");
				while(i<characters-1) {
						printf("\\x%x", p[i++]);
				}
				printf("\n");
		}

		free(p);
		p = NULL;

		return 0;
}
