#include<stdio.h>
#include<stdlib.h>

//This is the first method of creating a singly linked list. But it is not the most efficient due to having to create a pointer for every list. Hence the preferred method uses head->next->next....
//NO NEED TO RUN THIS PROGRAM ############################

struct node {
		int data;
		struct node* next;
};

int main(int argc, char** argv) {

		//List 1:
		struct node* head = malloc(sizeof(struct node));
		if(head == NULL) {
				fprintf(stderr, "Failed to allocate memory!\n");
				exit(1);
		head->data = 45;
		head->next = NULL;
		
		//List 2:
		struct node* current = malloc(sizeof(struct node));
		if(current == NULL) {
				fprintf(stderr, "Failed to allocate memory!\n");
				exit(1);
		current->data = 98;
		current->next = NULL;
		head->next = current;//This connects list 2 to list 1.(The head pointer now contains the &current starting memory block).
		
		//List 3:
		struct node* another = malloc(sizeof(struct node));
		if(another == NULL) {
				fprintf(stderr, "Failed to allocate memory!\n");
				exit(1);
		another->data = 33;
		another->next = NULL;
		current->next = another;//This connects list 3 to list 2.

/*Other way to reference the other lists is to use: head->next->next notation.
		head->next->next = another. This allows us to skip creating a pointer(ie current) since we can hop along the lists using the head.
*/
		free(head);
		free(current);
		free(another);

		return 0;

}

