#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

//execv - You can pass all the parameters inside a NULL terminated array rather than one-by-one.

int main(void) {

		//spawn a shell
	char* binaryPath = "//bin/sh";
	char* args[] = {binaryPath, NULL}; //Must be NULL terminated, otherwise, it compiles but goes straight to print function below.
//	printf("sizeof(binaryPath) = %ld\nsizeof(args) = %ld\n", sizeof(binaryPath), sizeof(args));

		//Just checking some stuff..
/*	char* ptr = binaryPath;
	int len = strlen(binaryPath);
	printf("len = %d\n", len);
	int i = 0;
	// This prints out the hexadecimal values
	while(i<len) {
			printf("%x ", *ptr++);			// '%#x' adds '0x' before the value (Not good in this instance since every char gets it). alternative is %hhx.
			i++;
	}
	printf("\n");
*/
/*		//list Testfolder directory	
	char* binaryPath = "/bin/ls";
	char* args[] = {binaryPath, "-la", "/home/rain/Testfolder", NULL}; //Must be NULL terminated, otherwise, it compiles but goes straight to print function below.

*/
	execv(binaryPath, args); 
	printf("if you are seeing this, execv didn't work\n");
	/*This printf will not execute because execv family overrides the c program with whatever program it is executing (-ls).
	 The way around this is to add 'fork()'.
	 */

	return 0;
}

