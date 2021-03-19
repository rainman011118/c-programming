#include <stdio.h>
/*https://www.youtube.com/watch?v=cNv4SA87y5c

Basics of structures:
*/
typedef struct
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

void print_pixel(pixel j)
{
    printf("%u %u %u\n", j.r, j.g, j.b);
}

int main()
{

    pixel p;
    p.r = 0;
    p.g = 255;
    p.b = 0;
    printf("sizeof(pixel): %lu\n", sizeof(pixel));

    print_pixel(p);

    return 0;
}