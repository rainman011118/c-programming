#include<stdio.h>
#include<stdlib.h>

struct node {
		int data;
		struct node* next;
};

struct node* create_node(int data, char* title);
void traverse_linked_list(struct node* a);
void free_linked_list(struct node* head);


int main(int argc, char** argv) {
		struct node* head = create_node(10, "head");
		struct node* two = create_node(20, "two");
		struct node* three = create_node(30, "three");

		head->next = two;
		two->next = three;

		traverse_linked_list(head);
		free_linked_list(head);

		return 0;
}

struct node* create_node(int data, char* title) {
		struct node* x = malloc(sizeof(struct node));
		if(x==NULL) {
				fprintf(stderr, "memory allocation failed\n");
				exit(1);
		}
		x->data = data;
		x->next = NULL;
		printf("%s node successfully created\n", title);

		return x;
}

void traverse_linked_list(struct node* a) {
		while(a != NULL) {
				printf("data: %d\n", a->data);
				a = a->next;
		}
}

void free_linked_list(struct node* head) {
		struct node* tmp;
		while(head != NULL) {
				tmp = head;
				head = head->next;
				free(tmp);
				tmp = NULL;
				printf("node successfully freed\n");
		}
}


		
