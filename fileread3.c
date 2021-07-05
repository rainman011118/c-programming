#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
		int x, y;
} Point;

int main(int argc, char** argv) {
		Point p1 = {
				.x = 12;
				.y = -9;
		};

		//Create 2 file handlers:
		FILE* in;
		FILE* out;

		//create 2 places to store info:
		char buffer_in[256], buffer_out[256];

		//fopen_s is a variant of fopen........
		//point.dat should be created as a new file in which the info (x and y) will be written to.
		fopen_s(&out, "point.dat", "w");
		if(out == NULL) {
				return 1;
		}
		
		sprintf_s(buffer_out, 256, "%d, %d\n", p1.x, p1.y);
		fwrite(buffer_out, sizeof(char), strlen(buffer_out), out);
		

		return 0;
}

/* SEE: https://www.youtube.com/watch?v=da9D4Bcsrgc&list=PLfqABt5AS4Fmv8DszqJjIjmCjvTtTVslT&index=11
Need to go over this again, to understand it fully. */ 

