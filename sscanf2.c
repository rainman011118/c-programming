#include <stdio.h>
int main()
{
    char input[] = "Jonny Bee 37 181 75";
    char first_name[25], last_name[25];
    int age;
    float height, weight;

    sscanf(input, "%s%s%d%f%f", first_name, last_name, &age, &height, &weight);
    printf("First name: %s\nLast name: %s\nAge: %d\nHeight(cm): %.2f\nWeight(kg): %.2f\n", first_name, last_name, age, height, weight);
    return 0;
}