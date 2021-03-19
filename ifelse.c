#include <stdio.h>

int main()
{

	/* local variable definition */
	int a = 100;

	/* check the boolean condition using if statement */
	if (a == 10)
	{
		printf("Value of a is 10\n");
	}
	else if (a == 20)
	{
		printf("Value of a is 20\n");
	}
	else if (a == 30)
	{
		printf("Value of a is 30\n");
	}
	else
	{
		printf("None of the values is matching\n");
	}

	printf("Exact value of a is : %d\n", a);

	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	if (num % 2 == 0)
	{
		printf("your number is %d and it is an even number\n", num);
	}
	else
	{
		printf("your number is %d and it is an odd number\n", num);
	}

	return 0;
}
