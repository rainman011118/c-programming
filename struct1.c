#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x;
	int y;
} Point;

void details(Point p)
{
	printf("%d %d\n", p.x, p.y);
}

void display_p2(Point* p) {
		printf("fn call: ptr2->x: %d ptr2->y: %d\n", p->x, p->y);
		//I put (Point* p) before and referenced the values as ptr2->x and y and it caused an error: ptr2-> is not declared.  This was because ptr2 is local to main only.  Therefore, to reference the p2 values x and y, I must use what I declared as the equivalent in the parameters: 'p'. So, p->x, p->y will now give me the p2 values.
}


int main()
{
	Point p1 = {24, 45};
	Point p2 = {15, 61};
	details(p1);
	details(p2);

	Point* ptr = &p1;
	printf("main call: p1 ptr->x = %d p1 ptr->y = %d\n", ptr->x, ptr->y);

	Point* ptr2 = &p2;
	display_p2(&p2);//can also pass (ptr2).

	return 0;
}
