#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//SEE youtube wizardofodds 'Baccarat Analysis'


#define DECK 52
#define TENSINDECK 16
#define NONTENS 36
#define HOWMANYDECKS 8
#define COMMISSION 0.95

int main(int argc, char** argv) {

    //No. of Player cards, banker cards, totals
		int p1, p2, p3, b1, b2, b3, ptot, btot, i, shoe[10];

		//First element holds all the tens in the shoe
		shoe[0] = TENSINDECK * HOWMANYDECKS;;

		//Add the number of cards of each value(4 of each per deck x 8 decks = 32) into the remaining elements.
		for(i=1;i<=9;i++) {
				shoe[i] = 4 * HOWMANYDECKS;
		}

		//combinations, who wins
		ssize_t combin, playerWin, bankerWin, tieWin;
		combin = 1;
		playerWin = 0;
		bankerWin = 0;
		tieWin = 0;
		
		//Now the loops for running through all the possible draws....THIS IS WHERE I GET CONFUSED....
		for(p1=0;p1<=9;p1++) {
				combin *= shoe[p1];	// 1 * 128
				shoe[p1]--;		// This decrements the values at each element.(Not the position in the array)
				for(p2=0;p2<=9;p2++) {
						combin *= shoe[p2];	// 128 * 128
						shoe[p2]--;	// Becomes 127.....Don't get this part...see later also, we add it back????
						for(p3=0;p3<=9;p3++) {
								combin *= shoe[p3];	// 128^3
								shoe[p3]--;
								for(b1=0;b1<=9;b1++) {
										combin *= shoe[b1];	// 128^4
										shoe[b1]--;
										for(b2=0;b2<=9;b2++) {
												combin *= shoe[b2];	// 128^5
												shoe[b2]--;



												// THIS IS MAIN PART ########################################################
												for(b3=0;b3<=9;b3++) {
														combin *= shoe[b3];	// 128^6, then *32 on second run when b3 = 1

														ptot = (p1+p2) % 10;	// equates to 0+0 % 10
														btot = (b1+b2) % 10;	// equates to 0+0 % 10
														if((ptot<8)&&(btot<8)) {
																if(ptot<=5) { //If player has 5 or less, he draws 3rd card...
																		ptot = (p1+p2+p3) % 10;	// equates to 0+0+0 % 10 

																		//This is the complicated drawing 3rd rules....
																		if((btot<=2) || ((btot==3) && (p3 != 8)) || ((btot == 4) && (p3 >= 2) && (p3 <= 7)) || ((btot == 5) && (p3 >= 4) && (p3 <= 7)) || ((btot == 6) && (p3 >= 6) && (p3 <= 7))) {
																						btot = (b1+b2+b3) % 10; // equates to 0+0+0 % 10
																		}
																}else{//if player is 6 or higher, he stands
																				if(btot<=5) {
																								btot = (b1+b2+b3) % 10;
																				}
																}
														}
														//Scoring the hands
														if(ptot>btot) {
																		playerWin += combin;
														}else if(ptot < btot) {
																		bankerWin += combin;
														}else{
																		tieWin += combin; // First outcome is a tie 0+0+0 = 4.398 trillion(128^6)
														}
												combin /= shoe[b3];	// 4.398 trillion / 128 = 34.359 billion
																				// 2nd and subsequent runs we divide by 32 (shoe[1-9] = 32 values)
												}
												// ########################################################################



												shoe[b2]++;	// Becomes 128 again....Adds it back....just to calculate combin??
												combin /= shoe[b2];
										}
										shoe[b1]++;
										combin /= shoe[b1];
								}
								shoe[p3]++;
								combin /= shoe[p3];
						}
						shoe[p2]++;
						combin /= shoe[p2];
				}
				shoe[p1]++;
				combin /= shoe[p1];
		}

		//Total number of each outcome
		printf("Player wins:\t%lu\n", playerWin);
		printf("Banker wins:\t%lu\n", bankerWin);
		printf("tie wins:\t%lu\n", tieWin);

		//Probabilities
		ssize_t tot_combin = playerWin + bankerWin + tieWin;
		double playerProb = (double)playerWin / (double)tot_combin;
		double bankerProb = (double)bankerWin / (double)tot_combin;
		double tieProb = (double)tieWin / (double)tot_combin;
		printf("Player prob:\t%f\n", playerProb);
		printf("Banker prob:\t%f\n", bankerProb);
		printf("tie prob:\t%f\n", tieProb);

		//EV calculations: Not sure why tie is 8 * ???
		double playerEv = playerProb - bankerProb;
		double bankerEv = (COMMISSION * bankerProb) - playerProb;
		double tieEv = (8 * tieProb) - bankerProb - playerProb;
		printf("Player EV:\t%f\n", playerEv);
		printf("Banker EV:\t%f\n", bankerEv);
		printf("tie EV:\t\t%f\n", tieEv);


		return 0;

}
