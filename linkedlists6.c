#include<stdio.h>
#include<stdlib.h>

struct node {
		int data;
		struct node* next;
};
struct node* make_node(int data) {
		struct node* node = malloc(sizeof(struct node));
		if(node == NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(1);
		}
		node->data = data;
		node->next = NULL;
		return node;
}
// ######### METHOD 1 to insert node via single pointer(pass by value) #######################
/*struct node* insert_node(struct node* head, int data) {
		struct node* new = malloc(sizeof(struct node));
		if(new == NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(1);
		}
		new->data = data;
		new->next = head;
		return new;
}*/
//		head = new;This statement does work but because the values are copies and not the original, even if you return the head, it will not be changed in main. So to affect the changes permanently, a reference to the head pointer must be used (double pointer). Then nothing needs to be returned. Otherwise it completes like:
		//new->next = head;
		//return new;
		//AND MAKE SURE in main it is called: head = insert_node().  This way new is returned to head ( this is practically the same as make_node()).
/*SEE: https://stackoverflow.com/questions/7271647/what-is-the-reason-for-using-a-double-pointer-when-adding-a-node-in-a-linked-lis
SEE ALSO: https://stackoverflow.com/questions/8403447/swapping-pointers-in-c-char-int/8403699#8403699
Looks like when a pointer is passed, it too, is passed by value (so it is a copy). Therefore when the values get changed inside a fn, it is still only local and so doesn't affect the original values.  But if it is passed by reference i.e. pointer to the pointer, then the dereferenced values ARE changed = permanent.
}*/
// ######### METHOD 2 - This directly changes the values so no return needed #####################
void insert_node_by_ref(struct node** head, int data) {
		struct node* new = malloc(sizeof(struct node));
		if(new == NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(1);
		}
		new->data = data;
		new->next = *head;
		*head = new;
}
void free_nodes(struct node* head) {
		struct node* tmp = NULL;
		while(head != NULL) {
				tmp = head;
				head = head->next;
				free(tmp);
				tmp = NULL;
		}	
		printf("nodes freed successfully\n");
}
void print_list(struct node* head) {
		while(head != NULL) {
				printf("data = %d\tnext = %p\n", head->data, head->next);
				head = head->next;
		}
}
int main(int argc, char** argv) {
		struct node* head = make_node(10);
		struct node* two = make_node(20);
		struct node* three = make_node(30);

		head->next = two;
		two->next = three;
		printf("head = %p\thead->data = %d\thead->next = %p\n", head, head->data, head->next);
		printf("two = %p\ttwo->data = %d\ttwo->next = %p\n", two, two->data, two->next);
		printf("three = %p\tthree->data = %d\tthree->next = %p\n", three, three->data, three->next);

		//FOR METHOD 1:
//		head = insert_node(head, 1);// Very important that this is assigned to head when called.
//		print_list(head);
		
		//FOR METHOD 2:
		insert_node_by_ref(&head, 2);
		print_list(head);

		free_nodes(head);
		return 0;
}
//Everything worked well. Just comment out the correct method as required.
/* Passing the double pointer is considered better practice as it saves one step of code (the return).  Remember that with double pointers (and single pointers), when passed as arguments, when the deference operator is used in the function, the DIRECT values are changed permanently (whether they are returned or not (usually don't need to be)). This dereference operator is the key.  If is it not used within the function, then any values within the function are simply copies.*/
