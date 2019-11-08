#pragma once
#include "Card.h"
#include <string>
#include <vector>
using namespace std;

class CPlayer
{
private:
	const string FILE_EXTENTION = ".txt"; // File extention of the text files for decks and seeds
	string mName;						  // Name of the player
	int mHealth;						  // Current health of the player
	vector<CCard*> mDeck;				  // Deck of cards
	vector<CCard*> mHand;				  // Hand of cards
	vector<CCard*> mTable;				  // Table of cards
	int mWallCount = 0;					  // How many Wall cards the player has on the table
	int mHordeCount = 0;				  // How many Horde cards the player has on the table
public:
	CPlayer(string name, int health);
	~CPlayer();
	void GetDeck();
	void DrawCard();
	int GetHealth();
	string GetName();
	void PlayCard(int chosenCard, CPlayer* friendly, CPlayer* enemy);
	void PlayTurn(CPlayer* friendly, CPlayer* enemy);
	void ActivateMinions(CPlayer* friendly, CPlayer* enemy);
	int Random(const float n);
	int DeckCount();
	int HandCount();
	int TableCount();
	void MinionTakeDamage(int amount, int target);
	void PlayerTakeDamage(int amount);
	void MinionTakeHeal(int amount, int target);
	void MinionIncreaseAttack(int amount, int target);
	void MinionIncreaseArmour(int amount, int target);
	void PlayerTakeHeal(int amount);
	int FindWall();
	int HordeCount();
	int GetMinionHealth(int target);
	void ClearCards();
	void ShuffleDeck();
	bool HasWall();
};

