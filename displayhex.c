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
		Thing t = {12, 'k', "ABCDEFGHIJ", &i, 255};// ff00 = 255, 0001 = 256, 0101 = 257
		printf("%lu\n", sizeof(t));
		unsigned char data;
		for(i=0; i<sizeof(t); i++) {
				if(i % 4 == 0) {
						printf("\n");
				}
				data = *(((unsigned char*)&t) + i);//If I don't typecast (unsigned char) here, it will raise an error: incompatible types assigning to type unsigned char from type Thing(struct). If I declared data as an INT, and type cast it, then everything is printed out as the int form....no good. And when I declare data as CHAR....it leads to overflows on the '&i' part. Hence why unsigned char is used. THIS IS BASICALLY THE SAME A POINTER TARGETING THE BYTE VALUES.

				printf("%02x ", data);// in hex
				//printf("%03hhu ", data);// in decimal
				//printf("%c ", data);// in char - but doesn't display everything....??
		}		
		printf("\n");

		return 0;

}
/* SEE: https://www.youtube.com/watch?v=a3ropbfIpw4&list=PLfqABt5AS4FmErobw8YyTwXDUE5nPH5lH&index=18
The output should be in little endian. */
