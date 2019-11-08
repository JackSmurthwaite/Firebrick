#pragma once

class CArmour: public CCard
{
private:
	int mProtection;	 // Protection value to modify incoming damage
	const int mHeal = 2; // Amount to heal friendly player
public:
	CArmour(int type, string name, int protection);
	~CArmour();
	void Action(CPlayer* friendly, CPlayer* enemy);
};

