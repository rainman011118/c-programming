#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define BUFFERSIZE 16

typedef struct {
		char *name;
		char race[BUFFERSIZE];
		char type[BUFFERSIZE];
		int lvl;
} wow;

void display(wow x) {
		printf("name: %s\nrace: %s\ntype: %s\nlvl: %d\n", x.name, x.race, x.type, x.lvl);
}

void c2ptrdisplay(wow* y) {
	printf("Pointer accessing for c2:\nname: %s\nrace: %s\ntype: %s\nlvl: %d\n", y->name, y->race, y->type, y->lvl); 
}
int main(int argc, char** argv) {
	wow c1 = {"Ace", "Tauren", "Shaman", 60};
	wow c2 = {"Max", "Goblin", "Priest", 55};
	wow c3 = {"Justice", "Human", "Paladin", 45};
	display(c1);
	display(c2);
	display(c3);
	printf("size of struct: %lu\n", sizeof(wow));	
	printf("size of int: %lu\n", sizeof(int));	

	puts("Updating c1 details:");
	//strncpy(c1.name, "Rufus", BUFFERSIZE);DON'T DO THIS!!! SEG FAULT. how can you copy a string to nothing...???
	strncpy(c1.race, "Troll", BUFFERSIZE);
	strncpy(c1.type, "Hunter", BUFFERSIZE);
	c1.lvl = 15;
	c1.name = "Rufus";//This assigns the string literal to the pointer. So it is technically READ-ONLY. So I could have made race and type both pointers as well BUT I would not be able to alter them.
	display(c1);

	wow* ptr = &c2;
	c2ptrdisplay(ptr);

	return 0;
}

/*I have basically created 3 structs and assigned values to each on declaration.  Their sizes are already defined except maybe for the *name.  therefore, no pointers to struct are needed however, it is still a viable way to create more struct objects.  E.g. If I was to be inputting an unknown number of objects and values, then creating a pointer to malloc would be the preferred method.  wow* ptr = malloc(10*sizeof(wow))
 */
