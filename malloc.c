#include<stdio.h>
#include<stdlib.h>

/*The reason malloc/calloc is used is when you don't know the exact size of the array elements required, therefore call to memory can dynamically allocate it at runtime.  If you know the size of the array, then just declare it: arr[256]. So malloc/calloc isn't required.
 */

int main(int argc, char** argv) {
		int* ptr = malloc(sizeof(int));
		if(ptr == NULL) {
				fprintf(stderr, "Memory allocation failed!\n");
				exit(1);
		}
		*ptr = 5;
		printf("The value of *ptr is: %d\n", *ptr);
		free(ptr);	
//#######################################################
		int p_size = 3;
		int* p = malloc(p_size * sizeof(int));
		if(p == NULL) {
				fprintf(stderr, "Memory allocation failed!\n");
				exit(1);
		}
		p[1] = 4;
		p[2] = 6;
		printf("p[1]: %d\np[2]: %d\np[0]: %d\n", p[1], p[2], p[0]);
		
		free(p);

		return 0;
}





