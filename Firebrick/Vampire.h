#pragma once

class CVampire: public CMinion
{
private:
	int mHeal; // Amount the Vampire heals itself
public:
	CVampire(int type, string name, int attack, int health, int heal);
	~CVampire();
	void Action(CPlayer* friendly, CPlayer* enemy);
};

