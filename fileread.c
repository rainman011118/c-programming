#include <stdio.h>

int main(int argc, char** argv) {
    FILE *fp, *fp1;
	SIZE = 50;
    char str[SIZE];
	char ch;

    fp = fopen("/home/rain/Testfolder/BBB.txt", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return (-1);
    }
/*    //Read 1 line from a file: ########################################
    fgets(str, sizeof(str), fp);
    puts(str);
*/
	//Read upto EOF: ###############################
	while((ch = fgetc(fp)) != EOF) {
			printf("%c", ch);
	}
/*  //Reads everything upto the buffer size specified or EOF: #################################
 *  The arguments[1] takes 'what ever the size of the datatype is'.
 *  The argument[2] asks 'how many of these datatypes?' so 50 bytes for chars. (If it was a string literal, then 'SIZE' would be replaced with 1.
	fread(str, sizeof(char), SIZE, fp);
	puts(str);	
*/
	/*To write to a file: ###############################
	This essentially copies contents from one file to another. NOTE: 'read' file must be open too otherwise it will = SEGFAULT! (It still compiles even if closed!! :s) ALSO: if I read from the file first and then write from the same file > new file, the contents of new file are BLANK. (This may be because the file pointer finishes at the end of the file, so when it comes to write, there is nothing to write.  Therefore, if I type: fp = fopen("/home/rain/Testfolder/BBB.txt" "r") again, it will reset pointer to start.)
	 */
/*	fp1 = fopen("/home/rain/Testfolder/CCC.txt", "w");
	if(fp1==NULL) {
			perror("Error opening file");
			return(-1);
	}
	while((ch = fgetc(fp)) != EOF) {
			fputc(ch, fp1);
	}
	printf("File successfully written\n");

    fclose(fp1);
*/
    fclose(fp);
	
    return 0;
}
