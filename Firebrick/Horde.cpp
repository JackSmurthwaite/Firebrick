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

CHorde::CHorde(int type, string name, int attack, int health):
	CMinion(type, name, attack, health)
{
}

CHorde::~CHorde()
{
}

// Action when Horde card is activated
// If the enemy players has minions, choose one at random and attack it
// If the enemy has a Wall minion, attack that
// Else attack the enemy player
// Increase the attack of the card for every other Horde card on the players table
// Friendly and enemy player are passed in
void CHorde::Action(CPlayer* friendly, CPlayer* enemy)
{
	cout << mName << " attacks ";

	if (enemy->TableCount() > 0)							     // If there are enemy minions
	{
		int target;
		if (enemy->HasWall())									 // If the enemy has Wall
		{
			target = enemy->FindWall();							 // Target the Wall
		}
		else
		{
			target = enemy->Random(enemy->TableCount()-1);		 // Choose a random minion
		}
		enemy->MinionTakeDamage(friendly->HordeCount(), target); // Get number of horde minions and attack the enemy
																 
	}
	else
	{
		enemy->PlayerTakeDamage(friendly->HordeCount());	      // Attack the enemy player
	}
}
