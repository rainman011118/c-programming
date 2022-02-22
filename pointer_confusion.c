#include<stdio.h>
#include<string.h>

/* ################### Just comment out the inputting function's selected ones for either:
 * ################### char* p version or char (*p)[n] version.
 * ################### and change the call in main to array or & array
 */

// I have it working now, but just need to see if the normal way of char* array is good enough, instead of the more complicated char (*p)[n] bullshit. AND GUESS WHAT....IT WORKS IN THE NORMAL WAY...
//
//  The (*p)[i] seems to be fine, but it pauses at this while loop...is that because there is no space allocated for the array???  Since it is only a copy??? - ANSWER; it wasn't pausing idiot!  it was waiting for input for getchar()....doh!!!
void inputting(int n, char *p) {
//void inputting(int n, char (*p)[n]) {//This was the weird way of doing it where I'd pass in &array...see below comments.....SO CAN CHOOSE THIS WAY AND THEN COMMENT OUT LINES 20, 24, or vice versa with simple method.
		int c;
		int i = 0;
		printf("address p in func = %p\n", p);
		printf("address &p in func = %p\n", &p);
		puts("Enter something...");
		while((c = getchar()) != EOF && c != '\n' && i <15) {// CAREFUL SINCE NO BOUNDS CHECKING so can write infinite...........So what I probably should do is create size varialble of just use i as counter..<15..........SORTED! :)
				p[i] = c;
		//		(*p)[i] = c;
				i++;
		}
		p[i] = '\0';
		//(*p)[i] = '\0';
}
/*When you pass in a fixed size array to a function, you must declare it as follows:
 * 		char (*array)[size]		//this says: pointer to an array of size chars
 * 		IT IS NOT THE SAME AS CHAR**
 * 		To dereference it, you write: (*array)[3] or array[0][3]
 * 		AFTER FINALLY GETTING THINGS TO WORK, THIS IS NOT NECESSARY, but may have use somewhere else...
 * 		Just passing the 'array' as argument was enough to get direct access to values and carryover
 */
int main(int argc, char** argv) {
		int MAX = 15;
		char array[MAX];
		char array2[MAX];
		int c;
		int i = 0;
		puts("Now trying with the functions.....\n");
		printf("strlen array before input = %ld\n", strlen(array));
		printf("address of array in main = %p\n", array);
		printf("address of &array in main = %p\n", &array);

		inputting(MAX, array);

		printf("strlen array after input = %ld\n", strlen(array));//overflow evident...
		printf("array = %s\n", array);
//		strncpy(array2, array, strlen(array));//Bad to use strlen as limiter if input doesn't limit input. othwise, make sure the input is limited in the loop, to prevent overwriting/flowing.
		strncpy(array2, array, MAX);//Only prints the MAX but no NULL is added.....
		printf("array2 = %s\n", array2);
		printf("strlen array2 after  = %ld\n", strlen(array2));

		//Can I pass out these two operations out to functions instead.....? - YES.
		//one for the input into array and the other for copy....? - YES. Since the array is getting filled in directly, it is shared in both func and main.
		//And one asks for char (*array)[MAX] instead of just char** array....???

		return 0;
}


