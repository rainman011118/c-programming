#include <stdio.h>
#include <stdlib.h>

/*Run this from the terminal to understand how
the arguments work.
e.g. ./a.out = argv[0](position 0 in cmd line).
./a.out jonny b 1 2 3 = 
argv[0] = ./a.out
argv[1] = jonny
argv[2] = b
argv[3] = 1 etc etc...

char *argv[] is exactly the same as char **argv.
*/

int main(int argc, char *argv[])
{
    int i;
    printf("argc = %d\n", argc);
    printf("Let's see what is in argv[]\n");

    for (i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    return 0;
}

/*int argc is the number(count) of arguments passed
from the COMMAND LINE:
e.g ./a.out = argc of 1
./a.out jonny = argc of 2

char *argv[] is basically the strings/arrays passed
from the command line:
So, ./a.out jonny b 7 is:
argv[3]. 
[0] = ./a.out
[1] = jonny
[2] = b 
[3] = 7
*/
