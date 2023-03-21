#include <stdio.h>

// SEE END FOR getc/putc, getchar/putchar, fgetc/fputc.

int main(int argc, char** argv) {
    FILE *fp, *fp1;
	unsigned char SIZE = 100;
    char buffer[SIZE];
	char ch;

    fp = fopen("/home/rain/Testfolder/BBB.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return (-1);
    }
//##############################################################################

	// USING FGETC IN WHILE LOOP (Read upto EOF): 
	while((ch = fgetc(fp)) != EOF) {
			putchar(ch);
			//printf("%c", ch);
	}
//###############################################################################

  // USING FREAD() (Reads everything upto the buffer size specified or EOF): 
  //The arguments[1] takes 'what ever the size of the datatype is' so char = 1, int = 4.
  // The argument[2] asks 'how many of these datatypes?' so 100 bytes for chars. (If it was a string literal, then 'SIZE' would be replaced with 1.
	fread(buffer, sizeof(char), SIZE, fp);
	puts(buffer);	
//################################################################################

	/*To write to a file: 
	This essentially copies contents from one file to another. NOTE: 'read' file must be open too otherwise it will = SEGFAULT! (It still compiles even if closed!! :s) ALSO: if I read from the file first and then write from the same file > new file, the contents of new file are BLANK. (This may be because the file pointer finishes at the end of the file, so when it comes to write, there is nothing to write.  Therefore, if I type: fp = fopen("/home/rain/Testfolder/BBB.txt" "r") again, it will reset pointer to start.) ALTERNATIVE IS TO USE FSEEK(fp, 0, SEEK_SET).
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


/*	
 *	getc(*STREAM) and putc(*STREAM) both take a file stream as args
 *	getchar() == getc(stdin)
 *	putchar(ch) == putc(ch, stdout)
 *	fgetc/fputc == getc/putc BUT there is something to do with MACROS....which I don't understand.
 */
