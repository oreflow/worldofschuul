#pragma once

#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
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

		map<string,Item*> items;
		
		Game* game;		
		
		void go(const string direction);

		virtual void fight(string item, string character) = 0;

		void pick_up(string item);

		void drop(string item);

		virtual void talk_to(string character) = 0;

		void searchRoom() const;


	public:
		const int ID() const;
		const string type() const;
	   	const string name() const;
		virtual void action(const string act)= 0;

		void takeDamage(int dmg);
		bool addItem(Item* it);
		Item* getItem(string name);
};
}
