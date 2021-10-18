#include "myHeader.h"
//std::vector <Deck> shuffledCards{};

//generates the deck of cards, which is 52
void makeDeck()
{
	//This makes clubs, hearts, spades and diamond
	
	// Also converts the faces from integers to strings
	// so you can see the face of the cards
	for (int i = 1; i < 5; i++) // 1, 2, 3 , 4
	{
		if (i == 1)
		{
			card.court = 3; //"Hearts";
		}

		if (i == 2)
		{
			card.court = 4; //"Spades";
		}

		if (i == 3)
		{
			card.court = 5; // "Diamonds";
		}

		if (i == 4)
		{
			card.court = 6; // "Clubs";
		}
		// makes Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, knight, queen and king.
		for (int j = 1; j < 14; j++)
		{
			/*
			std::string court{}; // hearts diamonds spades and clubs
			std::string face{};  // ace, queen, jack and knight
			int cardValue{};	 // the value of a card
			*/

			if (j == 1)
			{
				card.court = i;
				card.face = "Ace";
				card.cardValue = 1; //1 || 11;
			}

			if (j == 2)
			{
				card.court = i;
				card.cardValue = 2;
				card.face = std::to_string(j);
			}

			if (j == 3)
			{
				card.court = i;
				card.cardValue = 3;
				card.face = std::to_string(j);
			}

			if (j == 4)
			{
				card.court = i;
				card.cardValue = 4;
				card.face = std::to_string(j);
			}

			if (j == 5)
			{
				card.court = i;
				card.cardValue = 5;
				card.face = std::to_string(j);
			}

			if (j == 6)
			{
				card.court = i;
				card.cardValue = 6;
				card.face = std::to_string(j);
			}

			if (j == 7)
			{
				card.court = i;
				card.cardValue = 7;
				card.face = std::to_string(j);
			}

			if (j == 8)
			{
				card.court = i;
				card.cardValue = 8;
				card.face = std::to_string(j);
			}

			if (j == 9)
			{
				card.court = i;
				card.cardValue = 9;
				card.face = std::to_string(j);
			}

			if (j == 10)
			{
				card.court = i;
				card.cardValue = 10;
				card.face = std::to_string(j);
			}


			if (j == 11)
			{
				card.court = i;
				card.face = "Jack";
				card.cardValue = 10;

				//example
				//Jack of hearts has the value of 10
			}

			if (j == 12)
			{
				card.court = i;
				card.face = "Queen";
				card.cardValue = 10;
			}

			if (j == 13)
			{
				card.court = i;
				card.face = "King";
				card.cardValue = 10;
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

//This is the blackjack gaming function, uses referance of cards vector, to use their struct abilities
void gaming(std::vector<Deck>& cards)
{
	//humanPlayer.balance; //	Balance is set to 100 by default
	
	//The starting game
	bool gameover = true;

	//if gameover is false, whowinsyouorthehouse? = true, and will do the house's turn.
	bool whoWins_youOrTheHouse = false; 

	if (humanPlayer.balance == 0)
	{
		system("cls");
		std::cout << "No more money to play with fella.";
		exit(0);
	}
	if (humanPlayer.balance < 10)
	{
		gameover = true;
	}

	//Create the cards
	makeDeck();
	// and shuffle it
	shuffleDeck();


	system("cls");
	std::cout << "Welcome to black jack\n";
	std::cout << "How much do you want to bid?: ";
	std::cin >> playersMoney;

	//To participate you need to atleast put in 10$
	if (playersMoney < 10)
	{
		system("cls");
		std::cout << "Too low to participate, minimum is 10$\n";
		std::cout << "How much do you want to bid?????: ";
		std::cin >> playersMoney;
		if (playersMoney >= 10)
		{
			nowYouCanPlay = false;
		}

	}

	



	//the humans money total balance - price to play
	humanPlayer.balance = humanPlayer.balance - playersMoney;

	// the house bets the same as the human.
	house.balance = house.balance - playersMoney;
	thePot = playersMoney * 2; // times 2 because the player and the house bids the same

	system("cls");
	std::cout << "You bid: " << playersMoney << " and have " << humanPlayer.balance << "$ left.\n";
	std::cout << "The house bids: " << playersMoney << " and have " << house.balance << "$ left. \n";

	std::cout << "The winner of this game gets " << thePot << "$!!!\n";

	while (gameover) {

		std::cout << "Let's play! \n";
		std::cout << "Take a card\nT = take\nS = stop\n";


		if (playerpoints > 21)
		{
			system("cls");
			std::cout << "You got over 21 points, you had " << playerpoints << std::endl;
			std::cout << "Lets see what the house gets..\n";
			gameover = false;
			whoWins_youOrTheHouse = true;
			Sleep(3000);
		}

		else {
			std::cin >> playerStandOrHit;
			switch (playerStandOrHit)
			{
			case 't': case 'T':
				system("cls");

				std::cout << "You drew: ";
				cards[addCard].printCard();

				// Lets player choose if ACE is worth 1 or 11.
				if (cards[addCard].cardValue == 1)
				{
					std::cout << "\nYour hand is now worth " << playerpoints << std::endl;
					std::cout << "\n You got the card ACE!!!, do you want it to be 1 or 11?\nY = yes for 11\n N = no, for 1 :";
					std::cin >> yesOrNo;
					switch (yesOrNo)
					{
					case 'y': case 'Y':
						cards[addCard].cardValue = 11;
						break;
					case 'n': case 'N':
						cards[addCard].cardValue = 1;
						break;
					default:
						break;
					}
				}
				playerpoints += cards[addCard].cardValue;

				std::cout << "\nYour hand is now worth " << playerpoints << std::endl;
				addCard++;
				break;

			case 's': case 'S':
				cards[addCard].cardValue;
				gameover = false;
				whoWins_youOrTheHouse = true;
				std::cout << "Now its the house's turn..\n";
				break;

			default:
				break;
			}
		}
	}




	//This runs the house player or ai you might call it.
	while (whoWins_youOrTheHouse)
	{

		//Lets the house play aswell.
		for (int i = 0; housepoints <= 21 || housepoints > playerpoints; i++)
		{
			//If the house gets 21 points, we break out of the loop and check it against the humanplayer

			if (housepoints < playerpoints)
			{
				housepoints += cards[addCard].cardValue;

				std::cout << "House's took the card "; cards[addCard].printCard();
				std::cout << std::endl;
				//Draws a new card for the house

				++addCard;
				Sleep(2500);
			}

			//Kristian helped me with this, was a bug, kristian++
			if ((housepoints >= playerpoints) || (housepoints >= 21))
			{
				break;
			}

		}

		// This is for a draw
		if (housepoints == playerpoints)
		{
			std::cout << "Both of you got " << playerpoints << " points and win ur money back";

			thePot = thePot / 2; //splits the money

			//Gives back the money from the splitted pot to each player.
			humanPlayer.balance += thePot;
			house.balance += thePot;

			thePot = 0; // resets the pot to 0

			Sleep(2000);
			whoWins_youOrTheHouse = false;
			playAgain = true;
			playerpoints = 0;
			housepoints = 0;

		}



		//House wins over player, because player busts
		else if ((housepoints >= playerpoints && housepoints <= 21) || (playerpoints > 21)) //< playerpoints)
		{
			system("cls");
			std::cout << "House won, house had " << housepoints << " points" << std::endl;
			std::cout << "You had " << playerpoints << " points" << std::endl;

			house.balance += thePot; //House gets the money
			thePot = 0; //resetting the pot

			Sleep(2000);
			whoWins_youOrTheHouse = false;
			playAgain = true;
			playerpoints = 0;
			housepoints = 0;

		}

		//Player Wins over house, because house busts
		else if ((playerpoints >= housepoints && playerpoints <= 21) || (housepoints > 21))
		{
			system("cls");
			std::cout << "You won because your hand was" << playerpoints << " points" << std::endl;
			std::cout << "House had " << housepoints << " points" << std::endl;

			humanPlayer.balance += thePot; //player gets the money
			thePot = 0; //resetting the pot
			playerpoints = 0;
			housepoints = 0;
			Sleep(2000);
			whoWins_youOrTheHouse = false;
			playAgain = true;


		}

	}


	while (playAgain)
	{
		system("cls");

		if (humanPlayer.balance > 10)
		{
			std::cout << "\nDo you want to play again?\n";
			std::cout << "You still have " << humanPlayer.balance << "$\n";
			std::cout << "Y = yes\nN = no\n";
			std::cin >> yesOrNo;
			switch (yesOrNo)
			{
			case 'y': case 'Y':
				//restarts the game
				gaming(cards);
				break;
			case 'n': case 'N':
				system("cls");
				Sleep(1000);
				std::cout << "It was nice having you around..\n";
				Sleep(1000);
				std::cout << "Finally someone to play against...\n";
				Sleep(2000);
				std::cout << "PROGRAM IS SHUTTING DOWN IN \n";

				//Dramatic countdown if you are done with gaming :(
				for (int i = 1; i < 4; i++)
				{
					std::cout << i << ".....\n ";
					Sleep(1000);
					if (i == 3)
					{
						exit(0);
					}
				}
				break;
			default:
				break;
			}
		}


	}

}



int main()
{

	//gaming(cards);
	mainframe();

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

void mainframe()
{
	//Asks user for username to login

	while (userNameCorrect)
	{
		//User inputs the USERNAME
		std::cout << "You have " << 3 - loginCounter << " attempts";
		std::cout << "Please enter username: ";
		std::getline(std::cin, userName_input);

		if (userName_input == userName)
		{
			//loginCounter = 0;
			std::cout << "Correct";
			userNameCorrect = false;

		}
		else if (userName_input != userName)
		{
			++loginCounter;
		}
		//Conditions player that if he tries 3 times he loses
		if (loginCounter == 3)
		{
			std::cout << "Too many tries young one";
			exit(0);
		}
	}

	//	Asks user for password to login
	loginMainFrame();
}


void loginMainFrame()
{
	system("cls");

	passwordCorrect = true;

	while (passwordCorrect)
	{

		//Conditions player that if he tries 3 times he loses

		//User inputs the USERNAME
		std::cout << "You have " << 3 - passwordLoginCounter << " attempts" << std::endl;
		std::cout << "Please enter password: ";
		std::getline(std::cin, userPassword_input);

		if (userPassword_input == password)
		{
			std::cout << "Correct";
			passwordCorrect = false;
		}
		else if (userPassword_input != password)
		{
			++passwordLoginCounter;
		}

		if (passwordLoginCounter == 3)
		{
			std::cout << "Too many tries young one";
			exit(0);
		}
	}
	//IF PASSWORD IS CORRECT YOU GET TIME FOR GAMING :)))
	gaming(cards);
}


void clearCin()
{
	std::cin.clear();
	std::cin.ignore(32767, '\n');

}
void mainframe();