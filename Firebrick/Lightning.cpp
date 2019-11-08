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

CLightning::CLightning(int type, string name, int attack): CSpell(type, name, attack)
{
}

CLightning::~CLightning()
{
}

// Action when Lightning card is played
// Attack the enemy player and all their minions
// Friendly and enemy player are passed in
void CLightning::Action(CPlayer* friendly, CPlayer* enemy)
{
	int startMinionCount = 0;

	cout << mName << " attacks ";
	enemy->PlayerTakeDamage(mAttack);				  // Attack the enemy player

	if (enemy->GetHealth() > 0)						  // If the enemy player is alive
	{
		for (int i = 0; i < enemy->TableCount(); i++) // Go through all the enemy minions
		{
			startMinionCount = enemy->TableCount();
			cout << mName << " attacks ";
			enemy->MinionTakeDamage(mAttack, i);	  // Attack the minion

			if (enemy->TableCount() < startMinionCount)
			{
				i--;
			}
		}
	}
}