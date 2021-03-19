#include <stdio.h>
int main()
{
	int i;
	for (i = 1; i <= 5; i++)
	{
		printf("%d\n", i);
	}
	int x;
	for (x = 10; x > 0; x--)
	{
		printf("%d\n", x);
	}
	return 0;
}
/* The for statement reads:
	   i = 1 is the starting value of i.
	   i <= 5 is the condition to be met.
	   i++ is the increment value (go up by 1 each loop).
	   (i-- would be decrement by 1 each loop).
	 */
