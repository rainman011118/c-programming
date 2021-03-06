#include <stdio.h>

int main()
{
    int a = 12, b = 25;
    printf("Output = %d\n", a | b);
    puts("The bitwise operator returns the decimal representation of 8 in binary");
    return 0;
}

/*
12 = 00001100
25 = 00011001
8 = 00001000
(When you '&' them together, you get 8)
Output is 1 only if both numbers are 1:
00 = 0 (False)
01 = 0 (False)
11 = 1 (True)

For the bitwise OR '|' operator it is the opposite:
Output is 1 if both or one of the numbers is 1:
00 = 0 (False)
01 = 1 (True)
11 = 1 (True)

For the bitwise XOR '^' operator:
Output is 1 if the numbers are opposite:
00 = 0 (False)
01 = 1 (True)
11 = 0 (False)

With addition (+), you have to carry over the '1's' like in nursery school. So if you have:
1
1
then 1+1 = 2 = 0 and you carry 1 over to the left. If the next is also:
1
1
then 1+1 = 2, + carried over 1 = 3 (which will be 1 in binary) = 1.

*/
