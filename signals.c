#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

//https://www.youtube.com/watch?v=jF-1eFhyz1U

void handle_sigtstp(int sig) {
		printf("Stop not allowed\n");
}

void handle_sigcont(int sig) {
		printf("Input number: ");
		fflush(stdout);
//This allows for 'input number' to be printed when returning to complete the program with 'fg'
}

int main(int argc, char** argv) {
	struct sigaction sa;
	sa.sa_flags = SA_RESTART;
	//sa.sa_handler = &handle_sigtstp;
//	sigaction(SIGTSTP, &sa, NULL);//This is the bit that prevents the program from being backgrounded.
	sa.sa_handler = &handle_sigcont;
	sigaction(SIGCONT, &sa, NULL);


//	signal(SIGTSTP, &handle_sigtstp);//alternative way BUT man pages say that sigaction should be used instead, for portability..


	int x;
	printf("Input number: ");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x, x * 5);

		return 0;
}

