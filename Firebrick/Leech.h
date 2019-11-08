#pragma once

class CLeech: public CMinion
{
private:
	int mHeal = 2; // Amount to heal friendly player
public:
	CLeech(int type, string name, int attack, int health);
	~CLeech();
	void Action(CPlayer* friendly, CPlayer* enemy);
};

