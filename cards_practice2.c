#include<stdio.h>
#include<stdlib.h>

char** createsingledeck(int, int);
void fillsingledeck(char**, int, int);
void printsingledeck(char**, int, int);
void freeall(char**, int);

int main(void) {
				
				int i, j, sum = 0;
				int Numofeachcard = 4;
				int NumofTENS = 16;

				// Single array method for 1 DECK
				char cardValues[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
				char cardSuits[] = {'H', 'D', 'C', 'S'};
				for(i=0;i<sizeof(cardValues);i++) {
								if(i<9) {
												for(j=0;j<Numofeachcard;j++) {
																sum += 1;
																printf("%d ", cardValues[i]);
												}
												printf("\n");
								}else{
												for(j=0;j<NumofTENS;j++) {
																sum += 1;
																printf("%d ", cardValues[i]);
												}
								}
				}
				printf("\n");
				printf("sum = %d\n", sum);


				// Matrix method
				printf("Now let's try matrix method\n");
				int suits = 4;
				int ranks = 13;
				char** singledeck = createsingledeck(suits, ranks);
				fillsingledeck(singledeck, suits, ranks);
				printsingledeck(singledeck, suits, ranks);;
				freeall(singledeck, suits);

				return 0;
}

char** createsingledeck(int r, int c) {
				int i = 0;
				char** m = malloc(r*sizeof(char*));
				if(m == NULL) {
								fprintf(stderr, "Memory allocation failed\n");
								exit(1);
				}
				for(i=0;i<r;i++) {
								m[i] = malloc(c*sizeof(char));
				}
				return m;
}

void fillsingledeck(char** m, int r, int c) {
				int i, j;
				for(i=0;i<r;i++) {
								for(j=0;j<c;j++) {
												m[i][j] = 1 + j;
								}
				}
}
void printsingledeck(char** m, int r, int c) {
				int i, j;
				for(i=0;i<r;i++) {
								for(j=0;j<c;j++) {
												printf("%d ", m[i][j]);
								}
								printf("\n");
				}
}
void freeall(char** m, int r) {
				for(int i=0;i<r;i++) {
								free(m[i]);
								m[i] = NULL;
								printf("row freed\n");
				}
				free(m);
				m = NULL;
				printf("singledeck successfully freed\n");
}
								

