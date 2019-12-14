/*
 * Player.h
 *
 *  This is the Player class and is an abstract class.
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>

#include "Card.h"

#define MAX_HAND_SIZE 3

/**
 * Abstract Player classS
 */
class Player {
public:
	/**
	 * Deconstructor
	 */
	virtual ~Player() {
		// empty
	}

	/**
	 * Play a card. If the opponentCard is a joker then this player is going first else
	 * this player is going second and the opponentCard is the card our opponent played
	 */
	virtual const Card playCard(const Card opponentCard) = 0;

	/**
	 * Receive a card from the dealer
	 */
	void receiveCard(const Card c){
		hand.push_back(c);
	}

	/**
	 * Add points to the score
	 */
	void addScore(unsigned s) {
		score += s;
	}

	/**
	 * Get the score
	 */
	int getScore() const {
		return score;
	}

	/**
	 * Reset the score to zero
	 */
	void resetScore() {
		score = 0;
	}

	/**
	 * Return true if the player has cards in the hand
	 */
	bool hasCards() const {
		return (hand.size() != 0);
	}

	/**
	 * Receive the cards played from the completed round. This member function would
	 * be used by a computer player that may need to 'see' what cards were played.
	 */
	virtual void playedCards(const Card card1, const Card card2) {
		// default empty
	}

	/**
	 * Output the player's name
	 */
	friend std::ostream& operator <<(std::ostream& out, const Player& p){
		out << p.name;
		return out;
	}

protected:
	/**
	 * Constructor. Since this is an abstract class we do not want anyone instantiating
	 * a player class so we make it protected.
	 */
	Player(std::string name) :
			score(0), name(name), hand(0) {
	}

	int score;
	std::string name;
	std::vector<Card> hand;
};

#endif /* PLAYER_H_ */
