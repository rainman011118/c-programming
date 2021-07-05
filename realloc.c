#include<stdio.h>
#include<stdlib.h>

int main() {
		int a_size = 10;
		int* a = malloc(a_size*sizeof(int));
		if(a==NULL) {
			fprintf(stderr, "Error allocating memory!\n");
			exit(1);
		}
		//create and print an array from the block of memory:
		for(int i = 0; i < a_size; i++) {
			a[i] = i*10;
			printf("a[%d]: %d\n", i, a[i]);
		}
		int *tmp = NULL;
		int new_a_size = 0;
		new_a_size = a_size*2;

		//Increase the amount of memory required::	
		printf("Reallocating a!\n");
		tmp = realloc(a, new_a_size*sizeof(int));

		/*Why create a new (tmp) variable for realloc, instead of just reallocating a directly: a = realloc...?
Answer: https://stackoverflow.com/questions/28054407/realloc-an-array-of-pointers-is-doing-nothing
 Looks like, creating a new variable/pointer is the correct way. To do with the problem which may occur if you directly reallocate a; you may lose the original pointer to a, and not be able to free it later. If realloc fails it returns NULL. So if you directly relalloc'd a, then a would be overwritten with NULL and the original data lost. Hence why the below syntax is recommended:https://stackoverflow.com/questions/9142805/do-we-lose-data-in-a-buffer-after-reallocing#:~:text=A%20realloc%20that%20increases%20the,copied%20to%20the%20new%20block.&text=Note%20that%20your%20call%20to,some%20reason%20the%20realloc%20fails.
*/
		if(tmp==NULL) {
				fprintf(stderr, "Error allocating memory!\n");
				exit(1);
		}
		printf("Done.\n");

		//Assign this extra memory to a
		a = tmp;

		//and print out the old and the new (empty) elements:
		for(int i = 0; i < new_a_size; i++) {
				printf("a[%d]: %d\n", i, a[i]);
		}
		free(a);

		return 0;
}	

/*I believe, realloc automatically frees the source if it has to pick another part of memory to use.  Otherwise, it just extends the source with the extra memory.*/
