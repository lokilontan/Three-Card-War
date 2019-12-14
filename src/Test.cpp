//============================================================================
// Name        : Test.cpp
// Author      : Vladimir Plagov
// Version     : 1.1
// Copyright   : Your copyright notice
// Description : Just a Test class for Card and Deck classes (Lab 12)
//============================================================================

/*

#include <iostream>
#include <stdexcept>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "TerminalPlayer.h"
#include "ComputerPlayer.h"
#include "AIPlayer.h"
using namespace std;


int main() {


	//------------LAB 13----------------

	//Create a player with a given name
	TerminalPlayer human("Human");

	Card joker;

	Card c1(Card::Spades, Card::Ace);
	Card c2(Card::Hearts, Card::Four);
	Card c3(Card::Diamonds, Card::Queen);

	human.receiveCard(c1);
	human.receiveCard(c2);
	human.receiveCard(c3);



	//Check the output if a jocker passed
	cout << human.playCard(joker);			//Expected: The output - "You are going first."
											//and ask for card to chose then output(return) the card

	cout << human.playCard(c1);				//Expected: The output - "You are going second."
											//"Opponent`s card: Ace of Spades"
											//and ask for a card to chose and then return(output) it

											//The error messages also should be invoked if the
											//number of the card is wrong

											//Hand.size() decreases too
	cout << human.playCard(c1);

	cout << human.playCard(c1);


	//------------LAB 14----------------


	//Test the ComputerPlayer class
	Card joker;

	Card c1(Card::Spades, Card::Ace);
	Card c2(Card::Hearts, Card::Four);
	Card c3(Card::Diamonds, Card::Queen);

	ComputerPlayer computer("computer");

	computer.receiveCard(c1);
	computer.receiveCard(c2);
	computer.receiveCard(c3);

	try {

		cout << computer.playCard(joker);
		cout << computer.playCard(joker);
		cout << computer.playCard(joker);
		cout << computer.playCard(joker);
		}
	catch (const std::out_of_range& oor) {
	    std::cerr << oor.what() << '\n';
	  }



	//Teacher`s example #1 _ playing ACE
	AIPlayer ai2("AIPlayer");

	ai2.receiveCard(Card(Card::Spades, Card::Ace));

	Card c2(Card::Spades,Card::Ace);

	cout << "Test 1: " << ai2.beatP(c2) << endl; //Test 1: Expected: 94.1176;
	cout << "Test 2: " << ai2.pushP(c2) << endl; //Test 2: Expected: 5.88235;
	cout << "Test 3: " << ai2.loseP(c2) << endl; //Test 3: Expected: 4.18068e-16 - close to 0;


	//Teacher`s example #3 - playing TEN
	AIPlayer ai("AIPlayer");

	ai.receiveCard(Card(Card::Spades,Card::Ten));
	ai.receiveCard(Card(Card::Spades,Card::Ten));
	ai.receiveCard(Card(Card::Spades,Card::Jack));

	Card c(Card::Spades,Card::Ten);

	cout << "Test 4: " << ai.beatP(c) << endl; 	//Test 4: Expected: 65.3061";

	cout << "Test 5: " << ai.pushP(c) << endl;	//Test 5: Expected: 4.08163;

	cout << "Test 6: " << ai.loseP(c) << endl; 	//Test 6: Expected: 30.6122;

	//Teacher`s example #4 - playing JACK
	Card c3(Card::Spades,Card::Jack);

	cout << "Test 7: " << ai.beatP(c3) << endl; //Test 7: Expected: 69.3878";

	cout << "Test 8: " << ai.pushP(c3) << endl;	//Test 8: Expected: 6.12245;

	cout << "Test 9: " << ai.loseP(c3) << endl; //Test 9: Expected: 24.4898;

	//Testing of the playCard method
	AIPlayer aip("RealAI");

	Card joker;

	aip.receiveCard(Card(Card::Spades,Card::Three));
	aip.receiveCard(Card(Card::Spades,Card::Ten));
	aip.receiveCard(Card(Card::Spades,Card::Jack));

	cout << "Test 10: " << aip.playCard(joker) << endl;	//Test 10: Expected: Jack of Spades;
														//Probability stuff turns on

	aip.receiveCard(Card(Card::Spades,Card::Jack));		//Push the card back

	cout << "Test 11: " << aip.playCard(c3) << endl;	//Test 11: Expected: Jack of Spades;
														//Even though we have smaller cards,
														//AI prefers to get at lest a point

	cout << "Test 12: " << aip.playCard(c3) << endl;	//Test 12: Expected: Three of Spades;
														//Now it is good to choose the lowest
														//card to save the highest ones
	aip.receiveCard(Card(Card::Spades,Card::Four));
	aip.receiveCard(Card(Card::Spades,Card::Ace));

	Card c4(Card::Spades,Card::Two);

	cout << "Test 13: " << aip.playCard(c4) << endl;	//Test 13: Expected: Four of Spades;
														//Returns the smallest beating card


}


*/
