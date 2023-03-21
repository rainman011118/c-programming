#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// GETLINE OR FGETS.... READ LINE BY LINE....CONVERT TO ASCII...
// A simple program to read line by line, then convert the line into the equivalent ASCII letter
// FROM PICOCTF problem....when I did it before, the traditional way with ch = getchar(), it was simply reading every single character and so '112' was converted to 0x49 0x49 0x50 instead of 'p'.
// I think it can also be done using strtok, which is what I did on pico...

int main() {
				// Open file:
				FILE* fp = fopen("num.txt", "r");
				if(!fp) {
								fprintf(stderr, "Error opening file\n");
								exit(2);
				}

				//Set up buffer/pointer:
				size_t len = 64;
				ssize_t check = 0;
				char* p = malloc(len*(sizeof(char)));
				if(!p) {
								fprintf(stderr, "Error allocating memory\n");
								exit(1);
				}

				int x;
				char* endstr = NULL;
/*
				//MAIN PART: 
				//using getline to read each line (including '\n').
				//convert the string to and int with strtol
				//Cut off '\n' with strlen.
				//printing the char\ASCII version of the int.
				while((check = getline(&p, &len, fp)) != -1) {
								x = strtol(p, &endstr,10);
								p[strlen(p)-1] = 0;
								printf("%s = %c\n", p, x); 
				}
				printf("getline finished reading...check = %ld\n", check);
*/
	
/*			// ALTERNATIVE Using fgets and strtok to do the same thing:
				// See below for sscanf version...which seems a lot simpler...
				while(fgets(p, len, fp)) {
								x = strtol(p, &endstr,10);
								p[strlen(p)-1] = 0;
								printf("%s = %c\n", p, x); 

				}
*/

/*				// Using fread and fwrite
				fread(p, 1, len, fp);
				int length = strlen(p);
				printf("strlen: %ld\n", strlen(p));
				fwrite(p, 1, length, stdout);

				// Can't get this below working....how to move along the string...DON'T RUN!
				//Using sscanf
				while((sscanf(p, "%d", &x) != EOF)) {
								printf("x = %d\n", x);
				}
*/

				//This version of sscanf works :)
				//while((check = getline(&p, &len, fp)) != -1) {
				while(fgets(p, len, fp)) {
								sscanf(p, "%d", &x);
								printf("%d: %c\n", x, x);
				}




				fclose(fp);
				free(p);
				p = NULL;

				return 0;
}
