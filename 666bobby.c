#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void clearbuffer() {
		int ch;
		while((ch = getchar()) != '\n' && ch != EOF) {
					;
		}
}

// This is all working now without spill over and allows shorter inputs
// BUT, can improve it by adding or rather denying erroneous input e.g. ';lajs;lfjaljsdfj'
void student_info(struct student* ptr) {
		char* p;
		int a = '\n';// strchr character
		printf("Give the students ID, surname and firstname.\n");
		printf("ID: ");
		fgets(ptr->ID, 6, stdin);

		// ####################  Add checks for alphanumeric only ##############################
		
		if(p = strchr(ptr->ID, a)) {
				//printf("NEW LINE DETECTED\n");
				ptr->ID[strlen(ptr->ID)-1] = 0;
		}else{
				printf("ERROR, no newline detected, input must have been too long\n");
				clearbuffer();
		}
		printf("first name: ");
		fgets(ptr->f_name, 20, stdin);
		if(p = strchr(ptr->f_name, a)) {
				//printf("NEW LINE DETECTED\n");
				ptr->f_name[strlen(ptr->f_name)-1] = 0;
		}else{
				printf("ERROR, no newline detected, input must have been too long\n");
				clearbuffer();
		}
		printf("surname: ");
		fgets(ptr->s_name, 20, stdin);
		if(p = strchr(ptr->s_name, a)) {
				//printf("NEW LINE DETECTED\n");
				ptr->s_name[strlen(ptr->s_name)-1] = 0;
		}else{
				printf("ERROR, no newline detected, input must have been too long\n");
				clearbuffer();
		}

		printf("Info of the last student added:\nID: %s\nFirstname: %s\nSurname: %s\n", ptr->ID, ptr->f_name, ptr->s_name);
}

int main(int argc, char** argv) {
		struct student studentinfo;
		struct student* ptr = &studentinfo;	
		student_info(ptr);
	
		return 0;

}

