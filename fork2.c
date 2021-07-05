#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

//https://www.youtube.com/watch?v=tcYo6hipaSA&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=2

int main(int argc, char** argv) {
	int id = fork();
	int n;
	if(id == 0) {
		n = 1;
	} else {
		n = 6;
	}
	
	if(id != 0) {
		wait(NULL);//Why isn't this working???? - Because NULL has to be input as the argument...found this in the comments!!!
	}

	//This wait process will cause main to pause, until child(0) completes. i.e. 12345\n678910.

	int i;
	for(i = n; i < n + 5; i++) {
		printf("%d ", i);
//		fflush(stdout);
	}
	printf("\n");

	return 0;

}

/*The loop will print both processes main and child.  fflush(stdout) is used to clear the printf buffer otherwise printf will store all the info (from both branches, child and parent) and print it all at once = parallel. Instead we want it to print out all the elements from one branch, followed by all the elements from the other. Then we can distinguish between which output is from main and which is from child.
 Without use of fflush, you will simply get output from main, then new lline, then output from child: 
678910
12345
*/

