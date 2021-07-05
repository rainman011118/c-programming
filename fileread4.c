#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {
//		##################Read from a file and write it to another ####################################
		FILE* fp = fopen("/home/rain/Testfolder/BBB.txt", "r");
		if(fp==NULL) {
				perror("Error opening file!\n");
				return -1;
		}
		int ch;
		FILE* fp1 = fopen("/home/rain/Testfolder/CCC.txt", "w");
		if(fp1==NULL) {
				perror("Error opening file!\n");
				return -1;
		}
		while((ch = fgetc(fp)) != EOF ) {
				fputc(ch, fp1);//fp1 can be changed to stdout if you wanted to write to stdout. (But what is the point if read already does this...)
		}
		fclose(fp);
		fclose(fp1);

		return 0;
}
// ################################################################
// perror is better than fprintf 
// since it will include a description of why the error happened.
