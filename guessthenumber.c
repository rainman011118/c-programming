#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
		int x = 0, y = 100;
		int guessed_num = (x+y) / 2;
		char a[4];
		char ch;
		puts("Think of a number between 0-100 and I will try to guess your number.\nPress enter when ready...");
		getchar();
		while(1) {
				printf("Is this your number: %d? Type 'yes' or 'no'.\n", guessed_num);
				fgets(a, sizeof(a), stdin);
				a[sizeof(a) -1] = 0;
				if((strcmp(a, "yes")) != 0) {
						printf("Is your number higher or lower than %d? Type 'h' for higher or 'l' for lower\n", guessed_num);
						if((ch = getchar()) == 'l') {
								y = guessed_num;
								guessed_num = (x+y) / 2;
								getchar();
						} else  {
								x = guessed_num;
								guessed_num = (x+y) / 2;
								getchar();
						}
				}else {
						printf("Ta da, this is your number! %d\n", guessed_num);
						break;	
				}
		}
	return 0;
}

/*This works now but there is still room for error as I can enter any key besides the ones specified and the game continues.  Not sure how to limit this to just the 4 words: 'yes, 'no', 'l', 'h'....?*/
