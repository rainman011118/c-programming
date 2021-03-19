#include<stdio.h>

struct student {
int number;
char name[30];
float marks;
};

int main() {
struct student s;
struct student *sptr;

printf("Enter number, name, marks\n");
scanf("%d%s%f", &s.number, s.name, &s.marks);

sptr = &s;

printf("Number = %d\n", sptr->number);
printf("Name = %s\n", sptr->name);
printf("Marks = %f\n", sptr->marks);

return 0;
}
