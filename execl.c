#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

/*https://linuxhint.com/exec_linux_system_call_c/
Exec function families:
execl - PATH, PATH, parameters, NULL.
execlp - automatically includes the PATH.
execle
execv - uses an array to group the parameters. *****MOST COMMONLY USED **********
execve -										****** MOST COMMONLY USED *******
execvp - uses an array and automatically includes the PATH.
*/

int main(void) {
	int pid = fork();
	char* binaryPath = "/bin/ls";
	char* arg1 = "-lh";
	char* arg2 = "/home/rain/Testfolder";//the target you want the command to act upon

	//EXECV ARGS = PATH/PROGRAM, ARRAY OF STRINGS
	char* shell = "//bin/sh";
	char* shellargs[] = {shell, NULL};

	if(pid == -1) {
			return 1;
	}
	if(pid == 0) {
	//child process
			execl(binaryPath, binaryPath, arg1, arg2, NULL);
	} else {
	//parent process
			wait(NULL);
			printf("Parent process now executes this shell....\n");
			execv(shell, shellargs);
			printf("If you read this then the shell didn't execute :(\n");
	}

	return 0;
}

/*The _execl() fn takes the path of the executable binary file as the first arg.  The 2nd arg is the 1st arg of the binary file: 
 arg 1 = _execl 1st arg: path to (ping.exe).
 arg 2 = 1st arg of the program ping.exe: path (ping.exe).
 arg 2a = 2nd arg of the program ping.exe: domain.
 arg 3 = NULL pointer.  The final argv to _execl has to be NULL.
*/
