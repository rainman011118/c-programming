#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//DOUBLY LINKED LIST (This is similar to a BST except that is is ordered)
//USE OF PREV AND NEXT BUT ALSO JUST SOLE USE OF NEXT....

/*inserting node at head
 * inserting node at end
 * printing reverse order
*/

struct node {
		int data;
		struct node* next;
		struct node* prev;
};
struct node* create_node(int data, const char* name);
void display_data(struct node* head);
void display_data_reverse(struct node* end);
void insert_node(struct node** head, int data);
struct node* insert_node_at_end(struct node* node, int data);
void free_nodes(struct node* head);
void softreverse(struct node** head);
void hardReverse(struct node** head);

int main(int argc, char** argv) {
		struct node* head = create_node(1, "head");
		struct node* two = create_node(2, "two");
		struct node* three = create_node(3, "three");

		head->next = two;
		two->next = three;
		two->prev = head;
		three->prev = two;
		display_data(head);

		insert_node(&head, 4);
		display_data(head);

		struct node* end = create_node(5, "end");
		three->next = end;
		end->prev = three;
		display_data(head);
/* THERE ARE TWO WAYS TO REVERSE:
 * Set head to end and use prev pointers OR break links and point them the other way and only have to use next pointers for traversal.
 */
//########### Using prev and next to traverse list ###################################
		printf("Displaying list in reverse order just using prev pointers and passing end as arg instead of head...\n");
		display_data_reverse(end);
		printf("Reversing linked list by setting *head to point to end node, then using print with prev pointers.. *head is RESET before returning to main....\n");
		softreverse(&head);// included the display_data_reverse().
		printf("Changing all the links in the list permanently, using only the NEXT pointers, to reverse it, then calling print and passing normal head pointer which uses just NEXT to traverse...\n"); 
//###################### Break the links and point them the other way ###################### 
		hardReverse(&head);//JUST USING NEXT POINTERS (Double pointer was chosen because I could do it all in the external function without having to return anythin.) HEAD now points to what was, the end of the list.  It is basically flipping the whole list end to end and setting the pointers in the opposite direction..
		display_data(head);

		free_nodes(head);

		return 0;
}
struct node* create_node(int data, const char* name) {
		struct node* node = malloc(sizeof(struct node));
		if(node==NULL) {
				fprintf(stderr, "memory allocation failed\n");
				exit(1);
		}
		node->data = data;
		node->next = NULL;
		node->prev = NULL;
		printf("%s node created successfully\n", name);
		return node;
}
//####### This uses ->next to display list ###############################
void display_data(struct node* head) {
		printf("Displaying list data...\n");
		while(head != NULL) {
				printf("data: %d\n", head->data);
				head = head->next;
		}
}
//####### This uses ->prev to display list ###############################
void display_data_reverse(struct node* end) {
		printf("Displaying list in reverse order...\n");
		while(end != NULL) {
				printf("data: %d\n", end->data);
				end = end->prev;
		}
}
void insert_node(struct node** head, int data) {
		printf("new node being added to head of list....\n");
		struct node* new = create_node(data, "New head");
		new->next = *head;
		(*head)->prev = new;//this bit was key, because it was not connecting the newly created head node to the old head node, when printing the reverse order. (since the old head->prev = NULL;)
		*head = new;
}
void free_nodes(struct node* head) {
		struct node* tmp = NULL;
		while(head != NULL) {
				tmp = head;
				printf("node data: %d ..freeing....\n", head->data);
				head = head->next;
				free(tmp);
				tmp = NULL;
		}
		printf("All nodes successfully freed\n");
}
//###############################################################################
//This function simply changes the head pointer to point to the end of the list. Then prints the data from the head backwards using the prev pointers. SO NOT PERMANENT. Goes to end of list, sets head pointer to it, then works backwards to print data using prev.
void softreverse(struct node** head) {
		struct node* tmp = NULL;
		struct node* origin = *head;
		while(*head != NULL) {
				tmp = *head;
				*head = (*head)->next;
		}
		*head = tmp;//sets *head to last node traversed before NULL.
		display_data_reverse(*head);
		*head = origin;//RESETS THE HEAD BACK TO ORIGINAL BEGINNING OF LIST.....before returning to main.
		printf("Head position RESET to original top of list before return to main().\n");
}
//######################## THIS IS THE BETTER ONE ####################################
//This function reverses the list only using NEXT pointers.  So all the LINKS are reversed and HEAD is set to the end of the list (which is now the new beginning). PERMANENT CHANGES. Starts at head of list, works its way to end, breaking links and pointing them the other way, setting head to end(new beginning).
void hardReverse(struct node** head) {
		struct node* current = *head;
		struct node* prev = NULL;
		struct node* next = NULL;
		while(current != NULL) {
				next = current->next;
				current->next = prev;
				prev = current;
				current = next;
	}
	*head = prev;				
}







