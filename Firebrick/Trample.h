#pragma once

class CTrample: public CMinion
{
public:
	CTrample(int type, string name, int attack, int health);
	~CTrample();
	void Action(CPlayer* friendly, CPlayer* enemy);
};

