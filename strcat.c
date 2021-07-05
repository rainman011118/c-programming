#include <stdio.h>
#include <string.h>

int main()
{
    char name[30] = "Michael ";
    char lastname[30] = "Jackson";
    char full[30];
    strcpy(full, name);
    strcat(full, lastname);

    puts(full);

    return 0;
}
