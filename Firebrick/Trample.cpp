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

CTrample::CTrample(int type, string name, int attack, int health):
	CMinion(type, name, attack, health)
{
}

CTrample::~CTrample()
{
}

// Action when Trample card is activated
// If the enemy player has minions, chooose one at random and attack it
// If the minions health was less than the Trample minions attack, use the remainding attack value to attack another minion
// Keep attacking minions until there is no remainder
// Else attack the enemy player
void CTrample::Action(CPlayer* friendly, CPlayer* enemy)
{
	int originalAttack = mAttack;								    // Save original attack value of minion

	if (enemy->TableCount() > 0) 									// If the player has minion
	{
		int target;

		while (mAttack > 0 && enemy->GetHealth() > 0)				// Keep attacking minions if the enemy is alive
		{														    // - and there is a remainder
			cout << mName << " attacks ";

			if (enemy->TableCount() > 0)							// If the enemy has minions
			{
				if (enemy->HasWall())								// If the enemy has a Wall minion
				{
					target = enemy->FindWall();						// Target the Wall minion
				}
				else
				{
					target = enemy->Random(enemy->TableCount()-1);  // Choose a random minion
				}
				int minionHealth = enemy->GetMinionHealth(target);  // Get the targets health
				enemy->MinionTakeDamage(mAttack, target);			// Attack the target
				mAttack -= minionHealth;							// Get remainder attack
			}
			else
			{
				int playerHealth = enemy->GetHealth();
				enemy->PlayerTakeDamage(mAttack);
				mAttack -= playerHealth;
			}
		}
	}
	else
	{
		cout << mName << " attacks ";
		enemy->PlayerTakeDamage(mAttack);							// Attack the enemy player
	}

	mAttack = originalAttack;										// Reset the minions attack
}
