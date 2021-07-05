#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

//https://www.youtube.com/watch?v=cex9XrZCU14&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY

int main(int argc, char **argv) {
	//fork();
	//printf("Hello World!\n");
	
	int id = fork();
	printf("Hello from process id: %d\n", id);
	//This will show 2 different numbers: random no. for main, and 0 for child.  Child process is always 0.

	if (id == 0) {
		printf("This is the child process\n");
	} else {
		printf("This is the parent process\n");
	}
/*This loop will print both statements as they are both true since there is a main process and a child process.
 */
	return 0;

/*fork creates a new branch off the main execution path, so 'hello world' will be printed twice: - main process and child process.
Each fork() created creates 2**n processes/branches. 
*/



}

