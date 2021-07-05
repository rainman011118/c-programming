#include<stdio.h>
#include<stdlib.h>

void fill_array(int array[], int size) {
		for(int i=0; i<size; i++) {
				array[i] = i*10;
		}
}
void print_array(int array[], int size) {
		for(int i=0; i<size; i++) {
				printf("arr[%d]: %d\n", i, array[i]);
		}
}
int main(int argc, char** argv) {
		int arr[10] = {0};
		int size_arr = sizeof(arr) / sizeof(arr[0]);
		printf("size_arr is: %d\n", size_arr);
		
		fill_array(arr, size_arr);
		print_array(arr, size_arr);//Can do it this way or just return pointer from 'fill_array' and loop print it.

		return 0;

}

