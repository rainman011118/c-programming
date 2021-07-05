#include<stdio.h>
#include<stdlib.h>

int* fill_array(int* p, int size) {
		for(int i=0; i<size; i++) {
				p[i] = i*10;
		}
		return p;
}
int main(int argc, char** argv) {
		int arr[10] = {0};
		int size_arr = sizeof(arr) / sizeof(arr[0]);
		printf("size_arr is: %d\n", size_arr);
		
		int* ptr = arr;

		fill_array(ptr, size_arr); 
		for(int i=0; i<size_arr; i++) {
				printf("arr[%d]: %d\n", i, arr[i]);
		}
	
		return 0;

}

