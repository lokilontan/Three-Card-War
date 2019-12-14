/*
 * Deck.cpp
 *
 *  Created on: Nov 24, 2019
 *      Author: student
 */

#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include "Deck.h"
#include "Card.h"

using namespace std;

Deck::Deck(){
	for (int i = Card::Spades; i <= Card::Clubs; i++)
		for (int j = Card::Two; j <= Card::Ace; j++)
			cardDeck.push_back(Card (static_cast<Card::Suit>(i), static_cast<Card::Rank>(j)));

	nextCard = 0;
}

/**
 * Shuffle the deck and reset the next available card to the beginning of the deck
 */
void Deck::shuffle() {
	  // obtain a time-based seed:
	  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	  std::shuffle (cardDeck.begin(), cardDeck.end(), default_random_engine(seed));
}

/**
 * Return true if the deck is empty (next available card is past the end of the deck)
 */
bool Deck::isEmpty() const{
	return (nextCard>=MaxCards);
}

/**
 * Draw a card from the deck. If someone attempts to draw a card when the deck is
 * empty then throw an out-of-range exception.
 */
const Card Deck::draw() {
	if (isEmpty()) throw std::out_of_range("The deck is empty!");
	unsigned tempNextCard = nextCard;
	nextCard++;
	return (cardDeck[tempNextCard]);
}

//Overloaded << operator implemented for TESTING
std::ostream& operator <<(std::ostream& os, const Deck& d) {
	cout << "Deck size: " << MaxCards - d.nextCard<< endl;
	for (unsigned int i = d.nextCard; i<d.cardDeck.size(); i++) {
		os<<d.cardDeck[i];
	}
	return os;
}


