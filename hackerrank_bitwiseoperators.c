#include<stdio.h>
#include<stdlib.h>

//Hackerrank challenge: Bitwise operators - PASSED :)

void calculate_the_maximum(int n, int k) {
		int i, j;
		int max = 0;
		int max2 = 0;
		int max3 = 0;
		int tmp = 0;
		int tmp2 = 0;
		int tmp3 = 0;
		for(i=1;i<=n;i++) {
				for(j=i+1;j<=n;j++) {
						tmp = i & j;
						tmp2 = i | j;
						tmp3 = i ^ j;
						printf("%d & %d = %d\n", i, j, tmp);
						printf("%d | %d = %d\n", i, j, tmp2);
						printf("%d ^ %d = %d\n", i, j, tmp3);
						if((tmp > max) && (tmp < k)) {
								max = tmp;
						}
						if((tmp2 > max2) && (tmp2 < k)) {
								max2 = tmp2;
						}
						if((tmp3 > max3) && (tmp3 < k)) {
								max3 = tmp3;
						}
				}
		}
		printf("Max = %d\n", max);
		printf("Max2 = %d\n", max2);
		printf("Max3 = %d\n", max3);
}


int main(int argc, char** argv) {
		
		int n = 5;
		int k = 4;
		calculate_the_maximum(n, k);

		return 0;

}

