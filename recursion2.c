#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int f(int x) {
	if(x < 0) {
		return 10;//normally 0
	}
/*Note the return value(10) above: This is what gets returned to main as 'result'. You can put any number you want, normally 0.
If you wanted the fn to return a significant figure, eg. a sum of all the recursion calls, then put x + f(x -1) below: all these figs(sum) are returned to the f caller, then when < 0 executes, 0(10) is returned to f caller, and finally the sum is returned to main caller.  */
	printf("Hello from f with x = %d\n", x);
	//return f(x - 1);
	return x + f(x - 1);
}

int main(int argc, char** argv) {
	int result = f(5);
	printf("The result of calling f is %d\n", result);	
	return 0;
}


