//============================================================================
// Name        : Lab14_War.cpp
// Author      : 
// Version     :
// Copyright   : @Julia Buniak
// Description : Game loop for War of Cards
//============================================================================

#include <iostream>
#include <string>
#include <stdexcept>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "TerminalPlayer.h"
#include "ComputerPlayer.h"
using namespace std;

int main() {

	// instantiate two players
	ComputerPlayer compPlayer("Computer");
	TerminalPlayer termPlayer("You");
    //ComputerPlayer termPlayer("Comp1");

	//instantiate and shuffle the deck
	Deck deck;
	deck.shuffle();

	//instantiate a joker and cards to play for players
	Card joker;
	Card termPlayerCard;
	Card compPlayerCard;

	for (int i = 1; i <= 3; i++) {
		termPlayer.receiveCard(deck.draw());
		compPlayer.receiveCard(deck.draw());
	}

	// determine who goes first
	int order = rand() % 2;

	//checking if players have at least one card each
	while (termPlayer.hasCards() || compPlayer.hasCards()) {

		if (order == 0) {
			//termPlayer goes first (order ==0)
			termPlayerCard = termPlayer.playCard(joker);
			compPlayerCard = compPlayer.playCard(termPlayerCard);

		} else {
			// compPlayer goes first (order == 1)
			compPlayerCard = compPlayer.playCard(joker);
			termPlayerCard = termPlayer.playCard(compPlayerCard);
		}

		//inform the players which cards have been played
		termPlayer.cardsPlayed(termPlayerCard, compPlayerCard);
		compPlayer.cardsPlayed(termPlayerCard, compPlayerCard);
		cout << "You played " << termPlayerCard << ", Computer played " << compPlayerCard << endl;

		// compare the played cards
	    // if terminal player's card has smaller rank than computer player's one, compPlayer won
		// It will keep both cards and set them aside, and it will play first next round
		if (operator<(termPlayerCard, compPlayerCard )){
		    order = 1;
		    compPlayer.addScore(2);
		    cout << compPlayer << " won this round."<< endl;
		    cout << "The score is: " << endl;
		    cout << compPlayer << " - " << compPlayer.getScore() << endl;
		    cout << termPlayer << " - " << termPlayer.getScore() << endl;

		// if players played equal card, both players retain their cards and set them aside
		// original first player goes first again
		} else if (operator== (termPlayerCard, compPlayerCard)) {
		    compPlayer.addScore(1);
		    termPlayer.addScore(1);
		    cout << "There is no winner in this round."<< endl;
		    cout << "The score is: " << endl;
		    cout << compPlayer << " - " << compPlayer.getScore() << endl;
		    cout << termPlayer << " - " << termPlayer.getScore() << endl;
		// if a terminal player played greater card than comPlayer, he won
		// terminal player will go first next round (order = 0)
		} else {
			order = 0;
			termPlayer.addScore(2);
			cout << termPlayer << " won this round."<< endl;
			cout << "The score is: " << endl;
			cout << termPlayer << " - " << termPlayer.getScore() << endl;
			cout << compPlayer << " - " << compPlayer.getScore() << endl;
		}
		// check if there are still cards in the deck before next round
	    if (!deck.isEmpty()) {
			// deal one card to each player
			termPlayer.receiveCard(deck.draw());
			compPlayer.receiveCard(deck.draw());
		}
	}

	// determine a winner
	if (compPlayer.getScore() > termPlayer.getScore()){
		cout << compPlayer <<" is a winner!" << endl;
		cout << "The score is: " << compPlayer.getScore() << "-" << termPlayer.getScore() << endl;
	} else if (termPlayer.getScore() > compPlayer.getScore()){
		cout << termPlayer <<" is a winner!" << endl;
		cout << "The score is: " << termPlayer.getScore() << "-" << compPlayer.getScore() << endl;
	} else{
		cout << "There is no winner in this game" << endl;
		cout << "The score is: " << compPlayer.getScore() << "-" << termPlayer.getScore() << endl;
	}


	return 0;
}
