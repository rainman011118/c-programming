#include<stdio.h>

struct student {
int number;
char name[30];
float marks;
};

int main() {
struct student s[2];
int i;
for(i = 0; i < 2; i++) {
	printf("Enter details of student %d\n", i+1);
	scanf("%d%s%f", &s[i].number, s[i].name, &s[i].marks);
	}
for(i = 0; i < 2; i++) {
	printf("The details for student %d are:\n", i+1);
	printf("number = %d\n", s[i].number);
	printf("name = %s\n", s[i].name);
	printf("number = %f\n", s[i].marks);
	}
return 0;
}
