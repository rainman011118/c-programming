#include"bts.h"

struct node {//This had to be defined here since it is 'invisible' to compiler otherwise.
		int data;
		struct node* left;
		struct node* right;
};
void inorder(struct node* root) {//data is printed 'in order' smallest - biggest.
		if(root != NULL) {
				inorder(root->left);
				printf("%d  ", root->data);
				inorder(root->right);
		}
}
void preorder(struct node* root) {// data is printed as each node is reached. So all of left subtree of root is printed, then all of right subtree of root.
		if(root != NULL) {
				printf("%d  ", root->data);
				preorder(root->left);
				preorder(root->right);
		}
}
void postorder(struct node* root) {// data is printed after both children are checked.  Post order is generally used for deleting trees.
		if(root != NULL) {
				postorder(root->left);
				postorder(root->right);
				printf("%d  ", root->data);
		}
}

