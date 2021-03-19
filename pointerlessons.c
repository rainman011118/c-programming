#include <stdio.h>

void print_values(char *x, char *y);

int main()
{
    char one[] = "Hello";
    char two[] = " World!";
    char *ptr = "Pointer"; //This works, but doesn't make much sense as you want to use a pointer for flexibility.  This assigns a string literal to it, negating it's flexibility.
    /*A pointer always points to the beginning address
    of a value/string.
    Hence: when dereferencing with *ptr:
    %p = cast (void*) the address where the value/string starts.
    %d = the int value of the 1st letter in string.
    %c = the int value as char of first letter in string.
*/
    printf("&ptr = %p\n", &ptr);
    printf("ptr = %p\n", ptr);
    printf("(void*): %p\t*ptr with d: %d\t *ptr with c: %c\n", (void *)ptr, *ptr, *ptr);
    printf("%s\n", ptr);
    printf("%d %c\n", *ptr + 1, *ptr + 1);
    printf("%d %c\n", *ptr + 2, *ptr + 2);

    print_values(one, two);
    printf("dec of *one: %d\n", *one);
    printf("hex of *one: %x\n", *one);
    printf("oct of *one: %o\n", *one);
    printf("one: %s\n", one);

    /*This will not work with *one because *one returns
    an 'int' and %s returns a 'char'.
    */
    printf("(char*)one: %s\n", (char *)one);
    printf("*&one: %s\n", *&one);
    printf("one: %s\n", one);
    printf("(char*)ptr: %s\n", (char *)ptr);
    printf("*&ptr: %s\n", *&ptr);
    printf("ptr: %s\n", ptr);
    return 0;
}

void print_values(char *x, char *y)
{
    printf("call (char*)x: %s\ncall (char*)y: %s\n", (char *)x, (char *)y);
    printf("call x: %s\ncall y: %s\n", x, y);
    /*The above are the same.  x and y work simply, because
    I have already declared them as char pointers in 
    the function args.  By putting (char*)x, it is 
    EXACTLY the same as just putting x.
    What didn't work was *x.  Because this would 
    translate to **x.
    eg printf("one: %s\ntwo is: %s\n", *x, *y);
    */
}
