#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#define ncards 52

// Also see: https://www.youtube.com/watch?v=JF6RDcXnVKI for a C++ version

//   *************************  NOT FINISHED ************************************

struct card {
		char* suit;
		char* value;
};

void printcards(struct card*);

// Basic method:
// Create a 'card' - this has to have a suit and a rank, So make a struct with both these properties
// Create 52 structs
// Assign each one with a suit and rank...used static arrays for this...? Why were they matrices and not just simple 2D arrays???????
// OR PERHAPS I CAN USE ENUMS.......

int main(int argc, char** argv) {
		int i;

		//Using enums
		enum suits{Diamonds, Hearts, Spades, Clubs};
		enum suits S;
		for(i=0;i<4;i++) {
				printf("%d\t", S+i);
		}
		printf("\n");

		enum ranks{Ace, two, three, four, five, six, seven, eight, nine, ten, J, Q, K};
		enum ranks R;
		for(i=0;i<13;i++) {
				printf("%d\t", R+i);
		}
		printf("\n");

		/* Original
		srand((unsigned)time(NULL));
		int i, r;
		char name[4][9] = { {"D"}, {"C"}, {"H"}, {"S"} };
		char num[13][6] = { {"A"}, {"2"}, {"3"}, {"4"}, {"5"}, {"6"}, {"7"}, {"8"}, {"9"}, {"10"}, {"J"}, {"Q"}, {"K"} };

		//Declares 52 structs
		struct card c[ncards];
		struct card temp;

		//pointer to struct
		card* p = c;

		//Assign suits to all 52 cards and ranks
		for(i=0;i<52;i++) {
				c[i].suit = name[i % 4];
				c[i].value = num[i % 13];
		}
		printcards(p);
		printf("\n");

		//Now randomly sorts the struct.  Why use ABC swap and not just sort randomly to start with...?
		for(i=0;i<52;i++) {
				r = rand() % 52;
				temp = c[i];
				c[i] = c[r];
				c[r] = temp;
		}

		printcards(p);
		printf("\n");
*/
		return 0;
}


void printcards(struct card* ptr) {
		int i;
		for(i=0;i<52;i++) {
				printf("%s %s\t", (ptr+i)->suit, (ptr+i)->value);
		}
}


//6 decks of cards consists of:
//	24 of each value A-9 for a total of 216  and 96 'ten' value cards. Overall 312.
//	Make an array:
//		char array[10];
//		{24, 24, 24, 24, 24, 24, 24, 24, 24, 96};
//
//	Now this can be used to work out the probablities, but not the individual hand scores, since, we need the individual values of each card

// For that we could use the struct for each individual card like above, or what if we simply assign a value for each element of 24 by using a loop...?
//	for(i=1;i<=9;i++) {
//		for(j=0;j<24;j++) {
//			printf("%c",i);
//		}
//		printf("\n");
//	}
