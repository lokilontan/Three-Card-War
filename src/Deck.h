/*
 * Deck.h
 *
 * Deck class that holds Card objects
 */

#ifndef DECK_H_
#define DECK_H_

#include <vector>
#include "Card.h"

#define MaxCards 52

/**
 * The Deck class holds a deck of 52 cards. Cards are not removed
 * from the Deck.
 */
class Deck {
public:
	/**
	 * Constructor and destructor
	 */
	Deck();
	virtual ~Deck() {
		// empty
	}

	void shuffle();

	/**
	 * Return true if the deck is empty (next available card is past the end of the deck)
	 */
	bool isEmpty() const;

	/**
	 * Draw a card from the deck. If someone attempts to draw a card when the deck is
	 * empty then throw an out-of-range exception.
	 */
	const Card draw();
	/**
	 * Output the deck to an output stream as the lost of"rank of suit"
	 */
	friend std::ostream& operator <<(std::ostream&, const Deck&);


private:
	unsigned nextCard;
	std::vector<Card> cardDeck;
};

#endif /* DECK_H_ */
