#pragma once


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>	//	for shuffle
#include <ctime>
#include <random>
#include <Windows.h>


int randomizer(int x);
//
//	FOR PART 1, THE MAINFRAME LOGIN
//




/////////////////////////////////////////////////////////////////////////////////

/// <summary>
/// PART 2: BLACK JACK
/// </summary>

struct Deck
{
	std::string court{};	//	hearts diamonds spades and clubs
	std::string face{};		//	ace, queen, jack and knight  .... 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
	int cardValue{};		//	the value of the card, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11.
	//cardValue is so we can calculate who wins the game.

	void printCard()
	{
		std::cout << face << " of " << court << " and has the value of " << cardValue; //example		" 2		   of	  spades
	}

}card;//an object for each individual card


struct Players
{
	Deck hand{};
	int balance{ 100 };
	//	Balance is set to 100 by default

} humanPlayer, house;


std::vector <Deck> cards{}; //Stores each cards from the loop 52 in total


void makeDeck(std::vector<Deck>& cards);
void shuffleDeck();
void gaming(std::vector<Deck>& cards);
void initializeGame();
void exitGame();
void handleDraw();
void handleHouseWin();
void handlePlayerWin();
void stopPlaying();
void takeCard();

void askForPlayAgain();
char playerStandOrHit{}; //if a player wants to take a card or not.

int playersMoney{};		// humanPlayer.balance and starting balance is 100
int thePot{};			// amount in the pot from humanplayers balance and houses balance	
char yesOrNo{};			//takes a character that is either y for yes, or n for no
bool nowYouCanPlay = true;
bool playAgain = false;
bool houseIsDrawingCards = false;


int housepoints{};		//house points
int playerpoints{};		//human player points
int addCard = { 1 };	//the index of the random number, also is saved in playerpoints and housepoints


bool gameover = true; //The starting game of black jack. The first while loop you will be put in.

bool whoWins_youOrTheHouse = false; //if gameover is false, whowinsyouorthehouse? = true, and will do the house's turn.
// also checks who wins for that round


//JUNK / things i didnt use
void clearCin();		//clears cin