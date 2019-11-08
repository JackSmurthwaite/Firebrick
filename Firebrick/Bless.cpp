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

CBless::CBless(int type, string name, int attack, int heal): CSpell(type, name, attack), mHeal(heal)
{
}

CBless::~CBless()
{
}

// Action when Bless card is played
// Randomly selects one of: enemy minions, enemy player, friendly minions, friendly player
// If minions are chosen, one of them is randomly chosen
// If the target is friendly heal them, if they are not then attack them
// Friendly and enemy player are passed in
void CBless::Action(CPlayer* friendly, CPlayer* enemy)
{
	int target = enemy->Random(3);

	switch (target)
	{
	case 0:															// enemy minions
		if (enemy->TableCount() > 0)								// If there are minions
		{														
			cout << mName << " attacks ";						
			target = enemy->Random(enemy->TableCount() - 1);		// Choose random minion
			enemy->MinionTakeDamage(mAttack, target);				// Attack minion
		}
		else
		{
			cout << mName << " attacks ";						
			enemy->PlayerTakeDamage(mAttack);						// Attack enemy player
		}
		break;
	case 1:															// enemy player
		cout << mName << " attacks ";								// Attack enemy player
		enemy->PlayerTakeDamage(mAttack);
		break;
	case 2:															// friendly minions
		if (friendly->TableCount() > 0)							
		{
			cout << mName << " heals ";
			target = friendly->Random(friendly->TableCount() - 1);
			friendly->MinionTakeHeal(mHeal, target);				// Heal friendly minion
		}
		else
		{
			cout << mName << " heals ";
			friendly->PlayerTakeHeal(mHeal);						// Heal friendly player
		}
		break;
	case 3:															// friendly player
		cout << mName << " heals ";
		friendly->PlayerTakeHeal(mHeal);
		break;
	}

}