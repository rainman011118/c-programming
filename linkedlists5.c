#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
		int data;
		char* name;
		struct node* next;
};
//This was my first attempt at the build_node fn.  See below for corrected. ######################
/*struct node* build_node(int data, int size) {
		struct node* a = malloc(sizeof(struct node));
		if(a==NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(1);
		}
		printf("node block created...\t");
		a->data = data;
		a->name = malloc(sizeof(char) * size);
		if(a->name==NULL) {
				fprintf(stderr, "pointer->name memory allocation failed\n");
				exit(1);
		}
		printf("node->name block created...\t");
		a->next = NULL;
		printf("node fully completed\n");
		return a;
}
*/
//THIS WORKED!!  WOOHOOOOO!!!  Block of memory created meant that strcpy must be used.  Whereas before, I was creating memory then assigning string literal to a->name which basically meant the pointer was NOW NOT POINTING TO MY BLOCK OF MEMORY....so it was lost....
struct node* build_node(int data, char* title) {
		struct node* a = malloc(sizeof(struct node));
		if(a==NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(1);
		}
		printf("node block created...\t");
		a->data = data;
		a->name = malloc(strlen(title) + 1);
		if(a->name==NULL) {
				fprintf(stderr, "pointer->name memory allocation failed\n");
				exit(1);
		}
		strcpy(a->name, title);
		printf("node->name block created...\t");
		a->next = NULL;
		printf("node fully completed\n");
		return a;
}
void print_info(struct node* a) {
		while(a != NULL) {
				printf("%d\t%s\n", a->data, a->name);
				a = a->next;
		}
}
// Something wrong with this code....############################# It said: free(): invalid pointer. Aborted (core dumped) - SORTED:It was to do with my fuck up! SEE OTHER COMMENTS.
void free_node(struct node* a) {
		struct node* tmp = NULL;
		while(a != NULL) {
				free(a->name);
				a->name = NULL;
				printf("a->name freed successfully\t");
				tmp = a;
				a = a->next;
				free(tmp);
				tmp = NULL;
				printf("node freed successfully\n");
		}
		printf("All nodes successfully freed\n");
}
int main(int argc, char** argv) {
		//int LEN = 64;
		//struct node* head = build_node(10, LEN);
		//struct node* two = build_node(20, LEN);
		//struct node* three = build_node(30, LEN);
	
		char name1[] = "first node";
		char name2[] = "second node";
		char name3[] = "third node";
		struct node* head = build_node(10, name1);
		struct node* two = build_node(20, name2);
		struct node* three = build_node(30, name3);

		/*THIS IS PROBABLY INCORRECT since these string literals will be allocated to read-only memory and I have already set-aside memory in the 'build_node' function, which means, strcpy must be used.  HOWEVER WHEN I RAN IT THE ONE TIME, THE INFO WAS DISPLAYED CORRECTLY...? Also, if malloc was used to create the space for the name pointer, then when I put the below string literal assignments, it would have meant the head->name pointers now point to somewhere completely different.....?
		 * SEE: https://dev-notes.eu/2018/07/double-pointers-and-linked-list-in-c*/
/*		head->name = "first node";
		two->name = "second node";
		three->name = "third node";
*/
		head->next = two;
		two->next = three;
		print_info(head);
		free_node(head);

		return 0;
}


