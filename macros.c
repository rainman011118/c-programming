#include <stdio.h>
#include <stdlib.h>

#define PRINT_VAR(X) printf(#X " is %d at addr %p\n", X, &X);

/* 2 Parts to this above.
1) Passing X and &X is straight forward.  This is the macro's purpose.
2) #X is optionl.  It is like the {} in python.
*/

int main(int argc, char **argv)
{
	int a = 3;
	PRINT_VAR(a);
	return 0;
}
