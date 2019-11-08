#include "stdafx.h"
#include "Game.h"
#include "Card.h"
#include "Player.h"
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

CPlayer::CPlayer(string name, int health): mName(name), mHealth(health)
{
}

CPlayer::~CPlayer()
{
}

// Remove all cards from the players deck, hand and table
void CPlayer::ClearCards()
{
	for (int i = 0; i < mDeck.size(); i++) // Go through all cards in deck
	{
		delete mDeck[i];				   // Deallocate memory
	}

	mDeck.clear();						   // Clear cards from deck

	for (int i = 0; i < mHand.size(); i++)
	{
		delete mHand[i];
	}

	mHand.clear();

	for (int i = 0; i < mTable.size(); i++)
	{
		delete mTable[i];
	}

	mTable.clear();
}

// Shuffle the players deck of cards
void CPlayer::ShuffleDeck()
{
	for (int i = mDeck.size() - 1; i > 0; i--) // Go through the deck
	{
		int j = Random(i);					   // Random number between 0 and the last unshuffled card
		swap(mDeck[j], mDeck[i]);			   // Swap the chosen random card with the last unshuffled card
	}
}

// If the player has a Wall minion on the table
bool CPlayer::HasWall()
{
	if (mWallCount > 0) // If the player has Wall minions on the table
	{
		return true;
	}
	else
	{
		return false;
	}
}

string CPlayer::GetName()
{
	return mName;
}

int CPlayer::GetHealth()
{
	return mHealth;
}

// Get the minions health using the passed in target number
int CPlayer::GetMinionHealth(int target)
{
	return mTable[target]->GetHealth();
}

int CPlayer::HordeCount()
{
	return mHordeCount;
}

// Return the position of the Wall minion in the players table
int CPlayer::FindWall()
{
	for (int i = 0; i < mTable.size(); i++)
	{
		if (mTable[i]->GetType() == 6)	   // if the card is a wall
		{
			return i;					   // Return its position
		}
	}
	return NULL;
}

// Increase the attack of the minion at target location by the passed amount
void CPlayer::MinionIncreaseAttack(int amount, int target)
{
	cout << mTable[target]->GetName() << ". ";
	mTable[target]->IncreaseAttack(amount);
	cout << mTable[target]->GetName() << " attack is now " << mTable[target]->GetAttack() << endl;
}

// Increase the armour of the minion at target location by the passed amount
void CPlayer::MinionIncreaseArmour(int amount, int target)
{
	cout << mTable[target]->GetName() << ". ";
	mTable[target]->IncreaseArmour(amount);
	cout << mTable[target]->GetName() << " armour is now " << mTable[target]->GetArmour() << endl;
}

// Increase the health of the minion at target location by the passed amount
void CPlayer::MinionTakeHeal(int amount, int target)
{
	cout << mTable[target]->GetName() << ". ";
	mTable[target]->TakeHeal(amount);
	cout << mTable[target]->GetName() << " health is now " << mTable[target]->GetHealth() << endl;
}

// Heal the player by the amount
void CPlayer::PlayerTakeHeal(int amount)
{
	cout << mName << ". ";
	mHealth += amount;
	cout << mName << " health is now " << mHealth << endl;
}

// Damage the target minion by the given amount and output its remaining health or if it died
void CPlayer::MinionTakeDamage(int amount, int target)
{
	cout << mTable[target]->GetName() << ". ";

	mTable[target]->TakeDamage(amount);                          // Damage the minion

	if (mTable[target]->GetHealth() <= 0)                        // If the minion is dead
	{
		cout << mTable[target]->GetName() << " killed." << endl;

		if (mTable[target]->GetType() == 6)                      // If the card is a Wall
		{
			mWallCount--;									     // Player has no Wall
		}
		else if (mTable[target]->GetType() == 7)				 // If the card is a horde
		{
			mHordeCount--;										 // Reduce Horde count
		}
		delete mTable[target];									 // Deallocate memory
		mTable.erase(mTable.begin() + target);				     // Remove from table
	}
	else
	{
		cout << mTable[target]->GetName() << " health is now " << mTable[target]->GetHealth() << endl;
	}
}

// Deal damage to the player
void CPlayer::PlayerTakeDamage(int amount)
{
	cout << mName << ". ";
	mHealth -= amount;

	if (mHealth <= 0)										    // Player dead
	{
		cout << mName << " killed." << endl;
	}
	else
	{
		cout << mName << " health is now " << mHealth << endl; 
	}
}

int CPlayer::DeckCount()
{
	return mDeck.size();
}

int CPlayer::HandCount()
{
	return mHand.size();
}

int CPlayer::TableCount()
{
	return mTable.size();
}

