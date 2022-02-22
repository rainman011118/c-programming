#include<stdio.h>
#include<string.h>

//From page 107 K&R
void KRversion_strcpy(char* a, char* b) {
		while((*b++ = *a++) != '\0') {
				;
		}
}
int main(int argc, char** argv) {

		int MAX = 64;
		int c;
		int i = 0;
		char one[MAX];
		char two[MAX];
		while((c = getchar()) != EOF && c != '\n') {
				one[i++] = c;
		}
		one[i] = '\0';
		printf("one = %s\n", one);
		KRversion_strcpy(one, two);
		printf("two = %s\n", two);

		return 0;
}




