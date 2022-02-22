#include<stdio.h>

int main(int argc, char** argv) {
		printf("Enter your name: \n");
		char name[16];
		gets(name);
		printf("Your name is: %s\n", name);

		return 0;
}

