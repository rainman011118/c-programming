#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//execv - You can pass all the parameters inside a NULL terminated array rather than one-by-one.

int main(void) {
	char* binaryPath = "/bin/ls";
	char* args[] = {binaryPath, "-la", "/home/rain/Testfolder", NULL};

	execv(binaryPath, args); 
	
	printf("Hello from int main!\n");
	/*This printf will not execute because execv family overrides the c program with whatever program it is executing (-ls).
	 The way around this is to add 'fork()'.
	 */
	return 0;
}

