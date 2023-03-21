#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Program to check a 3 digit number input.

//FINISHED............ with the ch = getchar() method. this getchar() is particularly useful here as it deals with the automatic conversions between char and int, that I was having problems with previously.

int main(int argc, char** argv) {
		char chh = 53; // this is just for learning purposes.	
		int ch = 53;
		printf("ch = 0x%08x, %d, %c\n", ch, ch, ch);
		printf("chh = 0x%x, %d, %c\n", chh, chh, chh); // I just added this to compare 1byte to 4byte in hex.  0-127 = 2digits output. But as soon as you go 128+, it outputs the whole 8bits, I guess because it gets SIGN EXTENDED to negative. i.e. I don't have to specify width.

		int sum = 0;
		int max_num = 0; // I have used this like a timer, so each time a digit is registered in the while loop, it increments.  Once 3 digits are recorded, the loop condition is breached.  (I guess an alternative is to use a pointer...)
		while((ch = getchar()) != '\n' && ch != EOF && max_num < 3) {
			if(isdigit(ch)) {
//			if(ch >= '0' && ch <= '9') {//This is the verbose equivalent of isdigit()
				printf("ch formats: 0x%02x %d %c\n", ch, ch, ch);
				ch = ch-'0';
				printf("Number = %d\n", ch);
				sum += ch;
				max_num++;
		//Everything below this is irrelevant for the question's aim.
			}else if(isalpha(ch)) {
				printf("Invalid input. You entered a letter: %c\n", ch);
				break;
			}
		}
		printf("The sum of %d digits = %d\n", max_num, sum);

		return 0;
}


/*My previous attempts....was getting screwed over with the char and int conversions in an array and with the ascii inputs....
		int SIZE = 8;
		char num[SIZE];
		int MAX = 4;
		int num_check = 0;
		int mark = 0;
		puts("Starting program...");
		puts("Please enter a 3 digit number:");
		scanf("%d", &ch);
		if(ch >= '0' && ch <= '9') {
				printf("This is working\n");
		}else {
				printf("Number input = %d\n", ch);
				printf("something is still wrong\n");
		}
*/
/*
		while(num_check == 0) {
				printf("Please enter a 3 digit number:\n");
				fgets(num, MAX, stdin);
				printf("num(s) = %s\n", num);
				int number = atoi(num);
				printf("number = %d\n", number);
				if(strlen(num) < 4) {

				if((isdigit(number)) == 1) {
						printf("number = %d\n", number);
						mark += 1;
				}else {
						printf("Invalid number\n");
						continue;
				}

//				if((atoi(num)) == 123) {
//						printf("Valid conversion using atoi: %d\n", atoi(num));
//						num_check = 1;
//				}
				sscanf(num, "%d", &num_check);
		}
*/
/*
		//While loop set to infinite, until all conditions are met
		while(num_check == 0) {
				printf("Enter a 3 digit number:\n");
				//fgets: scan upto 8chars(SIZE). Whatever the 8th char is, gets replaced by 0.
				fgets(num, SIZE, stdin);
				printf("strlen(num) before the chop = %ld (includes the 'new line/enter')\n", strlen(num));
				//num[strlen(num)-1] = 0;
				printf("strlen(num) after the chop = %ld\n", strlen(num));
				printf("num is: %s\n", num);

//				HAVING A PROBLEM WHEN I ENTER A LONG NUMBER LIKE 6666666666666. THE REMAINING ONES AFTER THE SIZE CUTOFF ARE STILL IN THE BUFFER AND AUTOMATICALLY GET FED BACK IN...????

				//check for a 3 digit number only:
				if(strlen(num) != 3) {
						printf("Invalid input: 3 digit number required\n");
						continue;//Looks like this take you straight back to the beginning of while loop. WHEREAS 'BREAK' simply breaks out of immediate loop and continues to next step below.
				}
				//check that the characters entered are valid numbers (True(1) or False(0)): ERROR: it is not checking all the digits, only the first digit....?
				puts("checking if this sscanf check comes directly after continue\n");
				if((sscanf(num, "%d", &num_check)) != 1) {
						printf("Invalid character entered\n");
						num_check = 0;
						continue;
				}
//				if((isdigit(num_check)) != 1) {

				//This below loop, prints out the DECIMAL REPRESENTATIONS of the CHARS entered. So if I enter: 101, it will print out 49 48 49. (ASCII for 1 = decimal 49, ASCII for 0 = decimal 48).
				for(int i=0;i<strlen(num);i++) {
						if(!(isdigit(num[i]))) {
								printf("%d : Invalid input: not a digit\n", num[i]);
								num_check = 0;
								break;
						}else {
								printf("%d ", num[i]);
						}
						printf("\n");
				}
				//If all is ok, store the num into num_check
				sscanf(num, "%d", &num_check);
		}
		printf("Number ok: %d\n", num_check);
		puts("...End of program");
*/		
		
