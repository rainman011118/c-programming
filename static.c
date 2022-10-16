#include<stdio.h>

//Understanding the use of the static variable.

static int x; //As a global variable, static means x is only visible to this file.

void print_num(void) {
		static int y = 0;	//Inside a function, static means that y retains its value even outside of the function. Hence why, on subsequent calls to print_num(), y is NOT reset to 0 each time.
		printf("%d\n", y);
		y = y + 1;
}


int main(int argc, char** argv) {
		print_num();
		print_num();
		print_num();

		return 0;
}
