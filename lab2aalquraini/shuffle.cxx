/*
 * Name: aalquraini
 * Email: aalquraini@scu.edu
 */
#include <iostream>
#include "card.h"
#include "deck.h"

namespace lab2aalquraini {
	// Uses fisher-yates algorithm to shuffle the deck
	void Deck::shuffle() {
		for (int i = nCards - 1; i > 0; --i) {
			// Generate a random index between 0 and i
			int j = rand() % (i + 1);

			// swap the cards
			std::swap(cards[i], cards[j]);
		}

		// reset next
		next = 0;
	}

	// checks if the gaurd value has been passed and reshuffles if it has been. then deals out one card
	const Card &Deck::deal() {
		if(CARDS_PER_DECK - next <= guard) {
			shuffle();
		}
		return cards[next++];
	}
}

