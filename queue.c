#include<stdio.h>
#include<stdlib.h>

int queue[256];//An array but will be used as the queue with certain funcs.
int count = 0;

void insertIntoQueue(int x) {
		if(count==256) {
				fprintf(stderr, "no more space in the queue\n");
				return;
		}
		queue[count] = x;
		printf("%d added to queue\n", x);
		count++;									//  **********  follows what is added to queue  *****************
}

int removeFromQueue() {
		if(count==0) {
				fprintf(stderr, "No elements to extract from queue\n");
				return -1;
		}
		int result = queue[0];			// pops first item from queue
		for(int i=0;i<count-1;i++) {
				queue[i] = queue[i+1];	// moves 2nd item in queue to front
		}
		count--;									//  **********  follows what is removed from queue ***************
		return result;					// returns the item that was popped off front
}

int main(int argc, char** argv) {
		insertIntoQueue(1);
		insertIntoQueue(2);
		insertIntoQueue(3);
		insertIntoQueue(4);
		insertIntoQueue(5);

		int i, ret;
		int len = sizeof(queue) / sizeof(queue[0]);
		for(i=0;i<len;i++) {
				if((ret = removeFromQueue()) == -1) {
						break;
				}else{printf("Popped [%d]\n", ret);}
		}
		return 0;
}
		
//SEE: https://www.youtube.com/watch?v=Ra6p-Bmajlw
		
