#include<stdio.h>
#include<string.h>

//SEE: formatstring vulnerabilities pdf (in vscode C folder)
// the %n parameter writes the number of bytes already printed, into a var of our choice.

int main(int argc, char** argv) {
		int i;
		printf("foobar%n\n", &i);		// %n requires 1 argument = int* (that's why &i is there)
		
		printf("foobar%n%08x %08x %08x %08x %08x %08x %08x\n", &i);		// The %x's create a warning on the compiler, but will still run, and then leaks the data from the stack. (%p's give (nil), and %s's give segfault)
		printf("i = %d\n", i);
		
/* ##################################################################
// This below has '%n' after the %08x's, so it should print '7' or '14'(spaces included) (since there are 7 %08x's) to the stack at address 'foobar' Now since 'foobar' is not a valid address, it will segfault. BUT, if I input a valid address on the stack, then '7' should be printed to it on the stack.			
*/
		printf("foobar%08x %08x %08x %08x %08x %08x %08x %n\n", &i);		// The %x's create a warning on the compiler, but will still run, and then leaks the data from the stack. (%p's give (nil), and %s's give segfault)
		printf("i = %d\n", i);

				printf("foobardoobar%n%08x %08x %08x %08x %08x %08x %08x %08x %08x %08x %08x %08x %08x %08x %08x %08x\n", &i);	// NOTE: when this is printed AFTER the call to i, the leaked values are 0 0 0 6?? So, this must be the clean up following a call to printf...NOT SURE ABOUT THIS...

		return 0;
}


//The final one printed out the values on the stack BUT it was at strange intervals: 4 bytes, then skip 4 bytes. It didn't print the full 8 bytes or continuous bytes...?? eg when it got to the stack canary value, which is -8 from the rbp, it printed the 4bytes, but skipped the next 4bytes (-4(rbp))....Not sure what is happening there...

