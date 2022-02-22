#include<stdio.h>
#include<stdlib.h>

int double_up(int a) {
		return a << 1;
}
int half_it(int b) {
		return b >> 1;
}

int main(int argc, char** argv) {
		int x = 2;
		int y = 10;
		int z = double_up(x);
		printf("%d left shifted by 1 = %d\n", x, z);
		int v = half_it(y);
		printf("%d right shifted by 1 = %d\n", y, v);

		return 0;
}


