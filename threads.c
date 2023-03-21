#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

//NOTE: When compiled, you must put: gcc threads.c -lpthread (otherwise it will not compile)

void* routine() {//NOTE: This is a function pointer
		printf("Test from threads...\n");
		sleep(3);//This sleep is just to prove that both the threads are going through...
		printf("Ending threads...\n");
}

//We use if statements since pthreads return an int (1 = fail, 0 = successful)
int main(int argc, char** argv) {
		pthread_t t1, t2;
		if(pthread_create(&t1, NULL, &routine, NULL) != 0) {
				return 1;
		}
		if(pthread_create(&t2, NULL, &routine, NULL) != 0) {
				return 2;
		}
		if(pthread_join(t1, NULL) != 0) {
				return 3;
		}		
		if(pthread_join(t2, NULL) != 0) {
				return 4;
		}		

		return 0;

}
