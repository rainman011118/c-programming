#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
		int data;
		struct node* next;
};
void create_node(struct node** head, int data) {
		*head = malloc(sizeof(struct node));
		if(*head==NULL) {
				fprintf(stderr, "memory allocation failed\n");
				exit(1);
		}
		(*head)->data = data;		//These bits wouldn't work without the brackets
		(*head)->next = NULL;		//-> symbol was not working unless brackets were used.
		printf("head node successfully created...\n");
}

int main(int argc, char** argv) {
		struct node* head = NULL;
		create_node(&head, 12);

		printf("head->data = %d\n", head->data);

		free(head);

		return 0;

}


