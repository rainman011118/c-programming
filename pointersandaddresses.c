#include <stdio.h>
#include <string.h>

int main()
{
	char list[] = {1, 5, 32, 25, 27, 55, 97, 69, 83, 42, 22, 19, 2};

	printf("Address of list = 1st index[i] = %p\n", list); //already a pointer because it is an array.
	printf("You can access the list elements just by typing list[4] etc.\n");
	printf("list[3] = %d\n", list[3]);
	list[3] = 100;
	printf("updated list[3] = %d\n", list[3]);
	printf("To access all the elements, use a loop.\n");
	printf("*(list+6) value at index [6] = %d\n", *(list + 6));
	printf("(*list+6) aka Value at &[0] then add 6 to it = %d\n", (*list + 6));

	printf("NOTE: strlen(list) = %lu\n", strlen(list));
	printf("sizeof(list) = %ld\n", sizeof(list));
	printf("sizeof used on 'int list' will return 52 (13 x 4b) = size in bytes\nsizeof used on 'char list' will return 13 = No. of items\n");
	printf("Alternate way: is sizeof(list) / sizeof(list[0]) = %ld\n", sizeof(list) / sizeof(list[0]));
	printf("Note: if I name the list 'int' list, the strlen(list) doesn't work.\nThis is because strlen only works on chars not ints.\n");

	int i = 0;

	//int i = 0;
	//printf("The length of the list is %zu.", strlen(list));
	/*
	while (i = 1; i < strlen(list); i++)
	{
		printf("%d %d\n", i, list[i]);
*/
	return 0;
}
