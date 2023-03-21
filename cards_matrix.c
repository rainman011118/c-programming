#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int** createDeck(int, int);
void zeroFill(int**, int rows, int cols);
void printDeck(int**, int rows, int cols);
void freeDeck(int**, int rows);

// CREATING A DECK OF CARDS VIA MATRIX

int main(int argc, char** argv) {
		int SUIT = 4;
		int RANK = 13;
		int** deck = createDeck(SUIT, RANK);
		zeroFill(deck, SUIT, RANK);
		printDeck(deck, SUIT, RANK);
		freeDeck(deck, SUIT);


		return 0;
}

int** createDeck(int r, int c) {
		int i;
		int** d = malloc(r*sizeof(int*));
		if(d == NULL) {
				fprintf(stderr, "Memory allocation failed\n");
				exit(1);
		}
		for(i=0;i<r;i++) {
				d[i] = malloc(c*sizeof(int));
		}
		printf("Deck successfully created\n");
		return d;
}

void zeroFill(int** d, int rows, int cols) {
		int i, j;
		int val = 1;
		for(i=0;i<rows;i++) {
				for(j=0;j<cols;j++) {
						d[i][j] = val++;
				}
		}
		printf("zerofill complete\n");
}

void printDeck(int** d, int rows, int cols) {
		int i, j;
		for(i=0;i<rows;i++) {
				for(j=0;j<cols;j++) {
						printf("%02d ", d[i][j]);
				}
				printf("\n");
		}
}

void freeDeck(int** d, int rows) {
		int i;
		for(i=0;i<rows;i++) {
				free(d[i]);
				d[i] = NULL;
				printf("row freed\n");
		}
		free(d);
		d = NULL;
		printf("deck freed\n");
}


				
