#pragma once

#include <stdlib.h>
#include <string>
#include <vector>
#include <item.h>

using namespace std;
namespace WoS{

class Weapon : public Item{
	public:
	Weapon();
	Weapon(string name);
	~Weapon();
	virtual string getDescription();

};
}
