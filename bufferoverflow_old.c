#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define BUFFERSIZE 12

char buffer[BUFFERSIZE] = "Welcome";
char password[BUFFERSIZE] = "password5";


int main(int argc, char** argv) {
		if(argc != 3) {
				printf("Error: 3 args needed: %s <password> <string_to_print>\n", argv[0]);
				exit(1);
		}

		strcpy(buffer, argv[2]);//copies the <string_to_print> to buffer = overwrites "Welcome".NOTE: doesn't stop me from entering > BUFFERSIZE!!!
		//If there happens to be an apostrophe (eg "What's up" as <string>, it causes a new line with > awaiting input...????
		if(strcmp(argv[1], password) == 0) {
				printf("Correct password\n");
				printf("MSG: %s\n", buffer);
		} else {
				printf("ERROR, incorrect password!\n");
		}


		return 0;
}
/*SEE: https://www.youtube.com/watch?v=7mKfWrNQcj0
 * When you objdump -t a.out, you can see where the password and buffer sections are in memory.  In this case, they are hex10 apart: (I went back to check this but can't see where passwd and buffer are, it is not clear.  I then just objdump -d a.out, and passwd and buffer are highlighted separately, but this is the large output from the usual -d command)
0000000000004020		password
0000000000004010		buffer
This is equivalent to 16bytes (or 16 chars).  Therefore, if you type 16chars over the BUFFERSIZE, then anything typed beyond this 16 will be copying over 'password'.
eg:
a.out rain 0123456789abcdefrain (16 chars before my matching 'rain' input)

Safety changes:
use strncpy for bounds check.
use fgets().
*/
