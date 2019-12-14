/*
 * ComputerPlayer.h
 *
 *  Created on: Dec 7, 2019
 *      Author: student
 */

#ifndef COMPUTERPLAYER_H_
#define COMPUTERPLAYER_H_
#include "Player.h"
#include <iostream>

class ComputerPlayer: public Player {
public:
	ComputerPlayer(std::string name) : Player(name){}

	virtual ~ComputerPlayer();

	const Card playCard(const Card oponentCard);
};

#endif /* COMPUTERPLAYER_H_ */
