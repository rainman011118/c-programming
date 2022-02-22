#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"sort.h" //include the header for the external functions....

/*REMEMBER TO COMPILE with the object files: (if the object files aren't there, compile them first with:
	gcc -c sort_functions.c
Then:
	gcc external_header2.c sort_functions.o -o whatever
*/

int* make_array(int size);

int main(int argc, char** argv) {
		srand((unsigned)time(NULL));
		int r;
		int SIZE = 10;		
		int* array = make_array(SIZE);
		for(int i=0;i<SIZE;i++) {
				r = rand() % 100;
				array[i] = r;
				printf("%d ", array[i]);
		}
		printf("\n");

		sort_ascending(array, SIZE);

		for(int i=0;i<SIZE;i++) {
				printf("%d ", array[i]);
		}
		printf("\n");

		return 0;

}
int* make_array(int size) {
		int* x = malloc(size * sizeof(int));
		if(x==NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(1);
		}
		return x;
}

