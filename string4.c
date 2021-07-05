#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv) {
		char str[] = "This is a string literal assigned on declaration.";//almost...it's actually an array.
		printf("%s\n", str);
		printf("%c\n", *(str+1));

		int str_size = strlen(str);
		printf("strlen: %d\n", str_size);
		
/*These are not giving me the last chars in the array.  They are just returning ASCII values */
		printf("strlen-1: %d : %c\n", str_size - 1, str_size - 1);
		printf("strlen-2: %d : %c\n", str_size - 2, str_size - 2);
		
		char* ptr = &str[10];//pointer to the start of 10th element.
		printf("ptr: %s\n", ptr);
		int ptr_size = strlen(ptr);
		printf("ptrlen: %d\n", ptr_size);
/*##################################################################
		Playing around with changing values.  I assign a string literal to the ptr and this works.  But has not changed the original 'str[10]' onwards????. From now on, look at it as:
		char* = char pointer
		char** = char pointer to a block of pointers
		And whatever follows it is just the name of the variable..*/
		printf("NOTE:ptr before ABCD assignment: %p\n", ptr);

		ptr = "ABCD";//This is allowed..probably because "ABCD" is an array of chars/technically a memory address. But it also will work if a single letter is assigned with "D".(so double quotes must = mem addrs).  It will not work with single quotes, nor will 'ABCD'
		printf("ptr is now: %s - and is now pointing to somewhere completely different in memory.\n&str[10] is: %s\n", ptr, &str[10]);	
		printf("ptr[1] is: %c\n*&ptr[0] (which is the same as ptr[0]) is: %c\n", ptr[1], ptr[0]);
		printf("NOTE:ptr after ABCD assignment: %p\n", ptr);
		/*Changing the values of the string: You can change individual chars but you can't add a string literal. */
		str[1] = 'H';
		printf("%s\n", str);
		//*(ptr+1) = 'T';//This will be a SEG FAULT, if I have reassigned ptr to "ABCD", because there is no ptr+1.  There is only ptr which contains "ABCD". Also, you cannot change the individual chars using: (ptr[3] = 'y') because "ABCD" was assigned as a string literal and not an array.  (If I had put: ptr[] = "ABCD", then I could change the elements.)
		printf("%s\n", ptr);
		
		int i = 0;
		while(str[i] != '\0') {
				if(str[i] == 's') {
						str[i] = 'z';
						i++;
				}else {
						i++;
						continue;
				}
		}
		printf("Changed str: %s\n", str);
		return 0;

}
/*This nested statement didn't work.  'invalid type argument of unary '*' (have 'int').
"*str[i]" was the problem.
			if(*str[i] == 's') {
					*str[i] = 'z';
			}else {
					continue;
			}
Looking back at this, the '*' needs to be removed so it reads 'str[i]'.  This would access the vaule.  Also if I wanted to change all the 's' to 'z', then I could do something like this:
while(str[i] != '\0') {
	if(str[i] == 's') {
		str[i] = 'z';
	}
}
....DONE and it worked!  YES!!!  */
