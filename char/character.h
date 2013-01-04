#pragma once

#include <stdlib.h>
#include <string>
#include <vector>
#include "item.h"

using namespace std;
namespace WoS
{

class Character{
	protected:
		int cID;
		string cType;
		string cName;
		int health;
		int maxhealth;
		int energy;	
		int maxenergy;

		
		
		// returns the id of the room reached by the go command
		int go(const string direction);

		// returns the damage and attack type
		virtual string fight(Character& character) = 0;

		// returns the item picked up or NULL if pickup failed
		virtual Item& pick_up(Item& item) = 0;

		// returns 0 if item was dropped or error ID otherwise
		virtual int drop(Item& item) = 0;

		//returns answer from character
		virtual bool talk_to(Character& character) = 0;

	public:
		const int ID() const;
		const string type() const;
	   	const string name() const;
};
}
