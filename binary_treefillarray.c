#include<stdio.h>
#include<stdlib.h>

#define LIMIT 10

// ***  Almost got the tree_stack working.....just need to fix the global pointer issue (see line: 77 and 96...are they incrementing the GLOBAL right and left too???

struct node{
		int data;
		struct node* left;
		struct node* right;
};

char stack[LIMIT];
int top = -1;
char tree_stack[LIMIT];
char* RIGHT = tree_stack;
char* LEFT = tree_stack;

//  **************************  Stack functions  ******************************
void peek() {
		if(top != -1) {
				printf("top of stack: %d\n", stack[top]);
		}else{
				printf("peek: stack is empty\n");
		}
}
int isfull() {
		if(top==LIMIT) {
				return 1;
		}else{
				return 0;
		}
}
int isempty() {
		if(top==-1) {
				return 1;
		}else{
				return 0;
		}
}
int pop() {
		if(!isempty()) {
				return stack[top--];
		}else{
				printf("Nothing on the stack to pop\n");
		}
}

void push(int data) {
		if(!isfull()) {
				++top;
				stack[top] = data;
		}else{
				printf("Stack is full\n");
		}
}
void clear_stack(char* stack) {
		while(!isempty()) {
				printf("clearing stack...\n");
				stack[top--] = 0;
		}
		printf("stack cleared..\n");
}

//  *************  tree in the stack form  *************************
void check_right(char* right, int data, char* limit) {
		printf("Checking right with %d\n", data);
		int tmp;
		if(right != limit) {
				if(*right != 0) {
						if(data > *right) {
								check_right(++right, data, limit);
						}else{
								printf("right....inside loop\n");
								tmp = *right;
								*right = data;
								*(++right) = tmp;
								RIGHT++;
						}
				}else{
						printf("right zero....outside loop\n");
						*right = data;
						RIGHT++;
						top++;
				}
		}else{
				printf("right limit reached\n");
		}
}
void check_left(char* left, int data, char* limit) {
		printf("Checking left with %d\n", data);
		int tmp;
		if(left != limit) {
				if(*left != 0) {
						if(data < *left) {
								check_left(--left, data, limit);
						}else{
								printf("left....inside loop\n");
								tmp = *left;
								*left = data;
								*(--left) = tmp;
								LEFT--;
						}
				}else{
						printf("left zero....outside loop\n");
						*left = data;
						LEFT--;
						top++;
				}
		}else{
				printf("left limit reached\n");
		}
}
void array_stack(char* tree, int data, int size) {
		char* lowbound = &tree[0];
		char* upperbound = &tree[size];
		int mid = size / 2;
		if(isempty()) {
				top++;				// At present, RIGHT/LEFT just give direction....not much else. Can I get rid globals....??
				tree[mid] = data;
				RIGHT = &tree[mid+1];
				LEFT = &tree[mid-1];
		}else if(data > tree[mid]) {
				check_right(RIGHT, data, upperbound); 
		}else{
				check_left(LEFT, data, lowbound);
		}
}

void print_tree(char* tree, int size) {
		int i;
		for(i=0;i<size;i++) {
				printf("%d  ", tree[i]);
		}
		printf("\n");
}


//  ************************  Tree functions  ****************************
struct node* create_node(struct node* root, int data) {
		root = malloc(sizeof(struct node));
		if(root==NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(1);
		}
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		printf("node created\n");
		return root;
}

void insert(struct node** root, int data) {
		if(*root==NULL) {
				*root = create_node(*root, data);
				push((*root)->data);
		}else if((*root)->data >= data) {
				insert(&(*root)->left, data);
		}else{
				insert(&(*root)->right, data);
		}
}
void preorder(struct node* root) {
		if(!root) {
				return;
		}else{
				preorder(root->left);
				printf("%d\n", root->data);
				preorder(root->right);
		}
}
void pop_stack(char* stack) {
		int data;
		while(!isempty()) {
				data = pop();
				printf("popping stack data: %d\n", data);
		}
		printf("popping stack: now empty\n");
}
void freeall(struct node* root) {
		if(root==NULL) {
				return;
		}else{
				freeall(root->left);
				freeall(root->right);
				free(root);
				root == NULL;
				printf("node freed\n");
		}
}

int main(int argc, char** argv) {
		//binary tree
		struct node* root = NULL;
		insert(&root, 100);
		insert(&root, 50);
		insert(&root, 127);// These can just as well be 'push' instead of 'insert'.
		
		preorder(root);
		printf("root->data = %d\n", root->data);
		printf("root->left->data = %d\n", root->left->data);
		
		// binary tree with push and pop
		printf("top = %d\n", top);
		peek();
//		pop_stack(stack);  // Use either or..
		clear_stack(stack);
		printf("top = %d\n", top);

/*		// tree stack form  this isn't really a stack, but more a binary tree fill......
		puts("Trying the tree_stack");
		array_stack(tree_stack, 99, LIMIT);
		array_stack(tree_stack, 66, LIMIT);
		array_stack(tree_stack, 101, LIMIT);
		array_stack(tree_stack, 100, LIMIT);	
		array_stack(tree_stack, 122, LIMIT);		
		array_stack(tree_stack, 127, LIMIT);		
		array_stack(tree_stack, 50, LIMIT);
		array_stack(tree_stack, 71, LIMIT);
		print_tree(tree_stack, LIMIT);

		if(RIGHT >= tree_stack+LIMIT){
				printf("RIGHT is out of bounds\n");
		}else{
				printf("RIGHT = %d  add: %p\n", *RIGHT, RIGHT);
		}
		if(LEFT >= tree_stack+LIMIT){
				printf("LEFT is out of bounds\n");
		}else{
				printf("LEFT = %d add: %p\n", *LEFT, LEFT);
		}
*/
		freeall(root);

		return 0;
}


