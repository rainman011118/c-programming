#include <stdio.h>


//NOTE: %p simply returns the value(address) stored at a pointer
//i.e. dereferencing a pointer = value(int,char,float etc OR void* == address)
int main() {
    int a = 10;
    int *p = &a; 
	puts("a is an INT and p is a pointer to a");
    printf("a = %d, &a = %p\n", a, &a);
    printf("p==a holds: %p, &p = %p\n", p, &p);

    int **q = &p;
    int ***r = &q;
	printf("**q points to p and ***r points to q\n");
	printf("...in other words: **q holds &p and ***r holds &q\n");
    printf("q holds: %p\n", q);
    printf("*q holds: %p\n", *q);
	printf("HOW THE PATTERN/FLOW WORKS:\nr - > q - > p - > a\n*r = &q   *q = &p   *p = value of a\n");
	printf("r holds %p  q holds %p  p holds %p\n", r, q, p);
    printf("**q = %d\n", **q);
    printf("**r (%%p) = %p\n", **r);

// #########################################################################
//
//							wchar_t vs char datatypes	UNICODE
//
	//NOTE: this below line with %ls, skips printing the format specifier and instead goes and prints the following printf line...???  (The warning I got when I compile it with an incorrect format specifer said use %ls...???
	// %ls stands for 'wide string' and has to do with the type of encoding.  It refers to the wchar_t datatype which is like a char, only double the size.  It is usually required when encoding other languages that contain weird characters.
	// where as 'char' has a max of 256 (ASCII), wchar_t has a max of 65536 (which corresponds to UNICODE values = all the characters for all languages including symbols)
	// Now having learned all this, it still doesn't explain why it skipped right to the next line...?
    printf("\nERROR COMING UP: **r (%%ls) = %ls\n", **r);
    printf("123r = %d\n", ***r);
// ###########################################################################

	printf("Now correcting it...\n");
    printf("**r (%%p) = %p\n", **r);
    printf("***r (%%d) = %d\n", ***r);
    return 0;
}
