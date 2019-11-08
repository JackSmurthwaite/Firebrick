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

CSword::CSword(int type, string name, int attackInc): CCard(type, name), mAttackInc(attackInc)
{
}

CSword::~CSword()
{
}

// Action when Sword card is played
// If the friendly player has minions, choose one at random and increase its attack value
// Else heal the friendly player
void CSword::Action(CPlayer* friendly, CPlayer* enemy)
{
	if (friendly->TableCount() > 0)								 // If the friendly player has minions
	{
		cout << mName << " increases attack of ";
		int target = friendly->Random(friendly->TableCount()-1); // Choose random minion
		friendly->MinionIncreaseAttack(mAttackInc, target);		 // Increase minions attack
	}
	else
	{
		cout << mName << " heals ";
		friendly->PlayerTakeHeal(mAttackInc);					  // Heal friendly player
	}
}
