/*
 * ComputerPlayer.h
 *
 *  Created on: May 13, 2019
 *      Author: student
 */

#ifndef COMPUTERPLAYER_H_
#define COMPUTERPLAYER_H_

#include <vector>

#include "Card.h"
#include "Deck.h"
#include "Player.h"

class ComputerPlayer: public Player {
    public:
	/**
	 * Constructor and destructor
	 */
	ComputerPlayer(std::string name);
	virtual ~ComputerPlayer();

    /**
     * Play a card. If the player receives a joker then this player is going first
     */
    const Card playCard(const Card opponentCard);


};





#endif /* COMPUTERPLAYER_H_ */
