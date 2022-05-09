#include<stdio.h>

void loop(int x[], int size) {
		for(int i=0; i<size; i++) {
				printf("[%02d] ", x[i]);
		}
		printf("\n");
}
void reverseloop(int y[], int size) {
		for(int i=(size-1); i>=0; i--) {
				printf("[%02d] ", y[i]);
		}
		printf("\n");
}
void ptrloop(int *p, int size) {
		for(int i=0; i<size; i++, p++) {
				printf("%02d ", *p);
		}
		printf("\nptr after loop = %p\n", p);
}
void bigger(int *arr, int size) {
		int sum = 0;
		printf("Since previous ptrloop was external to main, it's final position is irrelevant and only the original ptr position from main is used for this loop:\n");
		for(int i=0; i<size; i++, arr++) {
			//	printf("%d %d\n", i, *arr);//prints garbage values...when passing ptr.? SEE ANSWER AT BOTTOM!
				sum = (*arr) * 2;
				printf("%02d ", sum);
		}
		printf("\n");
//		return sum;
}
int main(int argc, char** argv) {
		int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		int size = sizeof(numbers) / sizeof(numbers[0]);
		printf("size is: %d\n", size);

		puts("Normal loop:");
		loop(numbers, size);
		puts("Reverse loop:");
		reverseloop(numbers, size);

		int* ptr = numbers;
		printf("&numbers(same as ptr) = %p\n&ptr = %p\nptr before loop = %p\n", &numbers, &ptr, ptr);
		puts("Pointer traversing:");//Comment this loop out before calling external fn!! - ANSWER: Don't need to now, since the loop is now outside of main. So ptr position is always at 0 in main.
		ptrloop(ptr, size);
		bigger(ptr, size);//		This doesn't work in the external function....Seems to print garbage values...and I can't figure out why.  
/*FFS!! THIS IS WHY IT WOULDN'T WORK!  From the point when I declared the pointer, I had performed a loop (INSIDE MAIN) to print out the values, and this must have left the pointer pointing to 10 instead of resetting it back to [0].  So it now works when I comment out the loop!!  FFS!!!!!!
All along with the external fn, I could not figure out why *arr would not give me the expected value it should have(which was the same as *ptr or numbers[0] et al.).
		*/
		
		return 0;
}

