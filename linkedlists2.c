#include<stdio.h>
#include<stdlib.h>


struct node {
		int data;
		struct node* next;
};

int main(int argc, char** argv) {
		struct node* head = malloc(sizeof(struct node));
		if(head == NULL) {
				fprintf(stderr, "Memory allocation failed!\n");
				exit(1);
		}else {
				head->data = 55;
				head->next = NULL;
		}

		struct node* numberOne = malloc(sizeof(struct node));
		if(numberOne == NULL) {
				fprintf(stderr, "Memory allocation failed!\n");
				exit(1);
		}else {
				numberOne->data = 123;
				numberOne->next = NULL;
				head->next = numberOne;

		}
		
		free(numberOne);
		free(head);//I don't know if the order of freeing head and numberOne matter, but I put numberOne first just incase. Thinking it through, I don't think it matters as they are two separate lists and the head->next only holds the address of numberOne, which can be wiped anyway. 

		return 0;
}






