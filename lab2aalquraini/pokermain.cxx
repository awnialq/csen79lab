/*
 * CSEN 79 Lab: Poker Statistics
 * Name: aalquraini
 * Email: aalquraini@scu.edu
 */
#include <ctime>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <cmath>
#include "card.h"
#include "deck.h"
#include "poker.h"

using namespace std;
using namespace lab2aalquraini;

// Generate one sample hand for each rank
void pokerHands(Poker &poker) {
	/*
	 * Loop until you have found one of each rank.
	 * Print that "sample hand"
	 */
	bool each_type[Poker::Rank::POKER_ARRAY_SIZE] = {false};	//default initializes an array to false
	char cntr = 0;	// a counter of type char to save memory
	while(cntr < Poker::POKER_ARRAY_SIZE){	//makes sure we only print out the first 8 occurences of unique hands
		/*
		*Deals a hand and then ranks it. It then checks if that type of hand has been drawn before. If it has not, we increment the counter and we set its occurence to true
		* in the flag array and then print out the hand information.
		*/
		poker.dealHand();
		char handType = poker.rankHand();
		if(!each_type[handType]){
			cntr++;
			each_type[handType] = true;
			cout << poker // Align the poker hand
				 << setw(20) << " " << Poker::RankNames[handType] // Align the rank name
				 << endl;
		}
	}
}

// Collect statistics for each rank of Poker
void pokerStats(Poker &poker) {
	int hand_count[Poker::Rank::POKER_ARRAY_SIZE] = {0};	//init the whole array to 0.
	const int num_hands = 5000000;	// a constant variable used during testing to make sure you get the right stats.
	time_t tmark = clock();			// ready, get set, go!
	/*
	 * Do your thing here.
	 * This is supposed to be big loop that deal many many poker hands and collect the
	 * statistics for each rank.
	 * Once you believe the statistics are good.  Exit the loop.
	 * "tmark" then computes the number of "clock ticks" in your loop.
	 * You should convert that to human friendly units, such as "seconds"
	 * 
	 * Output your stats then, with the amount of time it took you collect the stats.
	 */

	for(int i = 0; i < num_hands; i++){	//processes the dealing of num_hands hands.
		poker.dealHand();
		char hand_type = poker.rankHand();
		hand_count[hand_type]++;
	}
	tmark = clock() - tmark;	// stop the clock
	double tmark_seconds = static_cast<double>(tmark) / CLOCKS_PER_SEC;	//converts the amount of clock cycles to seconds using the ctime library variable CLOCKS_PER_SEC
	cout << "Dealt " << num_hands << " hands. Elapsed Time: " << tmark_seconds << " seconds." << endl;
	cout << "Average " << tmark_seconds/(num_hands/50000) << " seconds per 50k hands" << endl;	//computation of seconds per 50k hands
	cout << fixed << setprecision(2);	//makes sure all floats print with a percision of 2 decimal places (x.xx%)
	for(int i = Poker::POKER_ARRAY_SIZE - 1; i >= 0; i--){	//Prints out each poker hand name, frequency of pulling that hand, and the percentage of hands that were of that tyep
		cout << setw(16) << Poker::RankNames[i] << ":";
		cout << setw(9) << hand_count[i];
		cout << setw(7) << ((double)hand_count[i]/(double)num_hands) * 100 << "%" << endl;
	}
}

int main(void) {
	Poker poker;
	cout << "Sample hand for each Rank:" << endl;
	pokerHands(poker);
	cout << endl << "Statistics:" << endl;
	pokerStats(poker);

	return EXIT_SUCCESS;
}
