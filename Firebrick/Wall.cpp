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

CWall::CWall(int type, string name, int attack, int health):
	CMinion(type, name, attack, health)
{
}

CWall::~CWall()
{
}

// Action when Wall minion is activated
// If the enemy has minions, choose one at random and attack it
// Else attack the enemy player
void CWall::Action(CPlayer* friendly, CPlayer* enemy)
{
	cout << mName << " attacks ";

	if (enemy->TableCount() > 0)							// If the enemy has minions
	{
		int target;
		if (enemy->HasWall())								// If the enemy has a Wall minion
		{
			target = enemy->FindWall();						// Target the Wall minion
		}
		else
		{
			target = enemy->Random(enemy->TableCount()-1);	// Target a random enemy minion
		}
		enemy->MinionTakeDamage(mAttack, target);			// Attack the target
	}
	else
	{
		enemy->PlayerTakeDamage(mAttack);					// Attack the enemy player
	}
}
