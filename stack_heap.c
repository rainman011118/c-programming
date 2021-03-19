#include <stdio.h>
//SEE MYCODESCHOOL youtube.com 'pointers and dynamic memory allocation.
int total;
int Square(int x)
{
	return x * x;
}

int SquareOfSum(int x, int y)
{
	int z = Square(x + y);
	return z;
}

int main()
{
	int a = 4, b = 8;
	total = SquareOfSum(a, b);
	printf("Output = %d\n", total);
}

/*	HEAP

	STACK

	STATIC/GLOBAL

	CODE(TEXT)

At start of process, the main() method is invoked first.
A small amount of memory is allocated.
It is put at the bottom of the stack (stackframe)
(int total is a global variable so sits outside of stack in STATIC/GLOBAL)

When the main() calls SquareOfSum method, this gets put on top of main().
SquareOfSum then calls Square which gets placed above it in the stack.

The stack is executed from the top down:
Square is called, returns, then cleared from stack.
SquareOfSum is called, returns, then cleared from stack.
main() is called, which will call printf, which gets put onto stack.
printf is called, returns, then is cleared from the stack.
main() is called, returns, then is cleared from the stack.
*/
