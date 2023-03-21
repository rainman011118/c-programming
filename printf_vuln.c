#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


// So this is why 'printf(buffer)' is so vulnerable.....
// If you write specifiers when reading input, printf interprets it and dumps the stack.. :O
int main() {
				char buffer[21];
				scanf("%20s", buffer);
				printf(buffer);
				printf("\n");


				return 0;
}
