#include<stdio.h>
#include<stdlib.h>


struct node {
		int data;
		struct node* next;
};

struct node* build_node(int data, const char* name);
void traverse_list(struct node* head);
void free_list(struct node* head);
void insert_node(struct node** head, int data, const char* name);

int main(int argc, char** argv) {
		struct node* head = build_node(10, "head");
		struct node* two = build_node(20, "two");
		struct node* three = build_node(30, "three");

		head->next = two;
		two->next = three;
		traverse_list(head);

		printf("Inserting a node at the head of the linked list....\n");
		insert_node(&head, 500, "new");

		traverse_list(head);

		free_list(head);

		return 0;

}
struct node* build_node(int data, const char* name) {
		struct node* node = malloc(sizeof(struct node));
		if(node==NULL) {
				fprintf(stderr, "memory allocation failed\n");
				exit(1);
		}
		node->data = data;
		node->next = NULL;
		printf("%s node successfully created\n", name);
		return node;
}
void traverse_list(struct node* head) {
		while(head != NULL) {
				printf("data: %d\n", head->data);
				head = head->next;
		}
}
void free_list(struct node* head) {
		struct node* tmp = NULL;
		while(head != NULL) {
				tmp = head;
				head = head->next;
				free(tmp);
				tmp = NULL;
				printf("node successfully freed\n");
		}
}
void insert_node(struct node** head, int data, const char* name) {
		struct node* new = malloc(sizeof(struct node));
		if(new==NULL) {
				fprintf(stderr, "memory allocation failed\n");
				exit(1);
		}
		new->data = data;
		new->next = *head;
		*head = new;
		printf("%s node successfully inserted at front\n", name);
}
