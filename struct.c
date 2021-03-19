#include <stdio.h>
#include <stdlib.h>
/*
https://www.youtube.com/watch?v=qqtmtuedaBM&ab_channel=KrisJordan
*/
typedef struct
{
	double x;
	double y;
} Point;

void Point_print(const Point *self);

int main()
{
	//Point p = {1.0, 2.0};  This is the alternative way to initialize.
	Point p;
	p.x = 1.0;
	p.y = 2.0;
	Point_print(&p);
	printf("Access via dot notation of individual values: p.x = %f, p.y = %f\n", p.x, p.y);
	return 0;
}

void Point_print(const Point *self)
{
	printf("%f, %f\n", (*self).x, (*self).y);
}
