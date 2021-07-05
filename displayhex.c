#include<stdio.h>
#include<stdlib.h>

typedef struct {
		int test;
		char k;
		char str[10];
		int* p;
		short sh;
} Thing;


int main(int argc, char** argv) {
		int i;
		Thing t = {12, 'k', "testing", &i, 256};
		printf("%lu\n", sizeof(t));
		unsigned char data;
		for(i=0; i<sizeof(t); i++) {
				if(i % 4 == 0) {
						printf("\n");
				}
				data = *(((unsigned char*)&t) + i);
				printf("%02x ", data);// in hexa
				//printf("%03hhu ", data);// in decimal
				//printf("%c ", data);// in char - but doesn't display everything....??
		}		
		printf("\n");

		return 0;

}
/* SEE: https://www.youtube.com/watch?v=a3ropbfIpw4&list=PLfqABt5AS4FmErobw8YyTwXDUE5nPH5lH&index=18
The output should be in little endian. */
