#include<stdio.h>
#include<stdlib.h>


int main() {
		char arr[] = "Male";
		const char* arr2 = "Female";//By putting this 'const char*' it will warn me if I try to alter the value like at the end of this code.

		printf("arr = %s\n", arr);
		printf("arr2 = %s\n", arr2);
		printf("Accessing elements via arr[] notation.\n");
		printf("arr[0][1][2][3] = %c%c%c%c\n", arr[0], arr[1], arr[2], arr[3]);
		printf("arr2[0][1][2][3][4][5] = %c%c%c%c%c%c\n", arr2[0], arr2[1], arr2[2], arr2[3], arr2[4], arr2[5]);
		printf("Accessing elements via *arr notation.\n");
		printf("*arr2 is: %c\n", *arr2);
		printf("*(arr2+1) is: %c\n", *(arr2+1));
		printf("(*arr2)+1 is: %d\n", (*arr2)+1);//allows me to add to the values at each element, but this doesn't change it permanently.
		printf("arr2 = %s\n", arr2);
		/*This shows you can access the individual elements of a string literal, but below shows you cannot change them.*/

		arr[2] = 't';
		printf("arr is now: %s\n", arr);

// ALL OF THE FOLLOWING IS SEG FAULT. Just running the first line(assigning 'z') without even having to print the output causes it.
		arr2[2] = 'z';
		printf("arr2[2] is now: %c\n", arr2[2]);
		printf("arr2 is now: %s\n", arr2); 
		

		return 0;
}




