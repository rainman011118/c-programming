#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int (*special_function)(int, int);

int add(int a, int b) {return a+b;}
int sub(int a, int b) {return a-b;}
int mul(int a, int b) {return a*b;}

typedef struct {
		char* function_name;
		special_function f;
} function_map_type;

#define NUM_FUNCTIONS 3
function_map_type function_map[NUM_FUNCTIONS] = {
		{"add", add},
		{"sub", sub},
		{"mul", mul}
};/*Here we basically declare the struct 'function_map[3]'.  And initialize the members with 'function name' and 'special_function f'.*/

special_function get_function(char* s) {/*the reason this is called special_function is because it returns a special_function...'add', 'sub' or 'mul'.  and get_function is the <name>*/
		for(int i=0; i<NUM_FUNCTIONS; i++) {
				if(strcmp(s, function_map[i].function_name)==0) {
						return function_map[i].f;
				}
		}/*This scans through the 3 members of function_map to see which matches the argc passed on the cmd line, then returns that function. */
		return NULL;
}

int main(int argc, char** argv) {
		if(argc != 4) {
				printf("USAGE\n\tfunction_caller f arg1 arg2\n");
				exit(1);
		}/*This checks to see if 4 argc are passed on cmd line.  (E.g. ./a.out add 5 7 = 4 x argc)*/
		special_function f = get_function(argv[1]);
		if(f==NULL) {
				printf("Invalid function\n");
				exit(1);
		}
		int a = atoi(argv[2]);
		int b = atoi(argv[3]);
		/*These represent the 3rd and 4th args passed on cmd line.  Not sure why atoi is used...?*/
		printf("a: %d, b: %d, %s(a,b): %d\n", a, b, argv[1], f(a,b));

		return 0;

}
/* https://www.youtube.com/watch?v=g1N_ttH0FQE */
