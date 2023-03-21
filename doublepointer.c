#include<stdio.h>
#include<stdlib.h>

//DOUBLE POINTER METHOD: this is generally more efficient (no return needed)
void allocate(int** x) {
		*x = malloc(sizeof(int));
		if(x==NULL) {
				fprintf(stderr, "memory allocation failed\n");
				exit(1);
		}
		**x = 1;
}
//SINGLE POINTER METHOD: 
int* allocate2(int* x) {
		x = malloc(sizeof(int));
		if(x==NULL) {
				fprintf(stderr, "memory allocation failed\n");
				exit(1);
		}
		*x = 3;
		return x;
}
int main(int argc, char** argv) {
		int* p = NULL;
		allocate(&p);
		printf("Value p immediately after func call = %d\n", *p);
		*p = 2;
		printf("Value p when reassigned in main = %d\n", *p);
//#######################################################################
		int* p2 = allocate2(p2);
		printf("Value p2 when changed in external func = %d\n", *p2);
		*p2 = 4;
		printf("Value p2 when reassigned in main = %d\n", *p2);

		free(p);
		free(p2);

		return 0;

}

//Overall the only real difference is that it saves 1 step (ie the return from the function)
