/*Basic information:
scanf() stops at whitespace.
fgets() stop at new line.

'ENTER'/NEW-LINE KEY PROBLEM:
scanf(), fgets() all store the enter/new-line in the buffer. (gets() doesn't store the new-line).
This can result in the next stdin data to be read being the 'enter/new-line' value instead of our expected next input.
 - getchar() or fgetc() can be placed after scanf() to 'eat' this.
 - <var>[strlen(<var>) - 1] = 0 can be placed after fgets().
 
 1byte can hold upto 255 characters.
 Char size = 1byte.
 Therefore 'char' data type is 255.  The first byte of a string, holds the string length.  This means that the length of a string can hold a max of 255 only.

POINTERS;
The '*' means different things when talking about pointers.
int *ptr = &x.  'Int pointer is the address of x'.
###################################
int *ptr = &x. 'Value of ptr is the address of x.
(This is interpreted wrong!!! Since the value of ptr = x.)
This is confusing since it declares a pointer while at 
the same time derefencing the pointer.
(So '*' in declaration means DECLARATION, and '*' elsewhere
means dereferencing.)
######################################
Best to declare separately: (until I am 100% confident)
int* ptr; 
ptr = &x;

ptr = &x. aka PTR = X (so *ptr = value of x.).

Maybe I am better using int* rather than the int *ptr...
Since *ptr is dereferencing indicator.

Read *ptr like:
What does ptr point to... and what's this value?

Passing an array as an arg to a func:
Can be done in 3 ways:
1) ...(int *array) - as a pointer.
2) ...(int array[]) - as unsized array.
3) ...(int array[10]) - as sized array.

Example:
char arr[5];
int *p = &arr;
The following all give the same result:
To get address (%p): arr, arr[], p.
To get a value: arr[0], *p, *(p+2) 
To increment a pointer: p++.
**Pointers can be incremented whereas array name(arr++)
cannot be incremented.

STRUCTURES AND POINTERS:
If you declare an array as a member and don't know what the size of the data will be, 
then it's better to just use a pointer.
If you know the size [], then don't use the pointer.
you can make pointers to struct variables in main() and reference them 2 ways:
(*ptr).engine
ptr->engine (This is considered standard)

FUNCTION ARG PASSING:
When declaring a function with parameters, it is not
necessary to type the same names of the args as in main,
only the data type is essential.
e.g.
void sumofElements(int *x, int size)
int main() {
    int Arr[5] = {3,4,5,6,7};
    sumofElements(Arr, 5);
}

SPEED:
when using certain arithmetic operations to return
a result, it is usually better to assign it to a new
variable.  e.g.
sum = sizeof(a) / sizeof(strlen(a))
This means that the compiler only has to compute the
calculation once, and it is stored in 'sum'. So when sum
is used in other parts of the code, it is accessed fast.


 */


