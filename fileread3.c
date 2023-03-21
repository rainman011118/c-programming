#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
		int x, y;
} Point;

int main(int argc, char** argv) {
		Point p1 = {
				.x = 15,
				.y = -9
		};

		//Create 2 file handlers:
		FILE* in;
		FILE* out;

		//create 2 places to store info:
		char buffer_in[64], buffer_out[64];

		//point.dat should be created as a new file in which the info (x and y) will be written to.
		out = fopen("point.dat", "wx");
		if(out == NULL) {
				perror("Error opening file");
				return 1;
		}
		
		//sprintf converts data to string format and prints it to buffer_out.
		//So the 2 ints are converted to a string and written to buffer_out.
		sprintf(buffer_out, "%d, %d\n", p1.x, p1.y);

		//fwrite returns the number of bytes written.
		//This then writes the buffer_out to the file
		size_t bytes_written = fwrite(buffer_out, sizeof(char), strlen(buffer_out), out);
 
		printf("Me just checking how many bytes of strlen(buffer_out) = %ld\nFile successfully written\n", strlen(buffer_out));

		//This if statement below is just a check to see if the correct number of bytes were written
		if(bytes_written != strlen(buffer_out)) {
				return 1;
		}

		fclose(out);
		return 0;
}

/* SEE: https://www.youtube.com/watch?v=da9D4Bcsrgc&list=PLfqABt5AS4Fmv8DszqJjIjmCjvTtTVslT&index=11
Need to go over this again, to understand it fully. */ 

