#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
// *******************  READING INPUT > CONVERTING CHARS TO INT > MAKING MATRIX  ****************

// FINALLY GOT IT ALL WORKING...
// READS ALL TYPES OF CHARS BUT ONLY SELECTS THE CORRECT ONES

//void clearbuffer();
void scanf_int(int*, int*);
void fgets_char(int*, int*);
void free_all(int** root, int rows);
void display(int** r, int rows, int cols);
void fill_matrix(int** r, int rows, int cols);
void make_matrix(int** r, int rows, int cols);

int main(int argc, char** argv) {
		int* root = NULL;
		char* ptr = NULL;
		int SIZE, LEN, ROWS, COLS;
		long choice;
		SIZE = 256;
		char input[SIZE];
		puts("A test programme to make a matrix.\nUsing 1 of 2 methods: scanf(with ints) or fgets.\nI still get confused with the int and char and ASCII interpretation.\nBut each of these methods should work fine now.");

		// TAKE INPUT
		puts("Please select the corresponding number for the method you wish to use for input\nscanf_int (1)\nfgets_char (2)");
		fgets(input, SIZE-1, stdin);
		LEN = strlen(input);
		printf("strlen(input) = %d\n", LEN);
		
		/*JUST CHECKING BUFFER CONTENTS
		printf("printing buffer contents....\n");
		if(LEN<8) {
				for(int i=0;i<LEN;i++) {
						printf("0x%x ", input[i]);
				}
				printf("\n");
		}else{
				printf("Too many bloody chars entered, what do you think this is!!\n");
				exit(1);
		}
		*/

		choice = strtol(input, &ptr, 10);//THIS RETURNS ZERO IF FAILS
		//ERROR CHECKING
		if(choice) {
				printf("Choice = %ld\n", choice);
				if(choice == 1) {
						printf("Choice 1 selected...\n");
//						clearbuffer();//NOTE REQUIRED SINCE EACH FN SEEMS TO HAVE ITS OWN BUFFER
						scanf_int(&ROWS, &COLS);
				}else if(choice == 2) {
						printf("Choice 2 selected...\n");
//						clearbuffer();//NOTE REQUIRED SINCE EACH FN SEEMS TO HAVE ITS OWN BUFFER
						fgets_char(&ROWS, &COLS);
				}else{
						printf("Invalid choice.  Please pick one of the two options shown\n");
						return 1;
				}
		}else{
				printf("ERROR: Choice = %ld\n", choice);
				exit(2);
		}

		//MAIN FUNCTIONS TO MAKE MATRIX;
		make_matrix(&root, ROWS, COLS);
		fill_matrix(&root, ROWS, COLS);
		display(&root, ROWS, COLS);

		//JUST DOUBLE CHECKING THE BUFFER CONTENTS AGAIN....IT IS THE SAME AS EARLIER EVEN AFTER RETURNING...
		printf("printing buffer contents....\n");
		for(int i=0;i<LEN;i++) {
				printf("0x%x ", input[i]);
		}
		printf("\n");

		free_all(&root, ROWS);
		return 0;
}
/*THIS NO LONGER SEEMS TO BE REQUIRED AS EACH FN SEEMS TO HAVE ITS OWN BUFFER...IT WAS FUCKING UP ANYWAY
void clearbuffer() {
		int ch;
		while((ch = getchar()) != '\n' && ch != EOF) {
				printf("clearing buffer: 0x%x\n", ch);
		}
		printf("inside clearbuffer...\t");
		if(ch == '\n') {
				printf("Char left in buffer = 0x%x\n", ch);
		}else{
				printf("Char left in buffer(not NL) = 0x%x\n", ch);
		}
}
*/
void scanf_int(int* rows, int* cols) {
		puts("Welcome to scanf_int");
		puts("Enter number of rows (Must be between 1-10)");
		scanf("%d", rows);
		if(*rows > 0 && *rows < 11) {
				printf("Rows = %d\n", *rows);
		}else{
				printf("Invalid value for rows\n");
				printf("Rows = %d\n", *rows);
				exit(3);
		}
		puts("Enter number of cols (Must be between 1-10)");
		scanf("%d", cols);
		if(*cols > 0 && *cols < 11) {
				printf("Cols = %d\n", *cols);
		}else{
				printf("Invalid value for cols\n");
				printf("Cols = %d\n", *cols);
				exit(3);
		}
		//clearbuffer();// NOT REQUIRED BECAUSE I THINK EACH FUNCTION HAS ITS OWN BUFFER....
}
//FINISHED AND WORKING:
void fgets_char(int* rows, int* cols) {
		int MAX, LEN1, LEN2, VAL, ch;
		MAX = 256;
		char* pointer = NULL;
		char buff1[MAX];
		char buff2[MAX];
		puts("Welcome to fgets_char");
		puts("Enter number of rows");
		fgets(buff1, MAX-1, stdin);
		for(int i=0;i<strlen(buff1);i++) {
				printf("0x%x ", buff1[i]);
		}
		printf("\n");
		LEN1 = strlen(buff1);

	/*	printf("len before chop = %d\n", LEN1);
		buff1[strlen(buff1)-1] = 0; 
		LEN1 = strlen(buff1);
		printf("len after = %d\n", LEN1);
*/
		for(int i=0;i<strlen(buff1);i++) {
				printf("0x%x ", buff1[i]);
		}
		printf("\n");

		VAL = strtol(buff1, &pointer, 10);
		if(VAL > 0 && VAL < 11) {
				*rows = VAL;
				printf("*rows = %d\n", *rows);
		}else{
				printf("Invalid value for rows\n");
				printf("VAL = %d\n", VAL);
				exit(5);
		}
		puts("Enter number of cols");
		fgets(buff2, MAX-1, stdin);
		//LEN2 = strlen(buff2);
		//buff2[strlen(buff2)-1] = 0;

		VAL = strtol(buff2, &pointer, 10); 
		if(VAL > 0 && VAL < 11) {
				*cols = VAL;
				printf("cols int = %d\n", *cols);
		}else{
				printf("Invalid value for cols\n");
				printf("VAL = %d\n", VAL);
				exit(5);
		}
}
void make_matrix(int** r, int rows, int cols) {
		int i;
		*r = malloc(rows*sizeof(int*));
		if(r==NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(6);
		}
		for(i=0;i<rows;i++) {
				r[i] = malloc(cols*sizeof(int));
		}
		printf("%d x %d Matrix created\n", rows, cols);
}
void fill_matrix(int** r, int rows, int cols) {
		printf("Filling matrix....\n");
		int i, j;
		for(i=0;i<rows;i++) {
				for(j=0;j<cols;j++) {
						r[i][j] = (i+j)+5;	
				}
		}
}
void display(int** r, int rows, int cols) {
		puts("displaying matrix....");
		int i, j;
		for(i=0;i<rows;i++) {
				for(j=0;j<cols;j++) {
						printf("%02d ", r[i][j]);
				}
				printf("\n");
		}
}
void free_all(int** root, int rows) {
		if(*root==NULL) {
				printf("root already NULL\n");
				exit(7);
		}else{
				for(int i=0;i<rows;i++) {
						free(root[i]);
						root[i] = NULL;
						printf("Row freed\n");
				}
		}
		free(*root);
		*root = NULL;
		printf("Matrix freed up\n");
}

