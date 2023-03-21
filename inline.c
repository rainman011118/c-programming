#include<stdio.h>


int main(int argc, char* argv[]) {
		__asm__("movl $10, %eax;"
						"movl $20, %ebx;"
						"addl %ebx, %eax;");
		

		return 7;
}
