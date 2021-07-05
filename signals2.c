#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>
#include<unistd.h>

int x = 0;

void handle_sigusr1(int sig) {
		if(x == 0) {
		printf("\n(HINT) Remember that multiplication is repetitive addition!\n"); 
		}
}

int main(int argc, char** argv) {
	int pid = fork();
	if(pid == -1) {
			return 1;
	}
//https://www.youtube.com/watch?v=PErrlOx3LYE

	if (pid == 0) {
			//child process
			sleep(5);
			kill(getppid(), SIGUSR1);
			//ppid targets parent.  Many signals to choose from. SIGUSR1 is a user-defined one. But this signal must be 'handled' by us = defined. Hence the struct below and the void handle_sigusr1().
	} else {
			struct sigaction sa = {0};//makes sure all members of the struct have been initialized to 0.
			sa.sa_flags = SA_RESTART;//to do with scanf
			sa.sa_handler = &handle_sigusr1;
			sigaction(SIGUSR1, &sa, NULL);//This calls the sigaction fn and binds the signal(sigusr1) to the struct sa.

			//parent process
			printf("What is the result of 3 x 5: ");
			scanf("%d", &x);
			if(x == 15) {
					printf("Right!\n");
			} else {
					printf("Wrong!\n");
			}
			wait(NULL);
	}
	return 0;
}

