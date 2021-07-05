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
		count++;
}

int removeFromQueue(int x) {
		if(count==0) {
				fprintf(stderr, "No elements to extract from queue\n");
				return -1;
		}
		int result = queue[0];
		for(int i=0;i<count-1;i++) {
				queue[i] = queue[i+1];
		}
		count--;
		return result;
}

int main(int argc, char** argv) {
			insertIntoQueue(1);
			insertIntoQueue(2);
			insertIntoQueue(3);
			insertIntoQueue(5);

			int i;
			//int localCount = count
			for(i=0;i<count;i++) {//NOTE: This count will decrement each run of the program since the function 'removeFromQueue' decrements the count each run.  As an element is removed from the queue each time, the queue gets smaller, hence why it makes sense to decrement the count.  If you don't want the count to decrement each run of the program then you can add a temporary counter and use that in the loop instead.
					//printf("%d ", queue[i]);
					printf("%d ", removeFromQueue());
			}

			return 0;

}
		
//SEE: https://www.youtube.com/watch?v=Ra6p-Bmajlw
		
