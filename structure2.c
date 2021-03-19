#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*This is the alternative way of using structure:
You declare a variable 'record'.
NOTE: It must be placed outside of STRUCT block, BUT
before ';'
*/
struct student
{
    int id;
    char name[20];
    float percentage;
} record;

int main()
{
    //struct student record1;
    record.id = 1;
    strcpy(record.name, "Jonny Bee");
    record.percentage = 75.0;
    printf("id = %d\nname = %s\npercentage = %.2f\n", record.id, record.name, record.percentage);

    return 0;
}