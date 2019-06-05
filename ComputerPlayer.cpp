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
	// computer player picks random card despite it's going first or second
        select = rand() % 3;
        cardSelected = hand[select];
        hand.erase(hand.begin()+select);
	    return cardSelected;
}




