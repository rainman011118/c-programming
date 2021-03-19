#include <stdio.h>
#include <stdlib.h>

#define A_SIZE 5

//assigning values at runtime as opposed to statically assigning them prior to runtime.

int main() {
	int a[5];

	for(int i = 0; i < A_SIZE; i++) {
		a[i] = i*5;
	}
	for(int i = 0; i < A_SIZE; i++) {
		printf("%d\n", a[i]);
	}
	
	return 0;
}
/*DANGERS of C:
If the programmer accidentally forgets to change the index limit back to the array size, then the loop will still run, and output correctly. HOWEVER, it is now writing this to unsigned memory beyond the array size specified.
eg if I put 'i < 10' but array size is still [5], then I will get a correct output but NO ERROR is shown...
THEREFORE it is wise to use 'define' to prevent the chances of this happening.
ALTERNATIVE(modern way) is to just declare a size variable:
int a_size = 5;
int a[a_size];
*/

