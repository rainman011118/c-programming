#include<stdio.h>

void countdown(int x) {
	printf("Entering countdown\n");
	if(x <= 0) {
		return;
	}
	printf("%d\n", x);
	countdown(x-1);
	printf("exiting  countdown\n");
	/*Note the output...
	There is a build up of 'exiting countdown' statements due continuous returns back to the countdown(x-1) fn.  Each time it was called, the exiting countdown statement wasn't printed because countdown was called again.  So by the time x was 0, it returns to the caller, then exiting countdown completes, but so do the previous calls which have stacked up.
*/
}

int main() {
	countdown(10);

	return 0;
}

