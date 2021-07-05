#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv) {

		//DO NOT DO THIS!!
//		char* name = malloc(25);
//		name = "The incredible Hulk";
		//I have declared a pointer to a block of memory called 'name'.  then next line, I assign the pointer 'name' to a string.  Therefore, the pointer is no longer pointing to the block of memory and I will not be able to free it later.  HENCE: why I got the error (after running it :s) free(): invalid pointer. Aborted (core dumped). !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
		//What you should do: #######################################################################
		const char* name = "The Incredible Hulk";
		char* p = malloc(strlen(name)+1);
		strcpy(p, name);

		printf("char name address: %p\n contents: %s\n", name, name);
		printf("p address: %p\n contents: %s\n", p, p);

		free(p);
		p = NULL;
		return 0;
}
/* Whenever you have a string literal that you know will not be modified, then declaring it as follows is fine:
 * const char* name = "Iron Man";  
 * so basically if you do not know the size of the strings at runtime, then use malloc.  Otherwise just direct assign as shown using const.
 */
