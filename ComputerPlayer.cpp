/*
 * ComputerPlayer.cpp
 *
 *  Created on: May 13, 2019
 *      Author: Julia Buniak
 */


#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "ComputerPlayer.h"

using namespace std;

ComputerPlayer::ComputerPlayer(std::string name) : Player(name){

}

ComputerPlayer::~ComputerPlayer(){

}

const Card ComputerPlayer::playCard(const Card opponentCard) {
	unsigned select;
	Card cardSelected;

	// check if opponentCard is a joker, it so computer player is going first, else it's going second
	// if computer player is first, the pick of a card is random
	if (opponentCard.isJoker()) {
        select = rand() % 3;
        cardSelected = hand[select];
        hand.erase(hand.begin()+select);
	}
    // computer player goes second
	else {
        // first, computer player checks for cards larger than opponent card
		// vector will contain cards which are larger then opponent card
		vector<Card>largerCards;
		for(unsigned i=0; i<hand.size(); i++) {
			if (operator<(opponentCard, hand[i])){
				largerCards.push_back(hand[i]);
			}
		}
		//if computer player has cards larger than opponent card, it picks the smallest one among them and use it in the game
		if (largerCards.size()!=0) { // compPlayer has larger card than opponent card
			//put cards in ascending order
            sort(largerCards.begin(), largerCards.end());
            //select the smallest card among those that are larger then opponent card
		    cardSelected = largerCards[0];
		    //remove the selected card from the hand
		    for (unsigned i=0; i<hand.size(); i++) {
		    	if (operator==(cardSelected, hand[i])){
		    		hand.erase(hand.begin()+i);
		    	}
		    }
		}
	    // If vector largerCards is empty, computer player doesn't have a card larger then opponent card
		// Then it checks his hand to find a card with the equal rank card
		else { // compPlayer doesn't have cards larger than opponent card
			//vector will contain cards equal to opponent card
			vector<Card>equalCards;
			for (unsigned i=0; i<hand.size(); i++){
				// trying to find an equal card
				if(operator==(opponentCard, hand[i])){
					equalCards.push_back(hand[i]);
				}
			}
			//if computer has equal rank card, it will play it
			if(equalCards.size()!=0){
				cardSelected = equalCards[0];
				//remove the card from the hand
				for (unsigned i=0; i<hand.size(); i++) {
					if (operator==(cardSelected, hand[i])){ // if there are two cards with the same rank as an opponent card, wrong card might be erased
					    hand.erase(hand.begin()+i);
					    break; // how to do it just one time?
					}
				}
			}
		    // if computer player doesn't have an equal card, it will play the smallest card from hand
			else {
                Card cardMin = hand[0];
                for (unsigned i=0; i<hand.size(); i++){
                    if(operator<(hand[i], cardMin)){
                	    cardMin = hand[i];
                    }
                }
                cardSelected = cardMin;
                //remove the selected card from the hand
                for (unsigned i=0; i<hand.size(); i++) {
                    if (operator==(cardSelected, hand[i])){
                        hand.erase(hand.begin()+i);
                    }
                }
		    }//end else for case when compPlayer plays the smallest card
		}// end else for case when compPlayer doesn't have cards larger than opponent card
	}//end else foe case when compPlayer goes second
	return cardSelected;
}





