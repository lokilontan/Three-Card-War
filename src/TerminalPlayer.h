/*
 * TerminalPlayer.h
 *
 *  Created on: Dec 2, 2019
 *      Author: student
 */

#ifndef TERMINALPLAYER_H_
#define TERMINALPLAYER_H_
#include "Player.h"
#include <iostream>

class TerminalPlayer: public Player {
public:
	TerminalPlayer(std::string name) : Player(name){

	}

	virtual ~TerminalPlayer();

	const Card playCard(const Card opponentCard);
};

#endif /* TERMINALPLAYER_H_ */
