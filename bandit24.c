#include<stdio.h>

void main() {
	char p[] = "passwd";
	for(int i = 0; i < 10000; i++) {
//		printf("passwd %d\n", i);
		printf("%s %d\n", p, i);
	}
	return;
}

/*To get this to run automatically like a bash script, I have to compile it with gcc and either run the ./a.out | ncat -v localhost 30002 OR gcc -o a separate file.
SPEED:
I initially had 'password' written and was timing this compared to the python loop and the python loop was faster....?
python av 200ms
c av 450ms
So I decided to make the code shorter by removing the char p and simply copy/pasting the 'password' into printf.  But still no difference in speed....
Even though there was 1 line less of code, it didn't change the speed.
Then I noticed that in the .py loop I had written 'passwd' (2 letters shorter)....would this make a difference....?
.....YES!
After I removed the 2 letters from the c loop, the av speed was <=100ms.
*/

