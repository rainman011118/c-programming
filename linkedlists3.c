#include<stdio.h>
#include<stdlib.h>

struct node {
		int data;
		struct node* next;
};
void print_linkedlists(struct node* a) {
		while(a != NULL) {
				printf("data = %d\n", a->data);
				a = a->next;
		}
}
/* NEED TO CHECK THIS FIRST BEFORE RUNNING IT...#######....ANSWER: Yes this will work fine.
void free_linkedlists(struct node* a) {
		struct node* tmp;
		while(a != NULL) {
				tmp = a;
				a = a->next;
				free(tmp);
				tmp = NULL;
		}
}
Another way to carry this out is to pass double pointer to head.  SEE:https://www.geeksforgeeks.org/how-to-write-functions-that-modify-the-head-pointer-of-a-linked-list/  */
int main(int argc, char** argv) {
		struct node* head = malloc(sizeof(struct node));
		if(head==NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(1);
		}
		head->data = 10;
		head->next = NULL;

		struct node* second = malloc(sizeof(struct node));
		if(second==NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(1);
		}
		second->data = 20;
		second->next = NULL;
		head->next = second;

		struct node* third = malloc(sizeof(struct node));
		if(third==NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(1);
		}
		third->data = 30;
		third->next = NULL;
		second->next = third;
		
		print_linkedlists(head);
/* I don't know if the following 'free' is correct because I can't find anywhere that states it in this fashion.  They all show a loop to free nodes.  Does this mean what I have put here is invalid...?
 */
		free(third);
		free(second);
		free(head);
		head = NULL;
		second = NULL;
		third = NULL;
/* SEE: https://www.youtube.com/watch?v=928Xhm_jByo
 * This video seems to say that the above free method is okay...
 */
		return 0;
}
