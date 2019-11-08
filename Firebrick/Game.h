#pragma once
#include <vector>
#include "Player.h"
using namespace std;

class CGame
{
private:
	vector<CPlayer> mPlayers;             // Players of the game
	void GetDecks();
	void PlayersDrawCard();
	int mRound = 1;						  // Round number
	bool mGameOver = false;				  // If the game is over
public:
	const int MAX_ROUNDS = 30;		      // Max number of rounds before the game ends
	const int PLAYER_HEALTH = 30;		  // Starting health of the players
	const string WIZARD = "Wizard";		  // Name of the Wizard player
	const string SORCERESS = "Sorceress"; // Name of the Sorceress player
	CGame();
	~CGame();
	int Random(const float n);
	void AddPlayers(string player1Name, string player2Name);
	void Play();
	void Shuffle();
	void SeedRandom();
};

