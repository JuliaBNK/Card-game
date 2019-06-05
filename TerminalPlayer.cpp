/*
 * TerminalPlayer.cpp
 *
 *  Created on: May 7, 2019
 *      Author: Julia Buniak
 */

#include <vector>
#include <iostream>
#include<string>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "TerminalPlayer.h"

using namespace std;

TerminalPlayer::TerminalPlayer(std::string name) : Player(name){

}

TerminalPlayer::~TerminalPlayer(){

}

/*Tell the player if they are going first (they received a joker) or they are going second (they received the card played by their opponent)
Display the cards in the player's hand (could be 1 - 3) cards
Prompt the player for the card they want to play
Removed the chosen card from the player's hand and return the chosen card */

/**
 * Play a card. If the player receives a joker then this player is going first
 */
const Card TerminalPlayer::playCard(const Card opponentCard) {
	unsigned select;

	// check if opponentCard is a joker, it so terminal player is going first, else we are going second
	if (opponentCard.isJoker()) {
		cout << "\nYou are going first" << endl;
	}
	else {
		cout << "\nNew round.\nYour opponent played a " << opponentCard << endl;
	}

	// display the cards in the player's hand
	cout << "You have the following cards: " << endl;
	for (unsigned i=0; i<hand.size(); i++) {
		cout << i +1 << ": " << hand[i] << endl;
	}

	// prompt the user to select a card (1 - number of cards). Remember to do error and range checking
	cout << "Select a card in the range between 1 and " << hand.size()<< ": " << endl;
    // checking if we got a number and not char
    while (true){
        cin >> select;
        if (cin) {
            // got an int; checking if a number within given range, leave loop if correct
            if (select >=1 && select <= hand.size()) {
                break;
            }
            cout << "Sorry, " << select << " is not in the range; please try again" << endl;
        } else if (cin.fail()) {
			cout << "Sorry, that was not a number; please try again"<<endl;

			// we found something that wasn’t an integer
			cin.clear();

			// Ignore to the end of file
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }  else {
			// eof or something bad: give up
			cerr << "no input" << endl;
			break;
		}
    }

	// remove the selected card from the player's hand and return
	// http://www.cplusplus.com/reference/vector/vector/erase/

	Card cardSelected = hand[select-1];

    // we have the selected card so we can now erase it from the hand vector

	hand.erase(hand.begin()+(select-1));

	return cardSelected;
}


/**
 * Output the player's name
 */
 std::ostream& operator<<(std::ostream& out, const Player& p){
	 return out<<p.name;
 }



