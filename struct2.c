#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	char name[40];
	int age;
	int roll_no;
	float marks;
} student;

void print_info(char name[], int age, int roll_no, float marks)
{
	printf("%s %d %d %.2f\n", name, age, roll_no, marks);
}

int main()
{
	student s1 = {"Jonny", 37, 5, 75.5};
	print_info(s1.name, s1.age, s1.roll_no, s1.marks);

	return 0;
}
