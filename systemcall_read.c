#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>		// This was essential 
#include<string.h>

// ********************  SYSTEM CALLS FOR READ ADN WRITE  ***************************

int main() {
		int fd;
		char buffer[256];
		char msg[50] = "Welcome to the wizarding world!";

		fd = open("file.txt", O_RDWR);
		printf("fd = %d\n", fd);
		if(fd != -1) {
				printf("open successful\n");
				//write(fd, msg, sizeof(msg));
				//lseek(fd, 0, SEEK_SET);
				read(fd, buffer, sizeof(msg));
				printf("'%s'\t was written to my file\n", buffer);
		}
		close(fd);

		return 0;
}
//NOTE: fd should always return '3', since 0,1,2 are already taken by stdin, stdout and stderr.

