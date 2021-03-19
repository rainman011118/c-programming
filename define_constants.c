#include <stdio.h> // #define and 'const' commands

#define LENGTH 10
#define WIDTH 5
#define NEWLINE '\n'

int main()
{
	int area;

	area = LENGTH * WIDTH;
	printf("value of area : %d", area);
	printf("%c", NEWLINE);

	return 0;
}

/* This is the alternative way of using constants:
 	'const' command

It is good practice to define constants in CAPITALS

#include <stdio.h>
int main() {
	
	const int LENGTH = 10;
	const int WIDTH = 5;
	const char NEWLINE = '\n''
	int area;

	area = LENGTH * WIDTH;
	printf("value of area : %d", area);
	printf("%c", NEWLINE);

	return 0;

	}
*/
