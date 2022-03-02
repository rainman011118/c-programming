#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {
		char buffer[8];
		puts("Enter some number");
		fgets(buffer, 8, stdin);
		int val = atoi(buffer);
		printf("buffer =  %s and atoi(buffer) = %d\n", buffer, val);
		printf("sizeof(buffer) = %lu\nsizeof(val) = %lu\n", sizeof(buffer), sizeof(val));


		return 0;
}

