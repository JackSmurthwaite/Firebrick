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

CArmour::CArmour(int type, string name, int protection): CCard(type, name), mProtection(protection)
{
}

CArmour::~CArmour()
{
}

// Action when armour card is played
// If the friendly player has any minions on the table, choose one at random and apply armour
// Else heal the friendly player
// Friendly and enemy player are passed in
void CArmour::Action(CPlayer* friendly, CPlayer* enemy)
{
	if (friendly->TableCount() > 0)								 // If the friendly player has minions
	{
		cout << mName << " increases armour of  ";
		int target = friendly->Random(friendly->TableCount()-1); // Choose random minion
		friendly->MinionIncreaseArmour(mProtection, target);	 // Increase minions armour
	}
	else														 // There are no minions
	{
		cout << mName << " heals ";
		friendly->PlayerTakeHeal(mHeal);						 // Heal friendly player
	}
}
