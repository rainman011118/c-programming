#include<stdio.h>
#include<stdlib.h>
#define MAX 10


char stack[10];
int top = -1;

int isempty() {
		if(top==-1) {
				return 1;
		}else{
				return 0;
		}
}
int isfull() {
		if(top>=MAX-1) {
				return 1;
		}else{
				return 0;
		}
}
void peek() {
		if(top==-1) {
				printf("Nothing on the stack\n");
		}else{
				printf("%d\n", stack[top]);
		}
}
int pop() {
		//int data;
		if(!isempty()) {
				//data = stack[top--];
				printf("pop(%d)\n", stack[top--]);
				//return data;
		}
}

void push(int data) {
		if(isfull()) {
				printf("No more room on stack\n");
				return;
		}else{
				++top;
				stack[top] = data;
				printf("%d pushed to stack (top: %d)\n", data, top);
		}
}	
void clearstack(char* stack, int size) {
		int i = 0;
		while(top > -1) {
				pop();
		}
}
void print_stack(char* stack, int sizetop) {
		int i = sizetop;
		while(i < MAX && i >- 1) {
				printf("%d ", stack[i]);
				i--;
		}
		printf("\n");
}

int main(int argc, char** argv) {
		/*int MAX = MAX;
		char* stack = malloc(MAX*sizeof(char));
		if(stack==NULL) {
				fprintf(stderr, "memory allocation failed\n");
				exit(1);
		}
		for(int i=0;i<MAX;i++) {
				stack[i] = rand() % 10;
		}
*/
		print_stack(stack, MAX);
		printf("Top = %d\n", top);
		push(100);
		push(50);
		push(25);
		push(7);
		push(1);
		pop();
		pop();
		peek(stack);
		push(8);
		push(9);
		push(10);
		push(11);
		push(12);
		push(13);
		push(14);
		push(15);
		print_stack(stack, top);
		printf("Top = %d\n", top);
		printf("Clearing stack\n");
		clearstack(stack, MAX);
		printf("Top = %d\n", top);

		return 0;

}

