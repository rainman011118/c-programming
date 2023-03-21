#include<stdio.h>
#include<stdlib.h>

//Just testing a swtich statement. Statement works fine, but overall this is not finished.

int main(int argc, char** argv) {
				char x, y, sum;
				char operator;
				puts("Please enter a number between 1-100");
				scanf("%c", &x);
				puts("Please enter another number between 1-100");
				scanf("%c", &y);
				getchar();
				getchar();

				puts("Do you want to add, subtract or multiply these numbers? Type '+', '-' or '*'");
				scanf("%c", &operator);

				switch(operator) {
								case '+': 
												sum = x + y;
												break;
								case '-':
												sum = x - y;
												break;
								case '*':
												sum = x * y;;
												break;
								default:
												printf("Invalid operator entered\n");
												exit(1);
				}
				printf("Sum = %d\n", sum);


				return 0;
}

