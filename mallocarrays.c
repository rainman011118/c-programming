#include<stdio.h>
#include<stdlib.h>

//https://www.youtube.com/watch?v=NKgb4K-2C5k&list=PLCNJWVn9MJuPtPyljb-hewNfwEGES2oIW&index=11

int* create_int_array(int len, int multiplier) {
	int* x = malloc(len*sizeof(int));//assigns a block of memory of 40bytes(10*4).
	if(x == NULL) {
			fprintf(stderr, "Memory allocatin failed!\n");
			exit(1);
	}
	for(int i=0; i<len; i++) {
		x[i] = i*multiplier;//fills the array and returns it to main.
	}
	return x;
}

int main() {
		int array_len = 5;
		//Create 3 arrays and fill the contents with 10 ints:
		int* a = create_int_array(array_len, 10);
		int* b = create_int_array(array_len, 100);
		int* c = create_int_array(array_len, 1000);

		//Create memory for 3 pointers to pointers:
		int** array_pointer = malloc(3*sizeof(int*));
		if(array_pointer ==  NULL) {
			fprintf(stderr, "Memory allocatin failed!\n");
			exit(1);
		}
		//Assign the 3 arrays[10](or their address') to each of the 3 double pointers:
		array_pointer[0] = a;
		array_pointer[1] = b;
		array_pointer[2] = c;

		//Now we print out the array elements from each row.
		for(int i=0; i<3; i++) {
				for(int j=0; j<array_len; j++) {
						printf("array_pointer[%d][%d]: %d\n", i, j, array_pointer[i][j]);
				}
		}
		free(a);
		free(b);
		free(c);
		free(array_pointer);

		return 0;
}




