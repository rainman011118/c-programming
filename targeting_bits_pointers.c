#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv) {
	int x = 1025;			//00000000 00000000 00000100 00000001
	int* p = &x;
	char* p1 = (char*)&x;	//Typecasting (char*) = targets lower 8bits of the value. NOTE: I can typecast this to the INT or the POINTER. Both work the same.

	int y = 65537;
	short* pp = (short*)&y;	//This works also to give the 16bit value eg 263169 = 1025
	int* p2 = p;			//Each of these points to the same thing as p.		
	int* p3 = p;			//We have assigned p to each = they all hold &x;	
	int* p4 = p;			//Therefore dereferencing each = value at x;
	//Likewise if these were all char* p2,3,4, then the lower 8bits would be targeted only.

	int** p5 = &p;			//double pointer = holds address of p. So **p5 = 1025.
	//Likewise: char** p5 = (char**)&p will do the same thing but at 8bits only.

	printf("add of p = %p\nvalue of p = %d\nadd of P1 = %p\nvalue of p1 = %d\n", p, *p, p1, *p1);
	printf("add of p2 = %p\nvalue at p2 = %d\n", p2, *p2);
	printf("*p2 = %d\n*p3 = %d\n*p4 = %d\n", *p2, *p3, *p4);
	printf("*p5 = %p\n**p5 = %d\n", *p5, **p5);
	printf("*pp = %d which is the 2byte value of 65,537\n", *pp);

	return 0;

}

/* You can have multiple pointers all pointing to the same object.
*/

