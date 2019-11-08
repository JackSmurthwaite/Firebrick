#pragma once

class CWall: public CMinion
{
public:
	CWall(int type, string name, int attack, int health);
	~CWall();
	void Action(CPlayer* friendly, CPlayer* enemy);
};

