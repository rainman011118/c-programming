#include <stdio.h>
#include<string.h>

/*Flexible Array Member (FAM).
When you declare an array with [], this means it is a FAM.  
Syntax dictates that it must be declared as the last member in the struct and there must be at least 1 other member in the struct.
In order to assign something to this, a call to malloc is required:
...But this is where it got confusing...
*/


struct Car
{
    //char *fuel_type;
    //int fuel_tank_cap;
    int seating_cap;
    //float city_mileage;
    char* engine;
};

int main()
{
/*None of this will work with FAM:
    struct Car car1, car2;
    car1.engine = "Volvo V50";
    car2.engine = "Merc 995v";
    printf("%s\n", car1.engine);
    printf("%s\n", car2.engine);
*/	
	struct Car car3 = {5, "Mitsubishi"};
	struct Car* ptr = &car3;

//	strcpy(ptr->engine, "Mitsubishi");//strcpy doesn't work with pointers. Unless malloc has been used.
	ptr->engine = "Mercedes";
	printf("car3 engine is: %s\n", ptr->engine);
	printf("Addr ptr: %p\naddr car3: %p\naddr ptr->engine: %p\n", ptr, &car3, ptr->engine);
	/*The reason this works is because when the struct is declared, memory is already set aside for everything inside, including the pointer.(*engine). And when you declare a pointer to the struct, you are using that pointer(ptr) to reference the member's (*engine) address.
*/
  	return 0;
}

/*Originally, I declared char* engine and tried to assign string to it via pointer(ptr) to car3.  But this would not work.  (You can't assign a value to a pointer address...).  However on research, if I assign the values on declaration: struct Car car3 = {5, "Mitsubishi"}; then I can access it like normal.
*/
