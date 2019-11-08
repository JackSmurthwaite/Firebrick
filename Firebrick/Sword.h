#pragma once

class CSword: public CCard
{
private:
	int mAttackInc; // Attack amount the sword increases
public:
	CSword(int type, string name, int attackInc);
	~CSword();
	void Action(CPlayer* friendly, CPlayer* enemy);
};

