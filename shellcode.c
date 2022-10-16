#include<stdio.h>
#include<string.h>
#include<unistd.h>

//SEE: bookmarks
//Not finished.....DO NOT RUN.......keep getting segfault....??  shellcode is not a function, it is an array......

unsigned char shellcode[] = "\xb8\x0a\x00\x00\x00\xc3"; //This doesn't make any sense. [I should copy in my "/bin/sh" shellcode]

// This doesn't fucking work either....segfault! even when they said to compile with:
// gcc -fno-stack-protector -z execstack shellcode.c 
// NEED TO GO THROUGH FUNC POINTERS PROPERLY BECAUSE THEY LOOK SO CONFUSING WITH ALL THE BRACKETS
int main(int argc, char** argv) {
		int (*func)() = (int(*)())shellcode;
		func();
/*		
		int foo_value = 0;
		int(*foo)() = (int(*)())shellcode;
		foo_value = foo();
		printf("%d\n", foo_value);
*/
		return 0;
}




/*
int main(int argc, char** argv) {
		printf("Shellcode = %s\n", shellcode);
		printf("Shellcode length: %lu\n", strlen(shellcode));

		int (*execshell)();								//declares function pointer
		execshell = (int*)shellcode;				//assigns the array to function pointer
		(int)(*execshell)();							//calls function pointer

//		execshell();  //this might be the right one?? (without having to cast it)
//		SEE: https://www.youtube.com/watch?v=T7GtWid5hsw&list=RDQMdobvO801faQ&index=21
		
		return 0;
}


//"\xb0\x3c\x31\xff\x0f\x05"; this is nasm_mod_edi (instead of rdi)....Still segfault....??
//"\x48\x31\xff\xb0\x3c\x0f\x05"; this is NASM_xor_mod (xor'd rdi instruction before 60 into al) (but not sure if I still have to mov rdi, 0 as the argument to exit????? Or since rdi is already 0, is this fine....??) - still segfault
//"\x48\x31\xc0\xb0\x3c\x48\x31\xff\x0f\x05"; - Still seg fault :(
*/
