#pragma once

#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;
namespace WoS{

class Game;
class Item;
class Character{
	protected:
		int cID;
		string cType;
		string cName;
		int health;
		int maxhealth;
		int energy;	
		int maxenergy;

		vector<Item*> items;
		
		Game* game;		
		
		// returns empty string if move was possible, error message otherwise
		string go(const string direction);

		// returns the damage and attack type
		virtual string fight(string character) = 0;

		// returns the item picked up or NULL if pickup failed
		string pick_up(string item);

		// returns empty string if pickup was possible, error message otherwise
		string drop(string item);

		//returns answer from character
		virtual string talk_to(string character) = 0;

		virtual void action(const string act)= 0;

	public:
		const int ID() const;
		const string type() const;
	   	const string name() const;
		const vector<Item*> getItems() const;
};
}
