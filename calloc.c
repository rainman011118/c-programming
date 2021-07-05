#include<stdio.h>
#include<stdlib.h>

int* arr;
size_t arrSize = 256;

int main(int argc, char** argv) {
	//arr = calloc(256, sizeof(int));//This is fine but below is safer due to global declaration.
	arr = calloc(arrSize, sizeof(int));
	if(arr == NULL) {
			fprintf(stderr, "arr not allocated!\n");
			exit(1);
	}
	arr[10] = 17;
	printf("%d\n", arr[10]);
	
	arrSize *= 2;
	int* arr2 = NULL;
	arr2 = realloc(arr, arrSize * sizeof(int));
	/*The above reallocates more memory for the change in size specified (* 2).
	*/
	if(arr2== NULL) {
			fprintf(stderr, "arr not reallocated!\n");
			exit(2);
	}
	arr = arr2;

	free(arr);

	return 0;
}

/*NOTE that calloc is used instead of malloc since with arrays, you generally want all the elements initialized to 0 beforehand.  (Malloc doesn't do this...?)
SEE: 'how to use dynamically allocated arrays' codevault.*/





