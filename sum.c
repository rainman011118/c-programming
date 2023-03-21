#include<stdio.h>
#include<stdlib.h>

// This is annoying the hell out of me....it should be so simple, but I can't fucking figure it out...with teh min, max and sum.  with them being 0 it is throwing the loops checks off....ffs

// SORTED! 17/1/23 HACKERRANK MINI-MAX SUM

int main() {
		int size = 5;
		int arr[] = {140638725, 436257910, 953274816, 734065819, 362748590};
		//practice array//int arr[] = {5, 8, 3, 7, 1};
		int* p = arr;
		int i, j;
		long min = 0;
		long max = 0;
		long sum = 0;
		for(i=0;i<size;i++) {
				sum = 0;
				for(j=0;j<size;j++) {
						if(i==j) {
								continue;
						}else{
								sum += arr[j];
						}
				}
				//printf("sum = %ld\n", sum);
				while(min == 0) {
						min = sum;
				}
				if(sum >= min) {
						if(sum >= max) {
								max = sum;
						}
				}else{
						min = sum;
				}
		}
//		printf("min = %ld\nmax = %ld\nlargest sum = %ld\n", min, max, sum);
		printf("%ld %ld\n", min, max);

		return 0;
}
