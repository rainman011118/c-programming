#include <stdio.h>
#include <string.h>

int main()
{
    char _one[] = "Jonny";
    char _two[32];
    char _three[32];

    printf("Enter your first name: ");

    fgets(_two, 32, stdin);
    _two[strlen(_two) - 1] = 0;
    /*It seems 'strlen -1' has to follow fgets
    everytime since this NULL ch leaves an extra
    line when their shouldn't be one.
    */
    sscanf(_two, "%s", _three);
    printf("one = %s\ntwo = %s\nthree = %s\n", _one, _two, _three);
    return 0;
}
