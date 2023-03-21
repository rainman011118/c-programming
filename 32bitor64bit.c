#include<stdio.h>
int main() {
		printf("Size = %lu\n", sizeof(size_t));
		return 0;
}

//compile:
//64bit		gcc file.c
//32bit		gcc -m32 file.c
//
//You have to change the %lu to u because in 64bit, size_t = long unsigned, but is unsigned int in 32bit.
