#pragma once

#include <stdlib.h>
#include <string>
#include <vector>
#include "character.h"

using namespace std;
namespace WoS{
class Item;

class NPC : public Character
	{
protected:
		// returns the damage and attack type
		virtual string fight(string character);

		//returns answer from said character
		virtual string talk_to(string character);

	public:
		NPC();
		// constructor setting character name to given string
		NPC(Game* g, const int ID, const string type, const string name);
		
		~NPC();
		
		//takes a string argument and performs the given action.
		//returns true if action was successful
		//false otherwise
		virtual void action(const string playerAction);
};
}
