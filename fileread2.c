#include<stdio.h>

int main(int argc, char** argv) {
		FILE* fp = fopen("/home/rain/Testfolder/BBB.txt", "r");
		if(fp==NULL) {
				perror("Error opening file");
				return -1;
		}
		int ch;
		while((ch = fgetc(fp)) != EOF) {
				putchar(ch);
		}
		
		fclose(fp);
		return 0;
}

