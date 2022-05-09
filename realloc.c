#include<stdio.h>
#include<stdlib.h>

int main() {
		int a_size = 10;
		int* a = malloc(a_size*sizeof(int));
		if(a==NULL) {
			fprintf(stderr, "Error allocating memory!\n");
			exit(1);
		}
		for(int i = 0; i < a_size; i++) {
			a[i] = i*10;
			printf("%d ", a[i]);
		}
		printf("\n");

		// Setting up realloc using tmp pointer
		int *tmp = NULL;
		int new_a_size = a_size*2;
		printf("Reallocating a!\n");
		tmp = realloc(a, new_a_size*sizeof(int));
		//If realloc is successful, it copies data then automatically frees original memory pointed to by a.
		if(tmp==NULL) {
				fprintf(stderr, "Error reallocating memory...freeing a\n");
				free(a);
				a = NULL;
				exit(1);
		}
		printf("Done.\n");
		a = tmp;
		tmp == NULL;
		for(int i = 0; i < new_a_size; i++) {
				printf("%d ", a[i]);
		}
		printf("\n");

		free(a);
		return 0;
}	
