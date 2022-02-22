#include<stdio.h>
#include<stdlib.h>

typedef int (*pair_function)(int, int);
/*	Any 'int<fn_name>(int, int)' is targeted for typedef.  
 *	If it doesn't return an int, it will not work.
 *	If it doesn't take 2 x int args, it will not work.
 *	This allows us to pass the 'pair_function(int, int)' and then specify which type when we pass the arg in main. e.g. add, sub etc.
*/
int add(int a, int b) {
		return a+b;
}
int sub(int a, int b) {
		return a-b;
}
int mul(int a, int b) {
		return a*b;
}
void blend(int *a, int *b, int len, pair_function f) {
		for(int i=0; i<len; i++) {
				printf("%d: %d\n", i, f(a[i], b[i]));
		}
}
int main() {
		int a[] = {1,2,3,4,5};
		int b[] = {5,6,7,8,9};

		printf("add:\n");
		blend(a,b,5,add);
		printf("sub:\n");
		blend(a,b,5,sub);
		printf("mul:\n");
		blend(a,b,5,mul);

		return 0;
}

//https://www.youtube.com/watch?v=g1N_ttH0FQE
/*If your create another function that takes doubles, then it will not work since int pair_function(int, int) expects int x 2 args and returns an int, not double. */
