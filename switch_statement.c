#include <stdio.h>

int main() 
{
	char operator;
	double n1, n2;
	printf("\nEnter an operator (+, -, *, /): \n");
	scanf("%c", &operator);
	printf("\nEnter two operands: \n");
	scanf("%lf %lf", &n1, &n2);
	switch(operator)
	{
		case '+':
			printf("%.1lf + %.1lf = %.1lf\n", n1, n2, n1 + n2);
			break;
		case '-':
			printf("%.1lf - %.1lf = %.1lf\n", n1, n2, n1 - n2);
			break;
		case '*':
			printf("%.1lf * %.1lf = %.1lf\n", n1, n2, n1 * n2);
			break;
		case '/':
			printf("%.1lf / %.1lf = %.1lf\n", n1, n2, n1 / n2);
			break;

		default:
			printf("Error! operator is not correct!\n");
	}
	return 0;

}
