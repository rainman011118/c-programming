#include<stdio.h>

//Using fprintf to write to a file
//the 'x' in the mode part is an 'exclusive create-and-open mode' and returns NULL if file already exists or could not be opened. Thereby protecting against accidental overwrites.

int main(int argc, char** argv) {
		
		FILE* fp;
		fp = fopen("/home/rain/Testfolder/DDD.txt", "wx");
		if(fp==NULL) {
				perror("Error opening file");
				return 1;
		}
		fprintf(fp, "%s\n", "Welcome to the city bitch!"); 
		puts("File successfully written");
		fclose(fp);

		return 0;
}

