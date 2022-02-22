#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

//https://www.youtube.com/watch?v=PZrQ4eGm-hM&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=4

int main(int argc, char** argv) {
	int id = fork();
	printf("line 1: id: %d, current ID: %d, parent ID: %d\n", id, getpid(), getppid());
//Technically both branches execute at the same time, so which one goes first can be random.

	if(id != 0) {
		wait(NULL);
//		sleep(1);//This causes the final delayed output to be output after prompt...(if I use wait(NULL), it all completes before prompt as expected.
	}
	printf("LINE 2: id: %d, CURRENT ID: %d, PARENT ID: %d\n", id, getpid(), getppid());

	return 0;

}
/*This was quite confusing overall.  Need to come back to it in the future.
 * IF I SET IF STATEMENT TO IF(ID == 0), THE FOLLOWING OCCURS: At the very end, the PARENT ID: 1  This is simply because the parent process has already terminated and so it is given the value '1' but the init process.  Otherwise it would have the same value from earlier when the parent process was running. See man getpid.
 * The order of things:
 * line1 executes (PARENT)
 *  - id != 0 which means PARENT pauses....
 *  child starts, line1 executes.
 *  child process continues and LINE 2 executes (CHILD)
 *  child process ends.
 *  parent process resumes
 *  line2 executes (PARENT)
 */

