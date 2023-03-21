#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv) {
		char input[10];
		puts("Enter a number:");
		scanf("%10s", input);
		int inputlen = strlen(input);

		//This is just an extra check (the %10s in scanf limits input anyway)
		if(inputlen > 9) {
				printf("ERROR, too many characters entered. Cannot exceed 10\n");
				exit(1);
		}
		printf("input length: %d\n", inputlen);
		//I could also do a check for non-numeric chars, but they are read as 0 anyway.

// ###############################################################################
		char array[] = {0,1,2,3,4,5,6,7,8,9};
		int len = sizeof(array) / sizeof(array[0]);
	
		int count = 0;
		for(int i=0;i<len;i++) {
				for(int j=0;j<inputlen;j++) {
				//NOTE: It doesn't matter if I declare a char array, or int array, below works exactly the same. You have to add the " +'0' ". // BUT WHY? Isn't an INT 0 == decimal 0??.....YES, but char 0 also == decimal 0. (SEE END!!).
						if((array[i] + '0')  == input[j]) {	//eg Decimal 0 + char '0'(decimal48) = decimal 48
								count++;
						}
				}
				printf("value %d appears %d times.\n", array[i], count);
				count = 0;
		}
		
/*FINALLY.....God damn time!! the "+ '0' " worked!!! Mother fucker!! 2 days.....God dman!!   
		This finally solved the hackerrank challenge  */
		return 0;

}

/*
  ####################################################################
// FIGURED IT!!
// Input on screen is interpreted as ASCII, so 0-9 = decimal 48-57, BUT, if I declare an array 0-9, it is interpreted as it is: decimal 0-9!!!!!

				    int array[] = {0,1,2,3,4,5,6,7,8,9};
						char array2[] = {0,1,2,3,4,5,6,7,8,9};
						printf("int array[0] = d%d and c%c\n", array[0], array[0]);
						printf("char array[0] = d%d and c%c\n", array2[0], array2[0]);
						exit(1);

						//Why do both these print statements print the same? Why is %d for char array2[1] == 1?? Decimal 1 = garbage..? Whereas ASCII 1 == 1 == decimal 49...BECAUSE THEY ARE THE SAME (declared, not interpreted)

						*/
