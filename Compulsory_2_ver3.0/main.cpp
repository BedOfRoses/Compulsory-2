#include "myHeader.h"
#include <limits>
#include <iostream>
#include "Login.h"
//std::vector <Deck> shuffledCards{};

//generates the deck of cards, which is 52
void makeDeck(std::vector<Deck>& cards) {
	const std::string suits[] = { "Hearts", "Spades", "Diamonds", "Clubs" };
	const std::string faces[] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };

	for (const auto& suit : suits) {
		for (int j = 0; j < 13; j++) {
			Deck card;
			card.court = suit;
			card.face = faces[j];
			if (j == 0) {
				card.cardValue = 1; // Ace
			}
			else if (j >= 10) {
				card.cardValue = 10; // Jack, Queen, King
			}
			else {
				card.cardValue = j + 1;
			}
			cards.push_back(card);
		}
	}
}
// uses std::shuffle from the algorithm library.
void shuffleDeck()
{

	int randomNumber{};

	//Generate random seed
	srand(time(0));

	randomNumber = rand();


	for (int i = 0; i < 52; i++)
	{
		//Shuffles the cards
		std::shuffle(cards.begin(), cards.end(), std::default_random_engine(randomNumber));
	}
}

void initializeGame()
{
	bool gameover = true;
	bool whoWins_youOrTheHouse = false;

	if (humanPlayer.balance == 0) {
		std::cout << "No more money to play with fella.";
		exit(0);
	}

	if (humanPlayer.balance < 10) {
		gameover = true;
	}

	//makeDeck(); // makeDeck somewhere else
	shuffleDeck();

	std::cout << "Welcome to blackjack\n";
	std::cout << "How much do you want to bid?: ";
	std::cin >> playersMoney;

	if (playersMoney < 10) {
		std::cout << "Too low to participate, minimum is 10$\n";
		std::cout << "How much do you want to bid?????: ";
		std::cin >> playersMoney;
		if (playersMoney >= 10) {
			nowYouCanPlay = false;
		}
	}

	humanPlayer.balance -= playersMoney;
	house.balance -= playersMoney;
	thePot = playersMoney * 2;

	std::cout << "You bid: " << playersMoney << " and have " << humanPlayer.balance << "$ left.\n";
	std::cout << "The house bids: " << playersMoney << " and have " << house.balance << "$ left.\n";
	std::cout << "The winner of this game gets " << thePot << "$!!!\n";


}

void playGame() {
	std::cout << "Let's play!\n";
	std::cout << "Take a card\nT = take\nS = stop\n";

	if (playerpoints > 21) {
		std::cout << "You got over 21 points, you had " << playerpoints << std::endl;
		std::cout << "Let's see what the house gets..\n";
		gameover = false;
		whoWins_youOrTheHouse = true;
		Sleep(3000);
	}
	else {
		std::cin >> playerStandOrHit;
		switch (playerStandOrHit) {
		case 't':
		case 'T':
			takeCard();
			break;
		case 's':
		case 'S':
			stopPlaying();
			break;
		default:
			break;
		}
	}
}
void takeCard() {
	std::cout << "You drew: ";
	cards[addCard].printCard();

	if (cards[addCard].cardValue == 1) {
		std::cout << "\nYour hand is now worth " << playerpoints << std::endl;
		std::cout << "\nYou got the card ACE!!!, do you want it to be 1 or 11?\nY = yes for 11\nN = no, for 1: ";
		std::cin >> yesOrNo;
		switch (yesOrNo) {
		case 'y':
		case 'Y':
			cards[addCard].cardValue = 11;
			break;
		case 'n':
		case 'N':
			cards[addCard].cardValue = 1;
			break;
		default:
			break;
		}
	}
	playerpoints += cards[addCard].cardValue;
	std::cout << "\nYour hand is now worth " << playerpoints << std::endl;
	addCard++;
}
void stopPlaying() {
	cards[addCard].cardValue;
	gameover = false;
	whoWins_youOrTheHouse = true;
	std::cout << "Now it's the house's turn..\n";
}
void playHouseTurn() {
	for (int i = 0; housepoints <= 21 || housepoints > playerpoints; i++) {
		if (housepoints < playerpoints) {
			housepoints += cards[addCard].cardValue;
			std::cout << "House's took the card ";
			cards[addCard].printCard();
			std::cout << std::endl;
			++addCard;
			Sleep(2500);
		}

		if ((housepoints >= playerpoints) || (housepoints >= 21)) {
			break;
		}
	}

	if (housepoints == playerpoints) {
		handleDraw();
	}
	else if ((housepoints >= playerpoints && housepoints <= 21) || (playerpoints > 21)) {
		handleHouseWin();
	}
	else if ((playerpoints >= housepoints && playerpoints <= 21) || (housepoints > 21)) {
		handlePlayerWin();
	}
}

