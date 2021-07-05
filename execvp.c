#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//execvp - uses the NULL terminated array and includes the PATH. 

int main(void) {
	char* programName = "ls";
	char* args[] = {programName, "-la", "/home/rain/Testfolder", NULL};
	execvp(programName, args); 

	return 0;
}
