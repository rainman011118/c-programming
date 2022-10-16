#include <stdio.h>


int main()
{
    printf("%d\n", printf("%s\n", "Hello World"));
    /*%d requires an int value
    The reason this statement works is because,
    the printf fn not only return a string, 
    but also the number of characters (12).
    Therefore when the computer comes to read the code,
     - Print value at %d
     - pause until value found
     - print str 'Hello World' (12)
     - return value to %d
     finish. */

    printf("%s\n", "Hello");
    printf("%10s\n", "Hello");
    /* The %10s prints 10 character spaces, 
    (blankspaces) before the 'str'
    */

    char c = 255;
    c = c + 10;
    printf("%d\n", c);
    /*THIS IS INTERESTING ONE:
     - char is capable of holding 1byte max (8-bits)
     - 255 is maximum value for 8 bits:
     2,4,8,16,32,64,128,256
     - Therefore 255 = ASCII char
     - However + 10 makes c 265
     - So 265 % 256 = remainder 9
     - so the output will be 9.
     */

    unsigned i = 1;
    int j = -4;
    printf("%u\n", i + j);
    printf("%d\n", i + j);
    /* Normally 1 + -4 = -3
    BUT, -3 is represented differently in binary.
    3 = 00000000 00000000 00000000 00000011
    For -3 you have to invert and add 1:
    -3 = 11111111 11111111 1111111 11111101
    And this = 4294967293
    NOTE:
    BECAUSE %u IS USED, 4294967293 IS THE RESULT.
    IF I USED %d, THEN -3 IS THE RESULT.
    */

    return 0;
}
