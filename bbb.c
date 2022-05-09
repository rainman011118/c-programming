#include<stdio.h>
#include<stdlib.h>

struct node{
		int data;
		struct node* right;
		struct node* left;
};

struct node* create_node(int data);
void insert(struct node** root, int data);
void printall(struct node* r, int data);
void freeall(struct node* root);

int main(int argc, char* argv[]) {
		int data = 100;
		struct node* root = NULL;
		root = create_node(data);
		insert(&root, 10);
		insert(&root, 20);
		insert(&root, 30);
		insert(&root, 40);
		insert(&root, 120);
		insert(&root, 150);
		insert(&root, 200);
		printall(root, data);
		printf("\n");

		freeall(root);
		return 0;
}
struct node* create_node(int data) {
		struct node* node = malloc(sizeof(struct node*));
		if(node==NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(1);
		}
		node->data = data;
		node->right = NULL;
		node->left = NULL;
		printf("node created (%d)\n", data);
		return node;
}
void insert(struct node** root, int data) {
		if(*root==NULL) {
				*root = create_node(data);
		}else{
				if(data<=(*root)->data) {
						insert(&(*root)->left, data);
				}else{
						insert(&(*root)->right, data);
				}
		}
}
void printall(struct node* r, int data) {
		if(r) {
				printall(r->left, data);
				printf("%d ", r->data);
				printall(r->right, data);
		}
}
void freeall(struct node* root) {
		if(root) {
				freeall(root->left);
				freeall(root->right);
				printf("freeing node %d\n", root->data);
				free(root);
		}
}



