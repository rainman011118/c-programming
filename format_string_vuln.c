#include<stdio.h>
#include<string.h>

//SEE: formatstring vulnerabilities pdf (in vscode C folder)
// the %n parameter writes the number of bytes already printed, into a var of our choice.

int main(int argc, char** argv) {

		int i;
		printf("foobar %n\n", &i);		// %n requires 1 argument = int* (that's why &i is there)
		printf("i = %d\n", i);

		return 0;
}


