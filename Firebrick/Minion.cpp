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

CMinion::CMinion(int type, string name, int attack, int health):
	CCard(type, name),
	mAttack(attack),
	mHealth(health)
{
}

CMinion::~CMinion()
{
}

void CMinion::IncreaseAttack(int amount)
{
	mAttack += amount;
}

void CMinion::IncreaseArmour(int amount)
{
	mArmour += amount;
}

int CMinion::GetAttack()
{
	return mAttack;
}

int CMinion::GetArmour()
{
	return mArmour;
}

int CMinion::GetHealth()
{
	return mHealth;
}

// Take damage with armour modifier applied
// Damage must be over 0 to prevent minus numbers
void CMinion::TakeDamage(int amount)
{
	if (amount > 0)					   // If damage is over 0
	{
		mHealth -= (amount - mArmour); // Reduce health by damage amount with armour modifier 
	}
}

void CMinion::TakeHeal(int amount)
{
	mHealth += amount;
}

bool CMinion::isMinion()
{
	return true;
}

// Action when Minion card is activated
// If the enemy has minions, choose one at random and attack it
// If the enemy has a Wall minion, attack that
// Else attack the enemy player
// Friendly and enemy player are passed in
void CMinion::Action(CPlayer* friendly, CPlayer* enemy)
{
	cout << mName << " attacks ";

	if (enemy->TableCount() > 0)						   // If the enemy has minions
	{
		int target;
		if (enemy->HasWall())							   // If the enemy has a Wall minion
		{
			target = enemy->FindWall();					   // Target the Wall
		}
		else
		{
			target = enemy->Random(enemy->TableCount()-1); // Target a random minion
		}
		enemy->MinionTakeDamage(mAttack, target);		   // Attack the target
	}
	else
	{
		enemy->PlayerTakeDamage(mAttack);				   // Attack the enemy player
	}
}
