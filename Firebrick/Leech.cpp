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

CLeech::CLeech(int type, string name, int attack, int health):
	CMinion(type, name, attack, health)
{
}

CLeech::~CLeech()
{
}

// Action when Leech card is activated
// If the enemy has minions, choose one at random and attack it
// If the enemy has a Wall minion, attack that
// Else attack the enemy player
// Heal the friendly player
// Friendly and enemy player are passed in
void CLeech::Action(CPlayer* friendly, CPlayer* enemy)
{
	cout << mName << " attacks ";

	if (enemy->TableCount() > 0)						   // If the enemy has minions
	{
		int target;
		if (enemy->HasWall())							   // If the enemy has a Wall minion
		{
			target = enemy->FindWall();					   // Target the Wall minion
		}
		else
		{
			target = enemy->Random(enemy->TableCount()-1); // Choose a random enemy minion
		}
		enemy->MinionTakeDamage(mAttack, target);		   // Attack minion
	}
	else
	{
		enemy->PlayerTakeDamage(mAttack);				   // Attack enemy player
	}

	if (enemy->GetHealth() > 0)							   // If the enemy is alive
	{
		cout << mName << " heals ";
		friendly->PlayerTakeHeal(mHeal);				   // Heal the friendly player
	}
}
