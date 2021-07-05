#include <stdio.h>
#include <string.h>
/*
Using typedef:
It basically allows us to shorten the names so that
we don't have to type the whole names out.
e.g. struct modelCars.
int main()
struct modelCars car1, car2;
Instead we use typedef as 'datatype' and then our
chosen name at end of struct block (car).
*/
typedef struct
{
    char *engine;       //Basically it says we take a pointer to a member, when we don't know the length of the data we need to store.
    char fuel_type[12]; //Otherwise, we should probably just specify the size instead of the pointer.
    int fuel_tank_cap;  //
    int seating_cap;
    float city_mileage;
} car;
/*When I specified the size of both char *engine[50] and char *fuel_type[10], it caused a problem with the 'double' in the int main variables... But when I remove the size[], it works fine..?? ANSWER: this is because char* engine[50] and char* fuel_type[10] are double pointers!
*/
int main()
{
    car c1 = {"Volvo V5", "petrol", 30, 5, 33.3};
    car c2 = {.engine = "Merc 995"};
    /*Example of declaring a pointer and using the pointer to get the values:
    */
    car *ptr;
    ptr = &c1;
    printf("(*ptr).fuel_type = %s\n", (*ptr).fuel_type); //the dot.method way.
    printf("ptr->engine = %s\n", ptr->engine);           //the pointer -> way. (recommended).
    /*Normal individual accessing of members: */
    printf("%s\n", c1.engine);
    printf("%s\n", c2.engine);
    printf("%f\n", c1.city_mileage);

    car c3 = {"Ford Focus RS", "Petrol", 37, 5, 27.8};
    car c4 = {"Toyota", "Electric", 90, 5, 60.5};
    printf("c3 = %s\nc4 = %s\n", c3.fuel_type, c4.fuel_type);

    /*Declare the struct variable first before trying to
    assign values to individual members:*/
    car c5;
    c5.seating_cap = 12;
    c5.engine = "Volkswagen";
    /*c5.fuel_type = "Diesel"; THIS DOESN'T WORK.
    strcpy must be used to copy a string to
    an array member[x] that has a specific size.
    */
    strcpy(c5.fuel_type, "Diesel");
    printf("c5.seating_cap = %d\n", c5.seating_cap);
    printf("c5.engine = %s\nc5.fuel_type = %s\n", c5.engine, c5.fuel_type);
    return 0;
}
