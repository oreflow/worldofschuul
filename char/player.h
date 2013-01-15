#pragma once

#include <stdlib.h>
#include <string>
#include <map>
#include "character.h"

using namespace std;
namespace WoS{
class Item;

class Player : public Character
	{

protected:
		// returns the damage and attack type
		virtual void fight(string item, string character);

		//returns answer from character
		virtual void talk_to(string character);
		
	public:
		Player();
		// a player always has ID = 0
		// constructor taking parameters game and name 
		Player(Game* g, string name);
		
		~Player();
		
		//takes a string argument and performs the given action.
		virtual void action(const string act);
};
}
