/*
 * AIPlayer.cpp
 *
 *  Created on: Dec 9, 2019
 *      Author: student
 */

#include "AIPlayer.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <stdexcept>

AIPlayer::~AIPlayer() {
	// TODO Auto-generated destructor stub
}

void AIPlayer::playedCards(const Card card1, const Card card2){
	if (cardsPlayed.size()==52) {			//Check if new game started, if so,
		cardsPlayed.clear();				//clear the counted cards from the previous game
		cardsPlayed.push_back(card1);		//Count new cards
		cardsPlayed.push_back(card2);
	}
	else {
		cardsPlayed.push_back(card1);		//Don`t clean and just count
		cardsPlayed.push_back(card2);
	}
}

/**
	 * Play a card. If the opponentCard is a joker then this player is going first and
	 * the probability stuff starts to work, if there is an opponent card then we
	 * choose the lowest card in the hand that is higher than the opponent's played card
	 */
const Card AIPlayer::playCard(const Card opponentCard) {
	Card cardToReturn;
	if (hasCards()){
		if (opponentCard.isJoker()) {					//If AI goes first then it has to choose the best card to win the round, relying on probability
			cardToReturn = hand[0];
			for (auto card: hand) {
				if (beatP(card) > beatP(cardToReturn)) {
					cardToReturn = card;
				}
			}
		}
		else {
			for (auto card: hand) {								//If AI goes second then it checks if it even
				if (opponentCard < card) {cardToReturn = card;}	//has a card higher than opponent`s card
			}													//If it doesn`t then cardToReturn remains joker

			if (cardToReturn.isJoker()){						//Check if AI can get at least a point for push
				for (auto card: hand) {
					if (opponentCard == card) {cardToReturn = card;
						}
				}
				if (cardToReturn.isJoker()) {						//If cardToReturn is still joker then we don`t have
					cardToReturn = hand[0];							//greater or equal card and we choose the
					for (auto card: hand) {							//smallest one to return (we loose but keep
						if (card < cardToReturn) {					//the highest cards)
							cardToReturn = card;
						}
					}
				}
			}
			else {
																	//If cardToReturn after the first check is not
				for (auto card: hand) {								//joker, then we choose the lowest card in
					if ((opponentCard < card)&&(card < cardToReturn)) {		//the hand that is higher than the
						cardToReturn = card;								//opponent's played card
					}
				}
			}
		}
		int i = 0;
		int index = 0;
		for (i; i < hand.size(); i++ ) {						//Get the hand index of the cardToReturn
			if (cardToReturn == hand[i]) index = i;
		}
		hand.erase(hand.begin() + (index));						//Erase the hand[index]
		return cardToReturn;									//FINALLY, return the card
	}
	else
		throw std::out_of_range ("AI player has no cards in hand!");

}

//Beating probability. Returns a double which is a percentage of the beating probability
double AIPlayer::beatP(const Card checkCard) {

	double beatButPlayed = 0;

	for (auto i:hand) {
		if (i.getRank() < checkCard.getRank()) {beatButPlayed++;}
	}
	for (auto i:cardsPlayed) {
			if (i.getRank() < checkCard.getRank()) {beatButPlayed++;}
	}

return (((((checkCard.getRank() - 2) * 4) - beatButPlayed)/(52 - cardsPlayed.size() - hand.size()))*100) ;
}

//Push probability. Returns a double which is a percentage of the push probability
double AIPlayer::pushP(const Card checkCard) {

	double sameCard = 0;

	for (auto i:hand) {
			if (i.getRank() == checkCard.getRank()) {sameCard++;}
	}
	for (auto i:cardsPlayed) {
			if (i.getRank() == checkCard.getRank()) {sameCard++;}
	}

	return (((4 - sameCard)/(52 - cardsPlayed.size() - hand.size()))*100) ;
}


