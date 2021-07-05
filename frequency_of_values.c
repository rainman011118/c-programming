#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char** argv) {
		char input[64];
		scanf("%s", input);
		int inputlen = strlen(input);
		printf("input length: %d\n", inputlen);
		printf("%c\n", input[0]);			//WATCH: %d - This prints the ASCII version of the numbers!!!
		printf("%c\n", input[1]);			//AND: %c will print the actual numbers.
		printf("%c\n", input[2]);
		printf("%d\n", input[0]);
		printf("%d\n", input[1]);
		printf("%d\n", input[2]);


// ###############################################################################
		int array[] = {0,1,2,3,4,5,6,7,8,9};
		int len = sizeof(array) / sizeof(array[0]);
		printf("len of int array: %d\n", len);
	
		int count = 0;
		for(int i=0;i<len;i++) {
				for(int j=0;j<inputlen;j++) {
						if((array[i] + '0')  == input[j]) {
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


