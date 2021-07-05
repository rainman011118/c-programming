#include<stdio.h>
#include<stdlib.h>

// ################### HACKERRANK Sum of digits of a five digit number #############################
int main(int argc, char** argv) {

		int x;
		printf("Enter any 5 digit number: ");
		scanf("%d", &x);
		int tmp = 0;
		int sum = 0;
		int i = 0;
		for(i=0;i<5;i++) {
				if(x < 10) {
						sum += x;
						break;
				}else {
						tmp = (x % 10);
						sum += tmp;
						x -= tmp;
						printf("1st x = %d\n", x);
						if(x % 10 == 0) {
								x = x / 10;
								printf("x = %d\n", x);
						}else {
								break;
						}
				}
		}
		printf("%d: %d\n", i, sum);

		return 0;
}
