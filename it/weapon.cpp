#include "weapon.h"
using namespace WoS;
using namespace std;
Weapon::Weapon()
{
}
Weapon::Weapon(string name)
{
	weight = 0;
	volume = 0;
	value = 0;
	iName = name;
}
Weapon::~Weapon()
{

}
	

string Weapon::getDescription()
{
	return "Weapon";
}
