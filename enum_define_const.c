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

*******************  ENUMS  ********************************

		#define
		const int num
		enum 
		THESE 3 ARE ALL SIMILAR
		According to stack overflow, for C, enum is considered best. (enum is declared similar to how a struct is declared:

		enum weekdays {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
		enum weekdays day;
		day = Wednesday;
		printf("Wednesday is position %d in the days of the week\n", day);

		other example:
		enum weekdays {Sunday = 0, Monday, Tuesday, Wednesday = 10, Thursday, Friday = 15, Saturday};

		printing this out would give:
		0, 1, 2, 10, 11, 15, 16
		(Like a dictionary key value pairs)

		
*/
