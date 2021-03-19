#include <stdio.h>

int main()
{
	int array[5];
	int size = sizeof(array);
	printf("size of array start: %d\n", size);

	int i;
	int *p = (int*)array;
	//This loop, fills up the array:
	for(int i = 0; i < 5; i++) {
		printf("Enter a number: ");
		//method 1) scanf("%d", &array[i]);
		//method 2) using pointer:
		scanf("%d", &p[i]);
	}
	//This loop, prints out the array values:
	for(i = 0; i < 5; i++) {
		/*Method 1)printf("array[%d]: [%d]\n", i, array[i]);*/

		//Method 2 using pointer:
		printf("%d ", *p);
		p++;
	}
	printf("\n");

	return 0;
}



