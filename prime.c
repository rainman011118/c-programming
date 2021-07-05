#include<stdio.h>

int main() {
		int i, j;
		printf("Prime numbers upto 100:\n");
		for(i=2; i<=100; i++) {
				for(j=2; j<=i; j++) {
						if(j==i) {
								printf("%d ", i);
						}else if(i%j==0) {
								break;
						}
				}
		}
		printf("\n");
		return 0;
}
/*Uses 2 loops in order to divide the main number (i) by all it's divisors between 2 and i.  And if none of them == 0, it is prime. */
