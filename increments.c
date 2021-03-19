#include <stdio.h>
int main()
{
	/* ++i increments i before i is used
	   i++ increments i after i is used
	   */
	int a = 1, b = 1;
	//int a;
	//int b;
	//a = 1;
	//b = 1;
	printf("increments and decrements, before and after\n");
	printf("%d, %d\n", ++a, b++);
	printf("%d, %d\n", a, b);

	printf("%d\n", a = b++); // 2 = 2+1(3)
	printf("%d\n", a = ++b); //2 = 3+1(4)
	return 0;
}
