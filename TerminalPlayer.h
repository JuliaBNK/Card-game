/*
 * TerminalPlayer.h
 *
 *  Created on: May 7, 2019
 *      Author: Julia Buniak
 */

#ifndef TERMINALPLAYER_H_
#define TERMINALPLAYER_H_

#include <vector>

#include "Card.h"
#include "Deck.h"
#include "Player.h"

class TerminalPlayer: public Player {
    public:
	/**
	 * Constructor and destructor
	 */
	TerminalPlayer(std::string name);
	virtual ~TerminalPlayer();

    /**
     * Play a card. If the player receives a joker then this player is going first
     */
    const Card playCard(const Card opponentCard);


};

#endif /* TERMINALPLAYER_H_ */
