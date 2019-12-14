//============================================================================
// Name        : ThreeWarGame.cpp
// Author      : Vladimir Plagov
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Game Loop
//============================================================================


#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <stdexcept>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "TerminalPlayer.h"
#include "ComputerPlayer.h"
#include "AIPlayer.h"
using namespace std;

int main() {
	cout << "------------------------------------------Three WAR Game------------------------------------------" << endl;

	short roundN = 0;
	string answer = "y";
	Card joker;										//Create the temp Cards
	Card player1Card;
	Card player2Card;

	string name;									//Create the players

	cout << "Enter your name: "; cin >> name;
	TerminalPlayer player1(name);

	cout << "Choose a name for the computer player: "; cin >> name; cout << endl;
	AIPlayer player2(name);

	while ((answer == "yes") || (answer == "Yes") || (answer == "y")) {


		answer = "n";
		Deck deck;										//Create the deck and shuffle it
		deck.shuffle();

		srand(time(NULL));								//Determine who goes first
		int whoFirst = rand() % 2;

		for (int i = 0; i < 3; ++i ) {					//Deal three cards to each player
			player1.receiveCard(deck.draw());
			player2.receiveCard(deck.draw());
		}

		player1.resetScore();							//Reset the scores for both players in case of new game is required
		player2.resetScore();
		roundN = 1;										//Reset round counter

		while (player1.hasCards() || player2.hasCards()) {		//Play while players have cards...
																//There is no need to compare both of the players
			cout << endl << "-----------------------------------------------ROUND " << roundN <<"--------------------------------------------" << endl;
			cout << endl << "-----------------------------------------------SCORES---------------------------------------------" << endl;
			cout << "                                       " << player1 << ": " << player1.getScore() << " | "
					<< player2 << ": " << player2.getScore() <<endl;

			if (whoFirst == 0) {
				player1Card = player1.playCard(joker);			//Player1 goes first if whoFirst = 0
				player2Card = player2.playCard(player1Card);	//Player2 gets his opponent`s card
				player1.playedCards(player1Card, player2Card);	//Show the cards to the player1
				player2.playedCards(player1Card, player2Card);	//Show the cards to the player2

				cout << endl << "                 " << player1 << ": " << player1Card << "	|	" << player2 << ": " << player2Card << endl << endl;
			}
			else {
				player2Card = player2.playCard(joker);			//Player2 goes first if whoFirst = 1
				player1Card = player1.playCard(player2Card);	//Player1 gets his opponent`s card
				player1.playedCards(player1Card, player2Card);	//Show the cards to the player1
				player2.playedCards(player1Card, player2Card);	//Show the cards to the player2

				cout << endl << "                 " << player2 << ": " << player2Card << "	|	" << player1 << ": " << player1Card << endl << endl;
			}

			if (player1Card < player2Card) {					//If player2 wins, he gets 2 points and goes first next round
				player2.addScore(2);
				whoFirst = 1;
				cout << "                                       " << player2 << " wins!" << endl;
			}
			else
				if ( player1Card == player2Card ) {				//If draw, then both players get points and no update on who goes first next round
					player1.addScore(1);
					player2.addScore(1);
					cout  << "                                             "<< " Draw!" << endl;
				}
				else {
					player1.addScore(2);						//If player1 wins, he gets 2 points and goes first next round
					whoFirst = 0;
					cout << "                                       " << player1 << " wins!" << endl;
				}

			if (!deck.isEmpty()) {								//If deck is not empty, every person gets a card
				player1.receiveCard(deck.draw());
				player2.receiveCard(deck.draw());
			}

			++roundN;

		}
		if (player1.getScore() < player2.getScore()) {
						cout << endl << "--------------------------------------------" << player2 << " WON!------------------------------------------" << endl;
		} else
			if  (player1.getScore() == player2.getScore()) {
				cout << endl << "-----------------------------------------------DRAW!---------------------------------------------" << endl;
			} else {cout << endl << "--------------------------------------------" << player1 << " WON!------------------------------------------" << endl;}
		cout << endl << "Do you want to play again?(y/n): "; cin >> answer;

	}

	cout << endl << "Thanks for the game!";


}

