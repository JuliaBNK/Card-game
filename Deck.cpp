/*
 * Deck.cpp
 *
 *  Created on: May 3, 2019
 *      Author: Julia Buniak
 */


#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include <cstddef>
#include <stdexcept>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

#define MaxCards 52

/**
 * The Deck class holds a deck of 52 cards. Cards are not removed
 * from the Deck.
 */

unsigned nextCard;
std::vector<Card> cardDeck;

/**
 * Constructor and destructor
 */
Deck::Deck() {
	nextCard = 0;
	cardDeck[MaxCards];
	for(int rank = 1; rank < 14; rank++){
		for(int suit = 0; suit < 4; suit++){
			Card::Suit suitTemp = static_cast<Card::Suit>(suit);
			Card::Rank rankTemp = static_cast<Card::Rank>(rank);
			Card cardTemp(suitTemp, rankTemp);
			cardDeck.push_back(cardTemp);
			nextCard++;
	     }
	}
}

Deck:: ~Deck() {

}
/**
 * Shuffle the deck and reset the next available card to the beginning of the deck
 */
void Deck::shuffle(){

    random_shuffle(cardDeck.begin(), cardDeck.end());
    nextCard = 0;
}

/**
 * Return true if the deck is empty (next available card is past the end of the deck)
 */
bool Deck::isEmpty() const{
	if (nextCard == MaxCards){
		return true;
	}
	else {
		return false;
	}
}

/**
 * Draw a card from the deck. If someone attempts to draw a card when the deck is
 * empty then throw an out-of-range exception.
*/
const Card Deck::draw(){
	if (isEmpty()){
		throw out_of_range ("The Deck is empty!");
    }
	return cardDeck[nextCard++];
	}

