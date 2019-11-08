#pragma once
#include "Card.h"

class CMinion: public CCard
{
protected:
	int mAttack;     // Amount of damage the minion does
	int mHealth;     // Amount of health the minion has
	int mArmour = 0; // Amount of armour the minion has
public:
	CMinion(int type, string name, int attack, int health);
	~CMinion();
	void Action(CPlayer* friendly, CPlayer* enemy);
	bool isMinion();
	void TakeDamage(int amount);
	int GetHealth();
	void TakeHeal(int amount);
	void IncreaseAttack(int amount);
	void IncreaseArmour(int amount);
	int GetAttack();
	int GetArmour();
};
