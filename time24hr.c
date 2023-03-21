#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// *******************  NOT FINISHED  *******************************

int main(int argc, char** argv) {
		int SIZE = 64;
		int len;
		char buffer[SIZE];

		puts("USING FGETS: Please enter the time in the following format: xx:xx:xxPM/AM");
		fgets(buffer, SIZE, stdin);
		buffer[strlen(buffer) - 1] = 0;
		len = strlen(buffer);

		// ERROR CHECKING
		int i = 0;
		if(strlen(buffer) != 10) {
				printf("incorrect length\n");
				exit(-1);
		}
/*		if(buffer[2] == ':' && buffer[5] == ':') {
				for(i=0;i<strlen(buffer)-2;i++) {
						if(!isdigit(buffer[i]) && !buffer[2] && !buffer[5]) { 
								printf("'%c'...Invalid character. It must be a number\n", buffer[i]);
								exit(2);
						}else{
								continue;
						}
				}
				if((atol(&buffer[0])) > 12) {
						printf("hours number cannot be greater than 12\n");
						exit(3);
				}else if((atol(&buffer[0])) < 0) {
						printf("hours number cannot be less than 0\n");
						exit(3);
				}else if((atol(&buffer[0])) == 0) {
						printf("Invalid hours input. Cannot be 00\n");
						exit(3);
				}
				if((atol(&buffer[3])) > 59) {
						printf("mins number cannot be greater than 59\n");
						exit(4);
				}else if((atol(&buffer[3])) < 0) {
						printf("mins number cannot be less than 0\n");
						exit(4);
				}else if((atol(&buffer[3])) == 0) {
						printf("Invalid mins input. Cannot be 00\n");
						exit(4);
				}
				if((atol(&buffer[6])) > 59) {
						printf("seconds number cannot be greater than 59\n");
						exit(5);
				}else if((atol(&buffer[6])) < 0) {
						printf("seconds number cannot be less than 0\n");
						exit(5);
				}else if((atol(&buffer[5])) == 0) {
						printf("Invalid seconds input. Cannot be 00\n");
						exit(5);
				}
		}else{
				printf("incorrect format: USE: xx:xx:xxPM/AM\n");
				exit(1);
		}
*/
//		// Why is this fucking up....???
//		if(buffer[8] != 'p' || buffer[8] != 'P' || buffer[8] != 'a' || buffer[8] != 'A') {
//				printf("Error, must be a pm or am in format\n");
//				exit(6);
//		}

/*		// METHOD SSCANF....WORKS WELL.....
		char* AMPM = &buffer[8];
		char time[SIZE];
		sscanf(buffer, "%[^a-zA-Z]", time);
		printf("%s\n", time);

		char* endstr = NULL;
		long longnum;
		int base = 10;
		if(*AMPM == 'P' || *AMPM == 'p') {
				//strtol will stop at first non-number, and so endstr holds rest of string
				if((longnum = strtol(buffer, &endstr, base)) < 12) {
						longnum = longnum + 12;
						endstr[strlen(endstr) - 2] = 0;
						printf("%ld%s\n", longnum, endstr);
				}
		}else if(*AMPM == 'A' || *AMPM == 'a') {
				if((longnum = strtol(buffer, &endstr, base)) == 12) {
						longnum = longnum - 12;
						endstr[strlen(endstr) - 2] = 0;
						printf("%02ld%s\n", longnum, endstr);
				}
		}else{
				printf("error, not a valid am or pm format\n");
				exit(1);
		}
*/	

		// STILL NEED TO WORK ON THIS...
// NOT FINISHED this strtok part

		// METHOD using strtok  (strtol may be better since it will leave a pointer to AM/PM...)
		// Just need to get rid of the last token 'M', then do the conversion for 24hr
		char delimiters[] = ":PpAa";	//This enables multi-delimiters to be scanned
		char* token = strtok(buffer, delimiters);
		while(token != NULL) {
				printf("inside %s\t", token);
				token = strtok(NULL, delimiters);
		}
		printf("\n");

		//alternative individual way of breaking it up.
		char* hours = strtok(buffer, ":");
		char* mins = strtok(&buffer[3], ":");
		char* seconds = strtok(&buffer[6], "%[^a-zA-Z]");
		printf("the time %s:%s:%s\n", hours, mins, seconds);
		
		
/*
		// CONVERSION TO INTS METHOD.....NEED TO FINISH
		// Pointers
		int Inthours = atoi(hours);
		int Intmins = atoi(mins);
		int Intseconds = atoi(seconds);
		char* AMPM = &buffer[8];

		printf("atolhours = %d\n", Inthours);
		printf("atolmins = %d\n", Intmins);
		printf("atolseconds = %d\n", Intseconds);
		// WHY ISN'T THIS AMPM WORKING....???
		printf("*AMPM = %c\n", *AMPM);

		if(*AMPM == 'p' || *AMPM == 'P') {
				if(Inthours <= 12) {
						Inthours = Inthours + 12;
						if(Inthours == 24) {
								Inthours = Inthours - 12;
						}
				}
		}else if(*AMPM == 'a' || *AMPM == 'A') {
				if(Inthours == 12) {
						Inthours = 0;
				}
		}

		printf("Here we are: %02d:%d:%d\n", Inthours, Intmins, Intseconds);
*/
		return 0;
}

