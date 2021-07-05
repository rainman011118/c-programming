#include<stdio.h>

int factorial(int n) {
		if(n == 1) {
				return 1;
		}else {
				return n*factorial(n-1);
		}
}
int main(int argc, char** argv) {
		int i = 6;
		printf("factorial of %d is: %d\n", i, factorial(i));			

		return 0;

}

