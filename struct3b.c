#include <stdio.h>
/*https://www.youtube.com/watch?v=cNv4SA87y5c
*/
typedef struct
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

void make_redder(pixel *p)
{
    p->r = 255;
    /*This changes the value of p.r from 0 to 255
	*/
}

int main()
{
    pixel p = {0, 255, 0};

    printf("%u %u %u\n", p.r, p.g, p.b);
    make_redder(&p);
    printf("%u %u %u\n", p.r, p.g, p.b);

    return 0;
}