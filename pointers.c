#include <stdio.h>
int main()
{
	int First_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int *ptr;
	ptr = First_array;
	int x = sizeof(First_array) / 4;

	printf("Value of *ptr variable = %d\n", *ptr);
	printf("Address of ptr variable = %p\n", ptr);

	//for (int i = 0; i < 10; i++)
	for (int i = 0; i < x; i++)
	{
		printf("%d\n", First_array[i]);
	}

	/*while (*ptr < 10)
	{DANGEROUS!!! DANGEROUS!!!! DO NOT USE!!
		printf("%d", *ptr);
		*(ptr + 1);
	}*/
	return 0;
}
