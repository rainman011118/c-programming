#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"bts.h"

#define BIGGEST(a,b) (a < b ? b : a)

/*Compile:
Generate object files first: 
		gcc -c bts_functions.c
		
linking:
		gcc bts.c bts_functions.o -o binarytree
*/
struct node {
		int data;
		struct node* left;
		struct node* right;
};
struct node* create_node(int data) {
		struct node* root = malloc(sizeof(struct node));
		if(root ==NULL) {
				fprintf(stderr, "memory allocation failed\n");
				exit(1);
		}
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		printf("node successfully created...\n");
		return root; 
}
// Remember to change in main: insert(&root, data)
void insert(struct node** root, int data) {
		if(*root==NULL) {
				*root = create_node(data);
		}else if(data <= (*root)->data) {					// **** DIRECT METHOD  *****
				insert(&(*root)->left, data);
		}else {
				insert(&(*root)->right, data);
		}
}
/* Remember to change in main: struct node* whatever = insert(root, data);
struct node* insert(struct node* root, int data) {
		if(root==NULL) {
				root = create_node(data);
				return root;
		}else if(data <= root->data) {
				root->left = insert(root->left, data);			//  **** INDIRECT METHOD  ****
		}else {
				root->right = insert(root->right, data);
		}
		return root;
}
*/
//search for data in tree and return the level it is located in the tree
//NOTE: This will not search the whole tree.  So it will stop as soon as it finds match at first instance. This is what makes a binary search more efficient but what about duplicate nodes???
int search_tree(struct node* root, int data) {
		int i = 1;
		while(root != NULL) {
				if(data < root->data) {
						root = root->left;
						++i;
				}else if(data > root->data) {
						root = root->right;
						++i;
				}else if(data == root->data) {
						return i;
				}
		}
		printf("End of branch reached\n");
		return 0;
}
//finding the height of a tree 
int height(struct node* root) {
		if(!root) {
				return 0;
		}
		int lheight = height(root->left);
		int rheight = height(root->right);
		return 1 + BIGGEST(lheight, rheight);			// BIGGEST(a,b) (a < b ? b : a)
		// This fn is basically is returning the number of nodes in the left tree and right tree, whichever is higher.
}
void free_all(struct node* root) {
		if(root != NULL) {
				free_all(root->left);
				free_all(root->right);
				printf("Freeing node %d\n", root->data);
				free(root);
				root = NULL;
		}else {
//				printf("leaf node reached\n"); 
		}
}
int main(int argc, char** argv) {
		struct node* root = NULL;
/*NOTE: When I commented out the above ...root = NULL, and instead put: struct node* root = insert(root, 100), it gave me a SEGFAULT immediately!.....:S  SO IT LOOKS LIKE THINGS ARE NOT SET TO NULL BY DEFAULT.... */
		insert(&root, 100);
		srand((unsigned)time(NULL));
		int i;
		for(i=0;i<20;i++) {
				insert(&root, rand()%200);
		}
/*	Slow way (direct method)	
		insert(&root, 50);
		insert(&root, 200);
		insert(&root, 25);
		insert(&root, 150);
		insert(&root, 70);
		insert(&root, 195);
		
		insert(&root, 60);
		insert(&root, 40);
		insert(&root, 120);
		insert(&root, 10);
		insert(&root, 170);
		*/
/*  Old way (indirect method)
		struct node* thirteen = insert(root, 180);
		struct node* fourteen = insert(root, 20);
		struct node* fifteen = insert(root, 110);
		struct node* sixteen = insert(root, 190);
		struct node* seventeen = insert(root, 160);
		struct node* eighteen = insert(root, 30);
		struct node* nineteen = insert(root, 90);
		struct node* twenty = insert(root, 140);
*/
		int h = height(root);
		printf("height of tree is: %d\n", h);

		puts("inorder traversal:");
		inorder(root);
		printf("\n");

		puts("preorder traversal:");
		preorder(root);
		printf("\n");

		puts("postorder traversal:");
		postorder(root);
		printf("\n");

		int input = 0;
		puts("To search for a specific node, please insert a number between 1-200");
		scanf("%d", &input);
		printf("Searching for data %d within tree....\n", input);
		int check = search_tree(root, input);
		if(check) {
				printf("data %d found at level %d\n", input, check);
		}else {printf("data not found...consider adding it to tree...\n");}

		free_all(root);

		return 0;
}

/* NOTE:
 * height of a tree = number of nodes - 1;
 * mimimum number of nodes in a tree = height + 1
 * maximum number of nodes in a tree = 2^(h+1)-1
 *		so if height(h) was 5, the maximum number of nodes would be 63.
 * maximum depth and height I think are the same thing.
*/


