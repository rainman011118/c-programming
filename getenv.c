#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {
		char *name = argv[1];
		if(argc == 1 || argc > 2) {
				printf("Invalid input. Enter 1 env variable after a.out\n");
				exit(0);
		}else {
				printf("argc = %d\n", argc);
				printf("argv[0] = %s\n", argv[0]);
				printf("argv[1] = %s\n", argv[1]);
				printf("getenv returns: %s\n", getenv(name));
		}

		return 0;
}


//getenv returns the result of the ENV variable passed on the cmd line.
//examples of ENV variables: PATH, HOME, SHELL, SHLVL, TERM, VIM, USER.
