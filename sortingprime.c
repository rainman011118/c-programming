#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {
		int array[] = {83,23,61,7,48,33,32,78,19,2};
		int size = sizeof(array) / sizeof(array[0]);
		//Prime loop:
		for(int i=0;i<size;i++) {
				int div = 2;
				for(int j=2;j<array[i];j++) {
						if(array[i] % j == 0) {
								div += 1;
								break;
						}else {continue;};
				}
				if(div<=2) {
						printf("%d\t is PRIME\n", array[i]);
				}
		}
		return 0;
}
//It works but I think I can simplify it in the if loop.  Whereby it doesn't have to go through all the possible range.  Since, once, div > 2, that's enough to prove it isn't prime.


