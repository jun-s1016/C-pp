#pragma once
#include <iostream>

using namespace std;

class Zerg
{
protected:
	int health;
	int maxHP;
public:
	Zerg();
	~Zerg();

	void SetHP(int health);
	int GetHP();

	virtual void Recovery();


};

