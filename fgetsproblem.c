#include<stdio.h>
#include<string.h>
int main()
{
	char str1[20], str2[20];
	printf("Enter 1st string: ");
	fgets(str1, 20, stdin);

	printf("Enter 2nd string: ");
	fgets(str2, 20, stdin);
	
	printf("\nstr1: %s\nstr2: %s\n", str1, str2);
	/*If I enter more than 20 characters in first input str1, then str2 input is automatically skipped and the two printf statements are executed with the chars > 20 being output as str2...? So there must be a buffer...storing the extra chars....
	 * */

	/*
	if (strcmp(str1, str2) == 0) {
		printf("Strings are equal\n");
	} else {
		printf("Strings are not equal\n");
	}
	*/

	return 0;

}
/*	The use of the 'gets' fn is considered dangerous:
	 - It can lead to buffer overflow
	 - If a user inputs more characters than is specified [20],
	 then buffer overflow can result, and may crash the system.
	  - 'scanf' can also result in overflow too.
	 */
