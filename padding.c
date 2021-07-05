#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
/*This aligns things according to (n) bytes.
(1) = hex no's come one after the other, no spacing.(EASIEST TO FOLLOW).  
(4) = hex no's spaced 4 bytes with padding of 00 to fill up nibbles/bytes.  
(8) = hex no's spaced 8 bytes with padding of 00...
https://stackoverflow.com/questions/3318410/pragma-pack-effect
https://www.youtube.com/watch?v=aROgtACPjjg: Nesoacademy says that processors read 1 word at a time, not 1 byte at a time.  So 32-bit machine processes 4bytes at a time = 1 word.  64-bit processes 8bytes at a time = 1word. So if a structure is 6bytes in size, then padding will be added.  So that CPU cycles are efficiently used.  It is best to list the members with largest first. */

typedef struct {
		int test;
		char k;
		char str[8];
		int* p;
		short sh;
	} Thing;

int main(int argc, char* argv[]) {
		int i;
		Thing t = {12, 'k', "aaaaaaa", &i, 255};
		printf("%lu\n", sizeof(t));
		unsigned char data;
		printf("Value of 255 in hex...%x\n",t.sh);
		
		for(i = 0; i < sizeof(t); i++) {
				if(i % 8 == 0) {
						printf("\n");
				}
				data = *(((unsigned char*)&t) + i);
				printf("%02x ", data);
		}
		return 0;
}

/*Explaining the hexadecimal output(before using pragma pack):
int = 4 bytes
char = 1 byte
char str = 10 bytes
int* = 
short = 2 bytes

32 - This isn't the figure we expected(25) but this is explained by the pragma pack.

0c 00 00 00 6b 61 61 61
61 61 61 61 00 00 00 ac
2c 90 a1 de ff 7f 00 00
ff 00 27 5f b3 7f 00 00
(Every heaxdecimal digit is 4bits so 0c = 8bits or 1 byte)

Each 2digits = 1 byte.
0c 00 00 00 = the int test (4 bytes)
6b = char k (1 byte)
61 61 61 61 61 61 61 00 00 00 = char str[10] - all 10 bytes are taken.
ac 2c 90 a1 de ff 7f 00 = &i(8bytes)
ff 00 = short(2bytes) After this the no.'s are random garbage.

The reason there are rows of 8bytes is due to the loop.  8 % 8 = new line, 16 % 8 = new line etc.  So first 8 bytes will be filled up with int(4), char(1), char str "tes"(3). NEW LINE, "ting\0"(5) BUT BECAUSE [10] HAS BEEN ALLOCATED, 00 00 fills the rest and i = 15.  So next i = 16 gets filled with 00 and then NEW LINE and int* p starts = 8 bytes.  So, next line = short = 2 bytes which I think is ff00 = 255 in little endian.
 Which means the rest of the hex digits are garbage.
https://www.youtube.com/watch?v=8wHoI-6R0CQ

*/
