#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

int array[MAX];
int front = -1;
int rear = -1;
int size = -1;

void enqueue(int data) {
		if(size>=MAX) {
				printf("Queue is full, remove some items before adding to it\n");
				exit(1);
		}else if(size<0) {
				front = 0;
				rear = 0;
				size = 0;
				printf("Initialising queue: front %d, rear %d, size %d\n", front, rear, size);
				array[rear] = data;
				printf("queue[%d]: added %d\n", rear, data);
				//front++;
				rear++;
				size++;
		}else{
				array[rear] = data;
				printf("queue[%d]: added %d\n", rear, data);
				rear++;
				size++;
		}

}
void dequeue() {
		if(size<=0) {
				printf("Queue is empty, nothing to remove\n");
				exit(1);
		}
		int target = array[0];
		if(front>=rear) {
				printf("No more elements left in queue\n");
				front = -1;
				rear = -1;
				size = -1;
		}else{
				printf("queue[%d]: %d popped off\n", front, array[front]);
				front++;
				//size--;
		}
}
				
void display() {
		int i;
		if(front >= 0 && rear > 0) {
				printf("printing queue...\n");
				for(i=front;i<rear;i++) {
						printf("%d  ", array[i]);
				}
				printf("\n");
		}else{
				printf("Nothing to print...\n");
				exit(1);
		}
}

int main(int argc, char** argv) {
		enqueue(22);
		enqueue(14);
		enqueue(6);
		enqueue(89);
		enqueue(26);
		enqueue(100);
		display();
		dequeue();
		dequeue();
		dequeue();
		display();


		return 0;
}

