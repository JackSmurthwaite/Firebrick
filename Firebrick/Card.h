#pragma once
#include <string>
class CPlayer;
using namespace std;

class CCard
{
protected:
	int mType;    // Card type number
	string mName; // Name of the card
public:
	CCard(int type, string name);
	~CCard();
	virtual void Action(CPlayer* friendly, CPlayer* enemy);
	virtual bool isMinion();
	virtual void TakeDamage(int amount);
	virtual int GetHealth();
	virtual int GetAttack();
	virtual int GetArmour();
	virtual void TakeHeal(int amount);
	virtual void IncreaseAttack(int amount);
	virtual void IncreaseArmour(int amount);
	int GetType();
	string GetName();
};

