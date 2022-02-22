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
		printf("Fd[0] = %d fd[1] = %d\n", fd[0], fd[1]);

		printf("Writing PIN to pipe...\n");
		write(fd[1], pin, 5); // writing to fd, from pin, len=5
		printf("Done.\n\n");
// NOTE: if I changed write(fd[0] and vice versa on read(fd[1], it outputs, but not right....
// So whatever the first array member of fd is, is always read, before write??? Like stdin(0), stdout(1)
		printf("Reading PIN from pipe...\n");
		read(fd[0], buffer, 5);
		printf("Done.\n\n");

		printf("PIN from pipe: %s\n", buffer);

		return 0;
}