void handleDraw() {
	std::cout << "Both of you got " << playerpoints << " points and win your money back\n";
	thePot /= 2;
	humanPlayer.balance += thePot;
	house.balance += thePot;
	thePot = 0;
	Sleep(2000);
	whoWins_youOrTheHouse = false;
	playAgain = true;
	playerpoints = 0;
	housepoints = 0;
}

void handleHouseWin() {
	std::cout << "House won, house had " << housepoints << " points\n";
	std::cout << "You had " << playerpoints << " points\n";
	house.balance += thePot;
	thePot = 0;
	Sleep(2000);
	whoWins_youOrTheHouse = false;
	playAgain = true;
	playerpoints = 0;
	housepoints = 0;
}

void handlePlayerWin() {
	std::cout << "You won because your hand was " << playerpoints << " points\n";
	std::cout << "House had " << housepoints << " points\n";
	humanPlayer.balance += thePot;
	thePot = 0;
	playerpoints = 0;
	housepoints = 0;
	Sleep(2000);
	whoWins_youOrTheHouse = false;
	playAgain;
}

//This is the blackjack gaming function, uses referance of cards vector, to use their struct abilities
void gaming(std::vector<Deck>& cards)
{
	//humanPlayer.balance; //	Balance is set to 100 by default
	
	initializeGame();

	while (gameover) {
		playGame();
	}

	while (whoWins_youOrTheHouse) {
		playHouseTurn();
	}

	while (playAgain) {
		askForPlayAgain();
	}
}
void askForPlayAgain() {
	system("cls");

	if (humanPlayer.balance > 10) {
		std::cout << "\nDo you want to play again?\n";
		std::cout << "You still have " << humanPlayer.balance << "$\n";
		std::cout << "Y = yes\nN = no\n";
		std::cin >> yesOrNo;
		switch (yesOrNo) {
		case 'y':
		case 'Y':
			//restarts the game
			gaming(cards);
			break;
		case 'n':
		case 'N':
			exitGame();
			break;
		default:
			break;
		}
	}
}
void exitGame() {
	system("cls");
	Sleep(1000);
	std::cout << "It was nice having you around..\n";
	Sleep(1000);
	std::cout << "Finally someone to play against...\n";
	Sleep(2000);
	std::cout << "PROGRAM IS SHUTTING DOWN IN \n";

	//Dramatic countdown if you are done with gaming :(
	for (int i = 1; i < 4; i++) {
		std::cout << i << ".....\n ";
		Sleep(1000);
		if (i == 3) {
			exit(0);
		}
	}
}

int main()
{

	Login user;
	user.mainframe();

	std::vector<Deck> cards;
	makeDeck(cards);

	if (user.GetIsThrough() == true)
	{
		initializeGame();
	}
	

	return 0;
}

//for a position/index of the player picking a new card
int randomizer(int x)
{
	srand(time(0));

	int randomNumber{};

	x = randomNumber;

	randomNumber = rand() % 52 + 1;

	return randomNumber;

}


void clearCin()
{
	std::cin.clear();
	std::cin.ignore(32767, '\n');

}
