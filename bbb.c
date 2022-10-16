#include<stdio.h>
#include<string.h>


// Just practicing byte targeting and how input is taken...it won't let me record 'A' though...? Only numbers... Why doesn't 'A' get registered as 65??

int main(int argc, char** argv) {
		int num;
		char* p = (char*)&num+3;
		puts("Enter a number");
		scanf("%d", &num);
		printf("num = %d, num = %c\n", num, num);
		printf("num = 0x%x\n", num);

		printf("Starting add: %p\n", p);

		for(int i=0;i<4;i++, p--) {
				printf("%p  %x\n", p, *p);
		}
		// Resets the pointer to original starting position (NOTE: p+4 didn't work. I had to assign it)
		p = p+4;
//		printf("\n%p\n", p);
//		printf("%08x\n", *p);

		puts("Print bytes out in big endian format (NOTE: I have used signed char, therefore, sign is extended. e.g. 128, 32768 etc");
		for(int i=0;i<4;i++, p--) {
				printf("%02x ", *p);
		}
		printf("\n");

		return 0;

}


