#include <stdio.h> 

#define LENGTH 10
#define WIDTH 5

int main()
{
	int area = LENGTH * WIDTH;
	printf("value of area : %d\n", area);

	return 0;
}

/* This is the alternative way of using constants:
 	'const' command

It is good practice to define constants in CAPITALS

#include <stdio.h>
int main() {
	
	const int LENGTH = 10;
	const int WIDTH = 5;

	int area = LENGTH * WIDTH;
	printf("value of area : %d\n", area);

	return 0;

	}
*/
