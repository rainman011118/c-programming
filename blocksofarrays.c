#include<stdio.h>
#include<string.h>

int main() {
	
		char* arr[5] = {"Hello", "my", "name", "is", "Bob."};//NOTE: This declares a pointer to 5 arrays.  Which is the same as a pointer to pointer. (char**).  Hence why we must dereference (*arr) in order to print out the values.  (if I just call arr for %s, it errors with '%s expects char*, but argument(arr) is a char**.)
		printf("*arr is: %s\n", *arr);	
		printf("*arr+3 is: %s\n", *arr+3);// (char*)arr[0]+3 is the exact same. [This is a way to split the string values within each array].  
/*#########################################################
		WARNING!! If I put *arr+22 and beyond, it starts to output the above printf text: '*arr is:'. So even though size is 40bytes, looks like there are not 40bytes available, only the 22 declared....?
############################################################
*/
		/*Notice how if I just increment '*arr+.......', the values are all back to back in memory location.  So I can target any starting point of any letter, and it will print the remaining letters in that particular string.*/
		printf("arr[1], [2], [3] is:\t%s\t%s\t%s\n", arr[1], arr[2], arr[3]);	
		printf("size of arr is: %lu\n", sizeof(arr));// answer = 40 since 5(pointers) x 8.
		printf("size / arr[0] is: %lu\n", sizeof(arr) / sizeof(arr[0]));// answer = 5.
		printf("size arr[0] is: %lu\n", sizeof(arr[4]));
//		printf("all chars: %c\n",*++arr[0]);
//########################################################
		printf("add is: %p\n%p\n%p\n%p\n%p\n", arr[0], arr[1], arr[2], arr[3], arr[4]);//These starting address' show that they contain the exact no. of bytes for each word+NULL.  No padding. And yet the sizeof is 40bytes...?? 
		for(int i=0; i<10; i++) {
				printf("char %d: %c\n", i,*(*arr)++);//* = target string, ** = target char.
		} 
//#############################################################
//DON'T RUN THE BELOW CODE WITH THE ABOVE LOOP, BECAUSE THE POINTER IS ALREADY AT THE END OF THE STRINGS.		
		int sizebyElements = sizeof(arr) / sizeof(arr[0]);
/*
		puts("Elements:");
		for(int i = 0; i<sizebyElements; i++) {
				printf("%d: %s\n", i, arr[i]);
		}
		puts("targeting sequential starting points:");
		for(int i=0; i<22; i++) {//Can I put sizeof here?????Also, my string values only take up 22bytes, so does that mean that the remaining 18bytes are wasted?
				printf("%s ", *arr);
				*arr += 1;
		}
		printf("\n");
*/
		return 0;

}	
