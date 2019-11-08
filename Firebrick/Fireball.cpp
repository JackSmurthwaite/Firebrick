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

CFireball::CFireball(int type, string name, int attack): CSpell(type, name, attack)
{
}

CFireball::~CFireball()
{
}

// Action when Fireball card is played
// Choose one of the enemy minions or the enemy player to attack
// Friendly and enemy player are passed in
void CFireball::Action(CPlayer* friendly, CPlayer* enemy)
{
	cout << mName << " attacks ";

	if (enemy->TableCount() > 0)								// If the enemy player has minions
	{
		int target = 0;											// Target to attack

		target = enemy->Random(1);								// Choose the enemy player or minions

		if (target == 0)
		{
			enemy->PlayerTakeDamage(mAttack);					// Attack enemy player
		}
		else
		{
			target = enemy->Random(enemy->TableCount() - 1);	// Choose random minion
			enemy->MinionTakeDamage(mAttack, target);			// Attack minion
		}
	}
	else
	{
		enemy->PlayerTakeDamage(mAttack);						// Attack enemy player
	}
	
}
