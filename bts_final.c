#include<stdio.h>
#include<stdlib.h>

// All works good + double pointer for insert function :) ***************************

struct node {
		int data;
		struct node* left;
		struct node* right;
};
struct node* create(int data) {
		struct node* root = malloc(sizeof(struct node));
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
				*root = create(data);
		}else if(data <= (*root)->data) {
				insert(&(*root)->left, data);
		}else {
				insert(&(*root)->right, data);
		}
}
void inorder(struct node* root) {
		if(root != NULL) {
				inorder(root->left);
				printf("node data = %d\n", root->data);
				inorder(root->right);
		}
}
void free_all(struct node* root) {
		if(root != NULL) {
				free_all(root->left);
				free_all(root->right);
				free(root);
				printf("node freed\n");
		}
}
int main(void) {
		struct node* root = create(100);
		insert(&root, 50);
		insert(&root, 25);
		insert(&root, 150);
		insert(&root, 200);
		insert(&root, 75);

		struct node** p = &root;
		printf("root = %p(address of struct node)\n*root won't give anything but root->data = %d\n", root, root->data);
		printf("p = %p(address of root)\n*p = %p(address of struct node)\n**p won't work but (*p)->data = %d\n", p, *p, (*p)->data);

		inorder(root);

		free_all(root);

		return 0;
}

