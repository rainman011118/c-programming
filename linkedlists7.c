#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
		int data;
		struct node* next;
};

//Using double pointer to create head node in list ##############################

void create_node(struct node** head, int data) {
		*head = malloc(sizeof(struct node));
		if(*head==NULL) {
				fprintf(stderr, "memory allocation failed\n");
				exit(1);
		}
		(*head)->data = data;		//These bits wouldn't work without the brackets
		(*head)->next = NULL;		//-> symbol was not working unless brackets were used.QUESTION: SHOULD I BE DOING IT THIS WAY OR SHOULD I BE DECLARING A NEW STRUCT NODE* NODE = malloc and doing it the normal way and then just assigning *head from there.....???

		printf("head node successfully created...\n");
}

int main(int argc, char** argv) {
		struct node* head = NULL;
		create_node(&head, 12);

		printf("head->data = %d\n", head->data);
		printf("&head = %p\tThis is the address of the actual head pointer itself\n", &head);

//NOTE: why *head will not work... ######################################

		printf("head = %p\tThis is the address that head points to : malloc. So if I was to dereference this using *head, I would get the value at the struct. BUT, since it is a struct, the value in this case is int data, and this can only be accessed via head->data notation and NOT *head\n", head);
//		printf("*head = %p\n", *head);	//%p = void* and *head = struct node* so ERRORS...?

		free(head);

		return 0;

}


