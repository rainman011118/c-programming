#include<stdio.h>
#include<stdlib.h>

// ################### HACKERRANK Sum of digits of a five digit number #############################

// SEE: this is a more complicated version of 'digit_checking.c' which I actually did many months after this file. however, for some reason, I did it this way (with modulus).
// NOTE: Just ran this now (after completing digit_checking.c), and I input letters...and the total sum printed at the end was a huge negative number....so this program is not error proof...

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
						printf("%d remainder %d\n", x, sum);
						if(x % 10 == 0) {
								x = x / 10;
								printf("x is now = %d\n", x);
						}else {
								break;
						}
				}
		}
		printf("Total sum of the 5 digits in the 5 digit number is: %d\n", sum);

		return 0;
}
