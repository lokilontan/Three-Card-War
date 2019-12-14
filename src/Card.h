/*
 * Card.h
 *
 * Single Card
 */

#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <string>

/**
 * String constants for the suits. Use these for the << operator. Use the ordinal value
 * of the Suit enum as an index to fetch the Card suit name
 */
static const std::string suitNames[] =
		{ "Spades", "Hearts", "Diamonds", "Clubs" };

/**
 * String constants for the rank. Use these for the << operator. Use the ordinal value
 * of the Rank enum as an index to fetch the Card rank name
 */
static const std::string rankNames[] = { "Joker", "Two", "Three", "Four",
		"Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King",
		"Ace" };

/**
 * Card class to represent a single playing card
 */
class Card {
public:
	/**
	 * Suit enumerations
	 */
	enum Suit {
		Spades = 0, Hearts, Diamonds, Clubs
	};

	/**
	 * Rank enumerations ordered by value for game of war
	 */
	enum Rank {
		Joker = 0,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack,
		Queen,
		King,
		Ace
	};

	/**
	 * Constructor
	 *
	 * @param s
	 * @param r
	 */
	Card(Suit s, Rank r);

	/**
	 * Constructor. This empty constructor will create a joker card.
	 * The joker card is a special card given to the player going first.
	 */
	Card();

	/**
	 * Destructor
	 */
	virtual ~Card() {
		// empty
	}

	/**
	 * Return true if this card is a joker
	 */
	bool isJoker() const {
		return (cardRank == Joker);
	}

	/*
	 * Return Rank of the card
	 */

	int getRank() const {
		return (int)cardRank + 1;
	}

	/**
	 * Output the card to an output stream as "rank of suit", except for the joker which is just output as "Joker"
	 */
	friend std::ostream& operator <<(std::ostream&, const Card&);

	/**
	 * Compare operators. For the game of war we only care about the rank value
	 */
	friend bool operator ==(const Card &lhs, const Card &rhs);
	friend bool operator <(const Card &lhs, const Card &rhs);

private:
	Suit cardSuit;
	Rank cardRank;
};

#endif /* CARD_H_ */
