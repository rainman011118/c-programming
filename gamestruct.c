#include <stdio.h>
#include <stdlib.h>
//SEE: https://lazyfoo.net/tutorials/SDL/01_hello_SDL/linux/cli/index.php

typedef struct
{
	int x, y;
	short life;
	char *name;
} Man;

void structs()
{
	Man man1, man2;

	man1.x = 50;
	man1.y = 50;
	man1.life = 100;
	man1.name = "enemy1";

	man2.x = 50;
	man2.y = 50;
	man2.life = 100;
	man2.name = "enemy1";

	printf("name of man2: %s\n", man2.name);
	//This next bit is a loop for eg create 100 characters(structs):

	/*for(int i = 0; i < 100; i++) {
		  man[i].x = 0;		//initialise
		  man[i].y = 0; 	//initialise
		  man[i].life = 100;	//100 life
		  man[i].name = "enemy1";
		  }

	 */
}

int main()
{
	structs();
	return 0;
}
