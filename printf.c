#include<stdio.h>


void print_it(void*) {





int main() {
		char name[] = "Captain Jack";
		puts("Let's see if we can figure out the printf function");
		print_it("my name is: %s\n", name);


		return 0;
}
