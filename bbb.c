#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct stack {
		int data;
		struct stack* next;
};

int top = -1;
struct stack* create_stack(struct stack** head, int data) {
		struct stack* node = malloc(sizeof(struct stack));
		if(node==NULL) {
				fprintf(stderr, "memory allocation failed\n");
				exit(1);
		}
		++top;
		node->data = data;
		node->next = NULL;
		*head = node;
		return node;
}


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
/*
void peek() {
		if(top==-1) {
				printf("Nothing on the stack\n");
		}else{
				printf("%d\n", stack[top]);
		}
}
int pop() {
		int data;
		if(!isempty()) {
				data = stack[top--];
//				printf("popped %d\n", data);
				return data;
		}else{
				return 0;
		}
}
*/
// Confusing myself with all of this linked lists and stacks.....
void push(struct stack** node, int data) {
		struct stack* SP = NULL;
		if(*node == NULL) {
				*node = create_stack(*node, data);
				SP = (*node)->next;
		}
		if(isfull()) {
				printf("No more room on stack\n");
				return;
		}else{
				while(*node != NULL) {
						*node = (*node)->next;
				}
				*node = create_stack(node, data);
				
				printf("%d pushed to stack (top: %d)\n", data, top);
		}
}	
void print_stack(struct stack* node) {
		while(node) {
				printf("%d\n", node->data);
				node = node->next;
		}
}
void free_stack(struct stack* BP) {
		struct stack* tmp = NULL;
		while(BP != NULL) {
				tmp = BP;
				BP = BP->next;
				free(tmp);
				tmp = NULL;
				printf("node freed\n");
		}
}

int main(int argc, char** argv) {
		struct stack* BP = NULL;
		print_stack(BP);
		push(&BP, 100);
		push(&BP, 50);
		push(&BP, 25);

		print_stack(BP);
		free_stack(BP);

		return 0;

}

