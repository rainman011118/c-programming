#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
		int data;
		char* name;
		int age;
}Person;


int main(int argc, char** argv) {
		Person p = {76, "Marcus Aurelius", 99};
		Person* ptr = &p;
		printf("ptr method: %d\n%s\n%d\n", ptr->data, ptr->name, ptr->age); 
		printf("dot method: %d\n%s\n%d\n", p.data, p.name, p.age); 
		
		Person p1;
		p1.data = 22;
		p1.name = "Cyclops";//This worked!?  I didn't have to use strcpy??? When I did use strcpy, it SEGFAULTED! This may be because p1.name is a pointer to chars but of unknown size, so copying a string literal to unknown = SEGFAULT. (If it was an array, strcpy would work fine)  But if you assign a string literal to the pointer, it is creating space...that doesn't exist.  DOUBLE CHECKING THIS, IT CAN'T BE CORRECT. SINCE IT IS BASICALLY SAYING THAT P1.NAME POINTS TO A NEW STRING SOMEWHERE, AND NOT NECESSARILY WITHIN THE STRUCT.  THEREFORE, IT IS BETTER TO MALLOC IT TO SPECIFY SIZE.
		p1.age = 103;
		printf("dot method: %d\n%s\n%d\n", p1.data, p1.name, p1.age); 
		
		Person* p2 = malloc(sizeof(Person));
		if(p2 == NULL) {
				fprintf(stderr, "Memory allocation failed!\n");
				exit(1);
		}
		printf("sizeof: %lu\n", sizeof(Person));
	//	p2->data = 77;
	//	p2->name = "Jack";
	//	p2->age = 19;
/*WARNING: https://stackoverflow.com/questions/13907684/scanf-doesnt-work-in-malloc-struct-members.
p2->name = "jack"....This is not recommended.  Instead I should put: p2->name = (char*)malloc(n * sizeof(char)). This will now work with scanf p2->name. Even though these 3 assignments all worked, it is best to follow good practice and malloc the p2->name.  When memory is allocated for a struct, it only creates memory for the entire struct and NOT for the pointer to name.
*/
		//scanf("%d%s%d", &p2->data, p2->name, &p2->age);
		printf("data: %d\nname: %s\nage: %d\n", p2->data, p2->name, p2->age);

		free(p2);
		return 0;

}

