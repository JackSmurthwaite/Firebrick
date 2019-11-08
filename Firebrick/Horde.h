#pragma once

class CHorde: public CMinion
{
public:
	CHorde(int type, string name, int attack, int health);
	~CHorde();
	void Action(CPlayer* friendly, CPlayer* enemy);
};

