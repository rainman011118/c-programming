#include<stdio.h>
#include<stdlib.h>

/* Use of fseek(fp, <relative position in file>, <where in file>)
 * Basically repositions the pointer to anywhere you specifiy in a file
 * fseek(fp, 0, SEEK_SET) 		set pointer to start of file
 * fseek(fp, -7, SEEK_END)		set pointer to -7 bytes from end of file
 * fseek(fp, 20, SEEK_CUR)		set pointer to 20 bytes forward from current position
*/

int main(int argc, char** argv) {
		FILE* fp = NULL;
		int ch;
		char buffer[256];

		fp = fopen("/home/rain/Testfolder/AAA.txt", "r");
		if(fp==NULL) {
				perror("Error opening file");
				return(-1);
		}

		//ftell() returns the current position of the file pointer.
		fseek(fp, 0, SEEK_END);
		printf("Position of pointer in file (which should be the last character since we used seek_end:  %ld\n", ftell(fp));

		// Now to reset the pointer to start of file, in order for fread to work correctly.
		fseek(fp, 0, SEEK_SET);
		fread(buffer, sizeof(char), 256, fp);
		puts(buffer);

		fclose(fp);

		return 0;

}


