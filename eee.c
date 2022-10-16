#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//TWO SEPARATE PROGRAMS: ONE DEALING WITH ARGC AND ARGV, THE OTHER WITH SCANF
//THIS SCANF WORKS FINE, EVEN WITH LOADS OF INPUT....
//BUT HOW CAN I REJECT INPUT THAT IS GREATER THAN 1CHAR????

int main(int argc, char** argv) {
		int check;
		char cat[] = "CAT";
		char dog[] = "DOG";
		
		if(argc == 1) {
				printf("Incorrect use.  Please input '%s <password>'\n", argv[0]); 
				printf("argc = %d\n", argc);
				;//I had to add this argc == 1 bit because it was segfaulting if I didn't check for this
				//If I entered './a.out '(NOTE THE SPACE), it went straight to the else clause and must interfere with the check = strcmp...???
		}else if(argc > 2) {
				printf("Error: Use: %s <string>\n", argv[0]);
				exit(1);
		}else{
				printf("argv[1] = %s\n", argv[1]);// argv[1] = (null) if only './a.out' is input.  If I press space or spaces, this too causes segfault with argc[1] = (null).
				if((check = strcmp(argv[1], cat)) == 0) {
						printf("MATCH! CAT\n");
						return 0;
				}else if((check = strcmp(argv[1], dog)) == 0) {
						printf("MATCH! DOG\n");
						return 0;
				}else{
						printf("Incorrect! Try again\n");
						exit(1);
				}
		}

		/*
		unsigned char a;
		char buf[8];
		int ch;
		memset(buf, 0, sizeof(buf));
		printf("strlen(buf) = %lu\n", strlen(buf));
		for(int i=0;i<8;i++) {
				printf("0x%x ", buf[i]);
		}
		printf("\n");
		for(int i=0;i<8;i++) {
				printf("%d ", buf[i]);
		}
		printf("\n");
		puts("Enter a choice 1, 2, 3");
		scanf("%c", &a);
		printf("The input value is: '%c' 0x%x and %d\n", a, a, a);
		*/
		/*
		if(

		*/
		printf("The end\n");

		return 0;
}

