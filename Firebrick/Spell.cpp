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

CSpell::CSpell(int type, string name, int attack): CCard(type, name), mAttack(attack)
{
}

CSpell::~CSpell()
{
}
