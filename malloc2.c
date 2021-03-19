#include <stdio.h>
#include <stdlib.h>

struct emp
{
	int num;
	char name[20];
	float marks;
};

int main()
{
	struct emp emp1;
	printf("Size of struct emp is: %lu\n", sizeof(struct emp));
	struct emp *ptr = (struct emp *)malloc(sizeof(struct emp));
	if (ptr == NULL)
	{
		printf("Error allocating memory!\n");
		return 1;
	}

	printf("Enter emp num, name, marks: ");
	scanf("%d%s%f", &ptr->num, ptr->name, &ptr->marks);
	printf("Emp details are:\nnum = %d\nname = %s\nmarks = %.2f\n", ptr->num, ptr->name, ptr->marks);

	free(ptr);

	return 0;
}
