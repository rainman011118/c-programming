#include<stdio.h>

int main(void) {
		printf("EOF is not ASCII but system defined = %d\n", EOF);
		int n = '\n';
		printf("newline char as well as 'enter' is ASCII: %d\n", n);
		int b = ' ';
		printf("space in ASCII: %d\n", b);
		int c = '\t';
		printf("tab in ASCII: %d\n", c);
		int d = 13;
		printf("'enter' key here is (CRLF) which = ASCII: %d\nThe main 'enter' is (LF) which is 10\n", d);

		int ch;
		while(1) {
		if((ch = getchar()) == '\n') {
				printf("Enter key (%d) was entered = \\n\n", ch);
				break;
		} else {
				printf("%c is %d in ASCII\n", ch, ch);
		}
		ch = getchar();
		}


		return 0;
}


