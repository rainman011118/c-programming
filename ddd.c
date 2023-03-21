#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 64


// ****************************  WORK IN PROGRESS ******************************************************
// things to do:
//		create multiple links for different details
//		See addCar function

struct cars* createNode();
void addCar(struct cars** x);
void printout(struct cars* x);
void freeall(struct cars* x);

struct cars {
		char make[MAX];
		char  model[MAX];
		int year;
		struct cars* next;
};

int main(int argc, char** argv) {
		struct cars* root = createNode();
		printf("MAIN: root %p\n&root = %p\n", root, &root); // root matches with createNode root

		addCar(&root);
		printout(root);

		freeall(root);

		return 0;
}

struct cars* createNode() {
		struct cars* x = malloc(sizeof(struct cars));
		if(x==NULL) {
				fprintf(stderr, "Memory allocation failure\n");
				exit(3);
		}
		x->next = NULL;
		printf("struct successfully created %p\n", x);	// This matches with main 'root'
		return x;
}

// ########################################################################################
// Need to rewrite this whole function, because it is not logical.....
void addCar(struct cars** x) {
		if(*x == NULL) {
				*x = createNode();
				printf("address in addCar of *x = %p\n", *x);
		}
		while(*x != NULL) { // This is not good, because even if I have data written to this, it will simply be overwritten, so I need to make a way to check if data is already there, and then to skip to next node.
				puts("Enter the make: ");
				fgets((*x)->make, MAX, stdin);
				(*x)->make[strlen((*x)->make) -1] = 0;
				puts("Enter the model: ");
				fgets((*x)->model, MAX, stdin);
				(*x)->make[strlen((*x)->model) -1] = 0;
				//scanf("%d", &(*x)->model);
				puts("Enter the year: ");
				scanf("%d", &(*x)->year);
				//*x = (*x)->next;		//THIS WAS CAUSING THE PRINTOUT TO FAIL....IT WAS SETTING THE ROOT AS NULL....So I need to use single pointer perhaps instead of the double pointer...??
				//NOTE: Also that I need to add in some sort of error checking for the details, since if I type in chars for where INTS are supposed to go, scanf only records the first single input, which will cause overrun into next line, and also returns 0 since chars are not valid.
		}
}
// #################################################################################
void printout(struct cars* x) {
		printf("printing out...\n");
		printf("address of root %p\n", x);
		while(x != NULL) {
				printf("make: %s\nmodel: %s\nyear: %d\n", x->make, x->model, x->year);
				x = x->next;
		}
		printf("x = NULL\n");
}
void freeall(struct cars* x) {
		struct cars* tmp;
		while(x != NULL) {
				tmp = x;
				x = x->next;
				free(tmp);
				tmp = NULL;
				printf("Node freed\n");
		}
}

