 /*
 * Card.cpp
 *
 *  Created on: May 3, 2019
 *      Author: Julia Buniak
 */

#include <iostream>
#include <string>
#include "Card.h"
#include <cstddef>

using namespace std;

/**
 * Constructor
 *
 * @param s
 * @param r
 */
Card::Card(Suit s, Rank r) {
    cardSuit = s;
	cardRank = r;
}

/**
 * Constructor. This empty constructor will create a joker card.
 * The joker card is a special card given to the player going first.
 */
Card::Card() {
	cardRank = Card::Joker;
	cardSuit = Card::Spades;
}

/**
 * Output the card to an output stream as "rank of suit", except for the joker which is just output as "Joker"
 */
std::ostream& operator <<(std::ostream& output, const Card& c) {
    if (c.cardRank == Card::Joker) {
        return output << rankNames[c.cardRank];
	}
	return output << rankNames[c.cardRank] << " of " << suitNames[c.cardSuit];
}

/**
 * Compare operators. For the game of war we only care about the rank value
 */
bool operator ==(const Card &lhs, const Card &rhs) {
	if (lhs.cardRank == rhs.cardRank)
		return true;
	else
		return false;
}

bool operator <(const Card &lhs, const Card &rhs){
	if (lhs.cardRank < rhs.cardRank) {
		return true;
	}
	else
		return false;
}

