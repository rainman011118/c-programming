#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
		char firstname[32] = "Doctor ";
		char secondname[16];
		strcpy(secondname, "Strange");
		
		char* fullname = strcat(firstname, secondname);
		printf("%s\n", fullname);

		//NOTE: following strcat, firstname has now changed...NOT expected.
		printf("%s\n", firstname);
/*If I have the above strcat running, then the while loop below doesn't stop at '\0' and instead runs over and prints both names.....??....THERE IS THE PROBLEM: strcat is putting 'secondname' on the end of 'firstname' so when I print firstname on it's own, both names then come out!  NEED TO FIND OUT HOW STRCAT WORKS.  If I need to allow for ample room in the array before strcat'ing.  Looks like I need to allow for enough room in the array beforehand.  Since strcat simply appends it onto the end....that's why the loop keeps running over...*/

		int i = 0;
		while(firstname[i] != '\0') {
				printf("%d: %c\n ", i, firstname[i]);
				i++;
		}
		/*
		for(int j=9;j>0;j--) {
				printf("%c ", firstname[j]);
		}
	*/	
	
		return 0;
}

