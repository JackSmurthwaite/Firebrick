#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "Card.h"
#include "Sword.h"
#include "Armour.h"
#include "Spell.h"
#include "Bless.h"
#include "Fireball.h"
#include "Lightning.h"
#include "Minion.h"
#include "Horde.h"
#include "Leech.h"
#include "Trample.h"
#include "Vampire.h"
#include "Wall.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

CGame::CGame()
{
}

CGame::~CGame()
{
}

// Get the seed value to seed the random function
void CGame::SeedRandom()
{
	ifstream seedFile("Seed.txt");			 // Seed file
	int seed = 0;							 // Seed value

	seedFile >> seed;					     // Get seed value
	seedFile.close();						 // Close seed file

	srand(static_cast<unsigned int> (seed)); // Seed random function
}

// Ask the user if they want to shuffle the players decks
// If the user says yes, both players decks are shuffled
void CGame::Shuffle()
{
	cout << "Do you want to shuffle the decks? (yes/no)" << endl;
	string answer;												 // Users answer
	cin >> answer;												 // Get users answer

	if (answer == "yes")										 // If the user answers yes
	{
		mPlayers[0].ShuffleDeck();								 // Shuffle players deck
		mPlayers[1].ShuffleDeck();
	}
}

// Random function which returns a random number between 0 and the passed in value
int CGame::Random(const float n)
{
	return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * (n + 1));
}

// Adds the two players to the game
// Names of the players are passed in
void CGame::AddPlayers(string player1Name, string player2Name)
{
	CPlayer player1(player1Name, PLAYER_HEALTH); // Players being created with their name and health
	CPlayer player2(player2Name, PLAYER_HEALTH);

	mPlayers.push_back(player1);				 // Players added to the game
	mPlayers.push_back(player2);

	GetDecks();								     // Getting the players decks of cards
}

// Getting the players decks of cards
void CGame::GetDecks()
{
	mPlayers[0].GetDeck();
	mPlayers[1].GetDeck();
}

// Drawing the players cards from their decks
void CGame::PlayersDrawCard()
{
	cout << mPlayers[0].GetName() << " begins with ";
	mPlayers[0].DrawCard();

	cout << mPlayers[1].GetName() << " begins with ";
	mPlayers[1].DrawCard();
}

// Players draw a card from their deck at the start of the game
// A max of 30 rounds of the game are played unless one of the players dies
// Each round the players draw a card from their deck into their hand, and play a card to the table
// At the end of the players turn, their minions are activated and their actions are performed
// When the game ends, the cards are discarded to stop memory leaks
void CGame::Play()
{
	PlayersDrawCard();											      // Players draw a card from deck
	cout << endl;

	while (!mGameOver && mRound <= 30)								  // Play 30 rounds unless a player dies
	{
		cout << "Round " << mRound << endl;

		cout << mPlayers[0].GetName() << " draws ";					  
		mPlayers[0].PlayTurn(&mPlayers[0], &mPlayers[1]);			  // Players plays their turn
		mPlayers[0].ActivateMinions(&mPlayers[0], &mPlayers[1]);	  // Players minions are activated
		cout << endl;

		if (mPlayers[1].GetHealth() < 1)							  // If the other player dies
		{
			mGameOver = true;										  // Game Over
		}
		else
		{
			cout << mPlayers[1].GetName() << " draws ";
			mPlayers[1].PlayTurn(&mPlayers[1], &mPlayers[0]);
			mPlayers[1].ActivateMinions(&mPlayers[1], &mPlayers[0]);
			cout << endl;

			if (mPlayers[0].GetHealth() < 1)
			{
				mGameOver = true;
			}
		}

		mRound++;													  // Next round			
	}

	cout << "Game Over" << endl;

	mPlayers[0].ClearCards();										  // Discard cards to stop leaks
	mPlayers[1].ClearCards();

	system("Pause");
}
