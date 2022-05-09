#include<stdio.h>

int main() {

#ifdef _WIN32
		printf("Hey, you are working on a WIN32 OS\n");

#elif __APPLE__
		printf("You are on an APPLE OS\n");

#elif _WIN64
		printf("You are on an WIN64 OS\n");

#elif __linux__
		printf("You are on an LINUX OS\n");

#else
		printf("Sorry, I don't know what system you are on\n");

#endif
		return 0;
}

