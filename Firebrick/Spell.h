#pragma once

class CSpell: public CCard
{
protected:
	int mAttack; // Damage the spell does
public:
	CSpell(int type, string name, int attack);
	~CSpell();
};

