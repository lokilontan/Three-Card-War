/*
 * Card.cpp
 *
 *  Created on: Nov 23, 2019
 *      Author: student
 */

#include <iostream>
#include "Card.h"

/**
* Constructor
*
* @param s
* @param r
*/
Card::Card(Suit s, Rank r) {
	cardSuit = s;
	cardRank = r;
}

/**
* Constructor. This empty constructor will create a joker card.
* The joker card is a special card given to the player going first.
*/
Card::Card() {
	cardRank = Joker;
	cardSuit = Spades; 		//Logically makes no sense, but it is a good practice to initialize all the member
							//variables to avoid some related issues. In addition, isJoker() checks only the cardRank.
}

/**
 * Output the card to an output stream as "rank of suit", except for the joker which is just output as "Joker"
 */
std::ostream& operator <<(std::ostream& os, const Card& c) {
	if (c.isJoker()) { os << rankNames[0]; } else
		os << rankNames[c.cardRank] << " of " << suitNames[c.cardSuit];
	return os;
}

/**
 * Compare operators. For the game of war we only care about the rank value
 */
bool operator ==(const Card &lhs, const Card &rhs){
	return (lhs.cardRank == rhs.cardRank);
}

bool operator <(const Card &lhs, const Card &rhs){
	return (lhs.cardRank < rhs.cardRank);
}



