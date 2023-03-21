#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv) {

		// strtol method which helps isolate digits. If the first char is not a digit, then it returns 0
		float mins;
		int secs;
		int size = 8;  // I could put size = 3, but fgets automatically null terminates, so you will only get digits 1,2
		char* ptr = NULL;
		int VAL;
		char buff[size];

		puts("Enter a number and we will try to convert it into minutes and seconds");
		fgets(buff, size, stdin);
		buff[strcspn(buff, "\n")] = 0; 
		if((VAL = strtol(buff, &ptr, 10)) == 0) {
				printf("Invalid char entered. It must start with a number\n");
				exit(1);
		}else{
				printf("VAL = %d\n", VAL);
				printf("ptr = %s\n", ptr);
		}

		mins = (float)VAL / 60;
		secs = VAL % 60;
		printf("In minutes: %.2f minutes\n", mins);
		printf("using modulus to get the seconds: %d seconds\n", secs);
		printf("Final: %d seconds = %dmins %dseconds\n", VAL, (int)mins, secs);

		return 0;
}

