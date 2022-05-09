#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// NOTE HERE: WHEN I USED JUST 'typedef struct {.....}element;' the struct element* next was fucking up...
// SO I HAD TO TYPE 'typdef struct element{....}element;' and it worked fine...
typedef struct element{
		char* name;
		char symbol[8];
		int mass;
		struct element* next;
}element;

//THIS BELOW TYPEDEF WILL NOT WORK IF IT INCLUDES A STRUCT POINTER AS A MEMBER
typedef struct{
		char* name;
		char symbol[8];
		int mass;
//		struct element* next;
}ele;

int main() {
		int array[10] = {};
		for(int i=0;i<10;i++) {
				printf("%d ", array[i]);
		}
		printf("\n");
		//QUESTION: WHY CAN'T I INSERT THE 'next->0' in it....? Is it because element o is not yet declared...
		//TYPEDEF STRUCT ELEMENT
		element h = {"Hydrogen", "H", 1};
		element o = {"Oxygen", "O2", 8};
		element he = {"Helium", "HE", 2};
		element cl = {"Chlorine", "Cl", 7};
		element* ptr = &h;
		h.next = &o;
		o.next = &he;
		he.next = &cl;
		cl.next = NULL;
		while(ptr) {
				printf("\n");
				printf("element: %s\nsymbol: %s\natomic mass: %d\n", ptr->name, ptr->symbol, ptr->mass);
				ptr = ptr->next;
		}
//*************************************************************
		//TYPEDEF STRUCT ELE:
		ele one = {"one", "1", 1};
		ele two = {"two", "2", 2};
		ele three = {"three", "3", 3};
		ele* ptr2 = &one;
		if(!ptr2) {
				printf("\n");
				printf("ele: %s\nsymbol: %s\natomic mass: %d\n", ptr2->name, ptr2->symbol, ptr2->mass);
				perror("it ran successfully: ");
		}else{
				perror("ERROR: ");
				perror("ERROR 1: ");
				perror("ERROR 2: ");
		}
		
		return 0;
}
