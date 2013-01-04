#pragma once

#include <stdlib.h>
#include <string>
#include <vector>
#include "character.h"
#include "item.h"

using namespace std;
namespace WoS
{

class Player : public Character
	{

protected:
		// returns the id of the room reached by the go command
		virtual int go(const string direction);

		// returns the damage and attack string
		virtual string fight();

		// returns the item picked up or NULL if pickup failed
		virtual Item& pick_up();

		// returns 0 if item was dropped or error ID otherwise
		virtual int drop();

		//returns answer from said character
		virtual bool talk_to(Character& a);

	public:
		// a player always has ID = 0
		// defualt constructor sets character name to player
		Player();
		// constructor setting character name to given string
		Player(const string name);
		
		~Player();
		
		//takes a string argument and performs the given action.
		//returns true if action was successful
		//false otherwise
		const bool action(const string action);
};
}
