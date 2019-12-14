/*
 * ComputerPlayer.cpp
 *
 *  Created on: Dec 7, 2019
 *      Author: student
 */

#include "ComputerPlayer.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <stdexcept>


using namespace std;

ComputerPlayer::~ComputerPlayer() {
	// TODO Auto-generated destructor stub
}

const Card ComputerPlayer::playCard(const Card opponentCard) {

	if (hasCards()) {
		srand(time(NULL));
		int i = rand() % hand.size();
		Card cardToReturn = hand[i];
		hand.erase(hand.begin() + (i));
		return cardToReturn;

		}
	else throw std::out_of_range ("Computer player has no cards in hand!");

}

