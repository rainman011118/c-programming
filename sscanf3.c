#include <stdio.h>
/*CodeVault vids youtube*/
int main(int argc, char *argv[])
{
    char str[] = "Jonny;New York;37;1";

    char name[20] = {0};
    char city[20] = {0};
    unsigned int age;
    int hasDegree;

    /*1st doesn't work properly because of whitespace:
    It reads all chars upto first space after 'New', 
    and does't seem to scan anything else afterwards.*/
    //sscanf(str, "%s;%s;%u;%d", name, city, &age, &hasDegree);

    /*2nd works perfect. '[^;]' means:
    read everything that is not a semi-colon, 
    includes whitespace.*/
    sscanf(str, "%[^;];%[^;];%u;%d", name, city, &age, &hasDegree);

    /*3rd way with 'scanf' works the same if I type
    the same way: 'Jonny; New York; 20; 1'
    Must be DANGEROUS because if I don't enter
    semi-colons then I could enter way more than is
    allowed....*/
    //scanf("%[^;];%[^;];%u;%d", name, city, &age, &hasDegree);

    printf("%s is in %s and is %u years old\n", name, city, age);

    return 0;
}