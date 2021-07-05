#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void greet(const char* name) {
		printf("Bonjour %s\n", name);
}
int main(int argc, char** argv) {
		greet("Jonny");
		
		return 0;
}
/*The accepted convention of passing C-strings to functions is to use a pointer as above.  So I don't necessarily have to declare:
 * char myName[] = "Jonny";
 * greet(myname);
 * BOTH WAYS ARE ACCEPTABLE
 * By declaring 'const char* name'(which basically means Read-only memory), you allow the compiler to flag a warning if by mistake you try to change the string in some way.  Otherwise, 'char* name' will NOT flag a warning, and then will SGEFAULT at runtime!  
 * Declare 'CONST' when assigning a string literal to a pointer.  
 * If you know you will modify the string later on, then just declare it as myName[] = "Jonny".
 */
