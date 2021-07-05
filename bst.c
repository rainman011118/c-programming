#include<stdio.h>
#include<stdlib.h>

struct BSTnode {
		int data;
		struct BSTnode* left;
		struct BSTnode* right;
};
struct BSTnode* create_node(int data) {
		struct BSTnode* root = malloc(sizeof(struct BSTnode));
		if(root ==NULL) {
				fprintf(stderr, "memory allocation failed\n");
				exit(1);
		}
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		printf("Root node successfully created...\n");
		return root; 
}
struct BSTnode* insert(struct BSTnode* root, int data) {
		if(root==NULL) {
				root = create_node(data);
				return root;
		}else if(data <= root->data) {
				root->left = insert(root->left, data);
		}else {
				root->right = insert(root->right, data);
		}
		return root;
}

/* Haven't figured this traverse one out yet.......
void traverse_tree(struct BSTnode* root, int data) {
		while(root != NULL) {
				if(root->data > data) {
						root = root->right;
						}
				}else if(root->data < data) {
						printf("data: %d\nchecking left side...\n", root->data);
						root = root->left;
				}else root->data == data) {
						printf("data: %d\nchecking left side....\n", root->data);
						root = root->left;

		}
		printf("end of branch reached\n");
}
//First attempt at Method using repeated calls for each branch....gave me a segfault....:(
void free_tree(struct BSTnode* root) {
		struct BSTnode* tmp = NULL;
		while(root != NULL) {
				if(root->left != NULL) {
						free_tree(root->left); //do i need to return something for these calls....???
						//or will it just continue on to test while loop again and continue to right branch..?
				}else if(root->right != NULL) {
						free_tree(root->right);
				}else {
						tmp = root;
						root = root->left; //can be either root->left or root->right since both are NULL;
						//or can I simply say root = NULL;
						free(tmp);
						tmp = NULL;
						printf("node freed...\n");
				}
		}
		printf("binary search tree freed....\n");
}
*/
//This works well:
void free_all(struct BSTnode* root) {
		if(root != NULL) {
				free_all(root->left);
				free_all(root->right);
				free(root);
				root = NULL;
				printf("node cleared\n");
		}else {
				printf("leaf node = NULL\n");
		}
}
int main() {
		struct BSTnode* root = NULL;
/*NOTE: When I commented out the above ...root = NULL, and instead put: struct BSTnode* root = insert(root, 100), it gave me a SEGFAULT immediately!.....:S  SO IT LOOKS LIKE THINGS ARE NOT SET TO NULL BY DEFAULT.... */

		root = insert(root, 100);
		struct BSTnode* two = insert(root, 50);
		struct BSTnode* three = insert(root, 200);

		free_all(root);

		return 0;
}




