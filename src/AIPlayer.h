/*
 * AIPlayer.h
 *
 *  Created on: Dec 9, 2019
 *      Author: student
 */

#ifndef AIPLAYER_H_
#define AIPLAYER_H_

#include "Player.h"
#include <iostream>

class AIPlayer: public Player {
public:
	AIPlayer(std::string name) : Player(name){}

	virtual ~AIPlayer();

	const Card playCard(const Card oponentCard);

	void playedCards(const Card card1, const Card card2);	//Override playedCards to count all the played cards

	double beatP(const Card checkCard);					//Beating probability. Returns a double which is a percentage of the beating probability

	double pushP(const Card checkCard);					//Push probability. Returns a double which is a percentage of the push probability

	double loseP(const Card checkCard) {				//Losing probability. Returns a double which is a percentage of the push probability
														//This one is easy. It is just 100 - (beatP() + pushP())
		return (100 - beatP(checkCard) - pushP(checkCard));
	}
protected:
	std::vector<Card> cardsPlayed;
};

#endif /* AIPLAYER_H_ */
