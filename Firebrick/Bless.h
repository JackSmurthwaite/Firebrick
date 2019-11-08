#pragma once

class CBless: public CSpell
{
private:
	int mHeal; // Amount to heal friendly player
public:
	CBless(int type, string name, int attack, int heal);
	~CBless();
	void Action(CPlayer* friendly, CPlayer* enemy);
};

