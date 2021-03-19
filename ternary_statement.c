#include <stdio.h>
int main() {
	int a, b, max;

	printf("Enter any two numbers \n");
	scanf("%d%d", &a, &b);
	/*Follwing statement replaces the whole if-else statement
	  and makes the code more concise
	*/
	max = (a > b) ? a : b;
	/*The statement reads:
	 	max is = a > b.  If this is true, then a should be greater,
		else, b should be greater.
	*/
	//printf("%d\n", max);
	printf("%d is the largest number of given numbers\n", max);

	return 0;

}
