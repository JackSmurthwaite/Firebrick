#pragma once

class CFireball: public CSpell
{
public:
	CFireball(int type, string name, int attack);
	~CFireball();
	void Action(CPlayer* friendly, CPlayer* enemy);
};

