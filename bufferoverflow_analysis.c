#include<stdio.h>

// This is a test program for buffer overflow.
// When I analysed this in gdb, everytime I entered 65 'A', nothing would happen.  And the 'modified = 0' variable seemed to be unaffected (ie not overwritten). It was based at -0x54(%rbp), which was at top right hand corner of screen on x/32wx $rsp.  And the A's were being filled from there downwards, which meant that the 0 would not get overwritten...?? (I doubled checked this, and top right is correct) 

//compile this gives a warning about 'gets' being dangerous, but output file still produced.

int main(int argc, char** argv) {
		volatile int modified;
		char buffer[64];

		modified = 5;
		gets(buffer);

		if(modified != 5) {
				printf("You have changed the 'modified' variable\n");
		}else {
				printf("Try again\n");
		}

		return 0;
}


/* This is a copy of the x/32wx $rsp
 * rbp is ...ede60
 * rsp is ...eddf0
 * I assume my modified = 0 is at ...ede0c (2nd row, top right) - CORRECT.
 * 'A' gets filled from ...ede10	downwards...
 * segfault occurs when '0x0d4545900' gets overwritten, but only the '00' bit which gets overwritten first.
 * Also, I have to use 73*'A' before segfault.  (9 past the 64 buffer size)
 ****** is this 8 bytes of padding??  Is is due to the stack pointer automatically being incremented when old base pointer is copied at beginning...??
 
0x7ffffffeddf0: 0xfffedf58      0x00007fff      0x00000000      0x00000001
0x7ffffffede00: 0x08000040      0x00000000      0x00f0b6ff      0x00000000 <- modified = 0
0x7ffffffede10: 0x00004141 <-   0x00000000      0xfffede47      0x00007fff
0x7ffffffede20: 0xfffede46   |  0x00007fff      0x0800124d      0x00000000
0x7ffffffede30: 0xff7a0fc8   |  0x00007fff      0x08001200      0x00000000
0x7ffffffede40: 0x00000000   |  0x00000000      0x080010a0      0x00000000
0x7ffffffede50: 0xfffedf50   |  0x00007fff      0x0d454900	<-	0xa1051b95
0x7ffffffede60: 0x00000000   |  0x00000000      0xff5d70b3		| 0x00007fff
												     |																|
												     |																-- This is where buffer = segfault
												     |
												     -- This is where buffer starts

On another program (gets_test2) I did with gets, it did the same thing: I created a buffer[16], yet on the stack analysis, there is 8 extra bytes allowed before OVERFLOW on the 9th byte.  
Also, this 9th byte area is definiitely a place where other important info has been pushed onto the stack at an earlier time in the program: 
				At the start of int main(int argc, char** argv), 
				mov		%fs:0x28,%rax
				mov		%rax, -0x8(%rbp) <---- This is the 9th byte position = seg fault
I think it is a pointer because it is an 8byte value that is copied to the stack.

*/


