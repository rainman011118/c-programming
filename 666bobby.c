#include<stdio.h>
#include<stdlib.h>

/*SEE: https://stackoverflow.com/questions/55768118/problem-with-getting-user-input-for-a-struct
I didn't quite understand the answer given to this question but playing around with the order of f_name and s_name in the struct seems to affect the outcomes.  Must be due to being back to back in memory.
enter: 666666 boi bobby results in: 666666bobby boi bobby.(Because f_name comes straight after ID in the struct, it is next to it in memory,hence why it runs over into it.)
swap s_name and f_name order in struct and same input results in: 666666boi boi bobby.
So, scanf stores 666666, but there is no room for the NULL terminator, so when printf executes, it prints: 666666bobby.  No NULL means it runs straight into what comes next = f_name.  Then the next two %s are read as normal. */

struct student {
		char ID[6];
		char f_name[20];
		char s_name[20];
};

void student_info(struct student* ptr) {
		printf("Give the students ID, surname and firstname.\n");
		scanf("%s%s%s", ptr->ID, ptr->s_name, ptr->f_name);
		printf("Info of the last student added: %s %s %s\n", ptr->ID, ptr->s_name, ptr->f_name);
}


int main(int argc, char** argv) {
		struct student studentinfo;
		struct student* ptr = &studentinfo;	
		
		student_info(ptr);
		




		return 0;

}

