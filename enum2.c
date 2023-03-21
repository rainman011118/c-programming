#include<stdio.h>
#include<stdlib.h>

enum State {WORKING = 0, FAILED = 1, FROZEN = 2};
enum State currState = 2;

/* //Alternative to the above is to use #define:
#define WORKING 0
#define FAILED 1 
#define FROZEN 2
*/

enum State FindState() {
		return currState;
}

int main(int argc, char** argv) {

		(FindState == WORKING) ? printf("WORKING\n") : printf("NOT WORKING\n");

		return 0;
}