// Activate all player minions on table if the enemy is alive
void CPlayer::ActivateMinions(CPlayer* friendly, CPlayer* enemy)
{
	if (TableCount() > 0 && enemy->GetHealth() > 0) // If the player has minions and the enemy is alive
	{
		for (int i = 0; i < TableCount(); i++)
		{
			if (enemy->GetHealth() > 0)				// If the enemy is alive
			{
				mTable[i]->Action(friendly, enemy); // Activate minion
			}
		}
	}
}

// Play a turn by drawing a card from the deck and choosing a random card in the hand to play
void CPlayer::PlayTurn(CPlayer* friendly, CPlayer* enemy)
{
	DrawCard();							   // Draw card from deck
	int chosenCard = Random(1);			   // Choose random card from hand
	PlayCard(chosenCard, friendly, enemy); // Play chosen card
}

int CPlayer::Random(const float n)
{
	return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * (n + 1));
}

// Play the chosen card
// If the card is a minion play it to the table
// Else activate the card
// Display cards on the table
void CPlayer::PlayCard(int chosenCard, CPlayer* friendly, CPlayer* enemy)
{
	cout << mName << " plays " << mHand[chosenCard]->GetName() << endl;

	if (mHand[chosenCard]->isMinion())				// If the chosen card is a minion
	{
		if (mHand[chosenCard]->GetType() == 6)		// If the chosen card is a Wall
		{
			mWallCount++;                           // The player has a Wall
		}
		else if (mHand[chosenCard]->GetType() == 7) // If the chosen card is a Horde
		{
			mHordeCount++;							// Increase Horde count
		}

		mTable.push_back(mHand[chosenCard]);		// Add card to the table
		mHand.erase(mHand.begin() + chosenCard);	// Remove card from the hand
	}
	else
	{
		mHand[chosenCard]->Action(friendly, enemy); // Activate card
		delete mHand[chosenCard];					// Deallocate memory
		mHand.erase(mHand.begin() + chosenCard);    // Remove card from the hand
	}

	cout << "Cards on table: ";
	for (int i = 0; i < mTable.size(); i++)			// Display cards on table
	{
		cout << mTable[i]->GetName() << "(" << mTable[i]->GetHealth() << ") ";
	}
	cout << endl;
}

// Draw card from deck into hand
// Remove card from deck
void CPlayer::DrawCard()
{
	mHand.push_back(mDeck[0]);           // Add card to hand
	cout << mDeck[0]->GetName() << endl;
	mDeck.erase(mDeck.begin());			 // Remove card from deck
}

// Get the cards from the file and add them to the players deck
// Use the cards type to create the correct card and get its values
void CPlayer::GetDeck()
{
	int cardType = 0;						// Type of card
	string cardName = "";					// Name of card
	int cardAttack = 0;						// Attack value of card
	int cardHealth = 0;						// Health value of card
	int cardHeal = 0;						// Amount the card can heal
	int cardAttackInc = 0;					// Attack Increment of the card
	int cardProtection = 0;					// Protection value of the card
	CCard* pCard = nullptr;					// The card
	ifstream file(mName + FILE_EXTENTION);  // The deck file using the player name and .txt extension

	while (file >> cardType >> cardName)	// Get the card type and name and use that to create a card of the right type
	{
		switch (cardType)
		{
		case 1:
			file >> cardAttack >> cardHealth;								 // Get values for card type
			pCard = new CMinion(cardType, cardName, cardAttack, cardHealth); // Create the card with values
			break;
		case 2:
			file >> cardAttack;
			pCard = new CFireball(cardType, cardName, cardAttack);
			break;
		case 3:
			file >> cardAttack;
			pCard = new CLightning(cardType, cardName, cardAttack);
			break;
		case 4:
			file >> cardAttack >> cardHeal;
			pCard = new CBless(cardType, cardName, cardAttack, cardHeal);
			break;
		case 5:
			file >> cardAttack >> cardHealth >> cardHeal;
			pCard = new CVampire(cardType, cardName, cardAttack, cardHealth, cardHeal);
			break;
		case 6:
			file >> cardAttack >> cardHealth;
			pCard = new CWall(cardType, cardName, cardAttack, cardHealth);
			break;
		case 7:
			file >> cardAttack >> cardHealth;
			pCard = new CHorde(cardType, cardName, cardAttack, cardHealth);
			break;
		case 8:
			file >> cardAttack >> cardHealth;
			pCard = new CTrample(cardType, cardName, cardAttack, cardHealth);
			break;
		case 9:
			file >> cardAttack >> cardHealth;
			pCard = new CLeech(cardType, cardName, cardAttack, cardHealth);
			break;
		case 10:
			file >> cardAttackInc;
			pCard = new CSword(cardType, cardName, cardAttackInc);
			break;
		case 11:
			file >> cardProtection;
			pCard = new CArmour(cardType, cardName, cardProtection);
			break;
		}
		mDeck.push_back(pCard); // Add the card to the deck
	}
}
