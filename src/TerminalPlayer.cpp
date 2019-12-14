/*
 * TerminalPlayer.cpp
 *
 *  Created on: Dec 2, 2019
 *      Author: student
 */

#include "TerminalPlayer.h"
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

TerminalPlayer::~TerminalPlayer() {
	// TODO Auto-generated destructor stub
}

const Card TerminalPlayer::playCard(const Card opponentCard)
{
	if (hasCards()) {
		if (opponentCard.isJoker()) cout << "You are going first." << endl;
		else cout << "You are going second." << endl << endl << "Opponent`s card:                          " << opponentCard << endl << endl;

		cout << "Your cards are: " << endl << endl << "            " ;

		for (std::vector<int>::size_type i = 0; i != hand.size(); i++ ) {cout << "     " << i+1 << "." << hand[i]<< "     " ;}
		cout << endl << endl;
		int n=-1;

		cout << "What card do you want to play? Enter 1, 2 or 3: "; cin >> n;

		while ((n < 1) || (n > hand.size())) {
			cerr << "Wrong number of card!" << endl;
			cout << "What card do you want to play? Enter 1, 2 or 3: "; cin >> n;
		}

		Card cardToReturn = hand[n-1];
		hand.erase(hand.begin() + (n-1));

		return cardToReturn;
	}
		else throw std::out_of_range ("Terminal player has no cards in hand!");
}

