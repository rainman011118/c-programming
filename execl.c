#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

/* Substitute <unistd.h> for <process.h> if using windows to run the program. But this wouldn't compile for me (couldn't find process.h)*/

/*https://linuxhint.com/exec_linux_system_call_c/
Exec function families:
execl - PATH, PATH, parameters, NULL.
execlp - automatically includes the PATH.
execv - uses an array to group the parameters.
execvp - uses an array and automatically includes the PATH.
execle
execve
*/

int main(void) {
	int pid = fork();
	char* binaryPath = "/bin/ls";
	char* arg1 = "-lh";
	char* arg2 = "/home/rain/Testfolder";

	if(pid == -1) {
			return 1;
	}
	if(pid == 0) {
	//child process
			execl(binaryPath, binaryPath, arg1, arg2, NULL);
	} else {
	//parent process
			wait(NULL);
			printf("Parent process now executes...Success.\n");
	}

	return 0;
}

/* This below is codevault but <process.h> wouldn't work.
Also, he didn't declare a datatype for _execl...?

int main(int argc, char** argv) {
	_execl("C:\\Windows\\System32\\ping.exe", "C:\\Windows\\System32\\ping.exe", "google.com", NULL);

	printf("Ping finished executing\n");	

	return 0;

}
*/
/*The _execl() fn takes the path of the executable binary file as the first arg.  The 2nd arg is the 1st arg of the binary file: 
 arg 1 = _execl 1st arg: path to (ping.exe).
 arg 2 = 1st arg of the program ping.exe: path (ping.exe).
 arg 2a = 2nd arg of the program ping.exe: domain.
 arg 3 = NULL pointer.  The final argv to _execl has to be NULL.
*/
