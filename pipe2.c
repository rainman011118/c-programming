#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

//https://linuxhint.com/pipe_system_call_c/

int main(void) {
		int fd[2];
		char buffer[5];

		if(pipe(fd) == -1) {
				perror("pipe");
				return 1;
		}

		char *pin = "5678\0";

		printf("Writing PIN to pipe...\n");
		write(fd[1], pin, 5);
		printf("Done.\n\n");

		printf("Reading PIN from pipe...\n");
		read(fd[0], buffer, 5);
		printf("Done.\n\n");

		printf("PIN from pipe: %s\n", buffer);

		return 0;
}


