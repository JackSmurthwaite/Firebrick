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

CCard::CCard(int type, string name): mType(type), mName(name)
{
}

CCard::~CCard()
{
}

void CCard::Action(CPlayer * friendly, CPlayer * enemy)
{
}

void CCard::IncreaseAttack(int amount)
{
}

void CCard::IncreaseArmour(int amount)
{
}

int CCard::GetType()
{
	return mType;
}

string CCard::GetName()
{
	return mName;
}

bool CCard::isMinion()
{
	return false;
}

void CCard::TakeDamage(int amount)
{
}

int CCard::GetHealth()
{
	return 0;
}

int CCard::GetAttack()
{
	return 0;
}

int CCard::GetArmour()
{
	return 0;
}

void CCard::TakeHeal(int amount)
{
}
