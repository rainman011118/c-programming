#include <stdio.h>
struct Car
{
    char *engine;
    //char *fuel_type;
    //int fuel_tank_cap;
    //int seating_cap;
    //float city_mileage;
};
int main()
{

    struct Car car1, car2;
    car1.engine = "Volvo V50";
    car2.engine = "Merc 995v";
    printf("%s\n", car1.engine);
    printf("%s\n", car2.engine);
    return 0;
}