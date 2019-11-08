#pragma once
#include <string>
using namespace std;

class CLightning: public CSpell
{
public:
	CLightning(int type, string name, int attack);
	~CLightning();
	void Action(CPlayer* friendly, CPlayer* enemy);
};

