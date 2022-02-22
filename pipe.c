#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//https://linuxhint.com/pipe_system_call_c/

int main(void) {
		int fd[2];
		if(pipe(fd) == -1) {
				perror("pipe");
				exit(EXIT_FAILURE);
		}

		printf("Read File Descriptor Value: %d\n", fd[0]);
		printf("Write File Descriptor Value: %d\n", fd[1]);
/*The program will return 3 and 4.  This is because 0, 1, 2 are already taken by stdin, stdout, stderr. If you open other files, 5, 6, 7 etc.  But if you close files, the respective numbers can be used by another.

https://unix.stackexchange.com/questions/176324/what-and-why-file-descriptors
*/
		return EXIT_SUCCESS;
}

