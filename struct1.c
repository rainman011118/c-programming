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

int main()
{
	Point p1 = {24, 45};
	Point p2 = {15, 61};
	details(p1);
	details(p2);

	return 0;
}
