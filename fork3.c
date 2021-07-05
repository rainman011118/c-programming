#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

//https://www.youtube.com/watch?v=PZrQ4eGm-hM&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=4

int main(int argc, char** argv) {
	int id = fork();
	printf("current ID: %d, parent ID: %d\n", getpid(), getppid());
/*Technically both branches execute at the same time, so which one goes first can be random.
 */
	if(id == 0) {
		sleep(1);
	}
/*child process will sleep 1 sec, so parent process will execute first, followed by child process.
 */
	printf("current ID: %d, parent ID: %d\n", getpid(), getppid());

	return 0;

}
/*This was quite confusing overall.  Need to come back to it in the future.
 */

