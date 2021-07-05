#include<stdio.h>
#include<stdlib.h>

struct node {
		int data;
		struct node* next;
};
//Function to create the nodes:(data arg is optional) ###############################
struct node* create_node(int data) {
		struct node* a = malloc(sizeof(struct node));
		if(a == NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(1);
		}
		a->data = data;
		a->next = NULL;
		return a;
}
//Function to print info about nodes for easy comparison: (comment is for description only)######
void print_struct_info(const struct node* node, const char* comment) {
		if(node == NULL) {
				printf("%s is NULL\n", comment);
		}else {
				printf("%s: data:%d  address:%p  address of next:%p\n", comment, node->data, node, node->next);
		}
}
int main() {
		struct node* head = create_node(10);
		struct node* second = create_node(20);
		struct node* third = create_node(30);
		print_struct_info(head, "head");		
		print_struct_info(second, "second");		
		print_struct_info(third, "third");		

		head->next = second;
		second->next = third;
// https://www.youtube.com/watch?v=928Xhm_jByo ##################################	

		print_struct_info(head, "head");		
		print_struct_info(second, "second");		
		print_struct_info(third, "third");		
		print_struct_info(head->next, "head->next");		
		print_struct_info(second->next, "second->next");		
		print_struct_info(third->next, "third->next");		
//Free the nodes:####################################
		free(head);
		free(second);
		free(third);
		head = NULL;
		second = NULL;
		third = NULL;

		return 0;
}

