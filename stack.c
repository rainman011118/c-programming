#include<stdio.h>
#include<stdlib.h>
#define MAX 8

int stack[MAX];
int top = -1;

int peek() {
		return stack[top];
}

int isempty() {
		if(top==-1) {
				return 1;
		}else{
				return 0;
		}
}
int isfull() {
		if(top==MAX-1) {
				return 1;
		}else{
				return 0;
		}
}

void push(int data) {
		if(!isfull()) {
				++top;
				stack[top] = data;
		}else{
				printf("Could not insert data, stack is full\n");
		}
}
int pop() {
		if(!isempty()) {
				return stack[top--];
		}else{
				printf("No items on the stack to be popped\n");
		}
}

int main(int argc, char** argv) {
		push(1);push(2);push(3);push(4);push(5);push(6);push(7);push(8);push(9);push(10);
		printf("Is stack full: %s\n", isfull() ? "yes" : "no");
		printf("top of stack = %d\n", peek());
		printf("top = %d\n", top);
		int one = pop();
		int two = pop();
		printf("one = %d, two = %d\n", one, two);
		while(!isempty()) {
				int data = pop();
				printf("%d\n", data);
		}
		printf("Is stack empty: %s\n", isempty() ? "yes" : "no");

		return 0;
}

