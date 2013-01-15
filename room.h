#pragma once

#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

namespace WoS{
class Item;

class Room{
	private:
	map<string,Room*> neighbours;
	map<string,Item*> items;
	int rID;
	string rName;
	string rDescription;

	public:
	Room(){}
	Room(const int ID, const string name, const string description);
	~Room();
	
	bool needsKey;


	void addNeighbour(string str, Room* room);

	bool isNeighbour(const string str) const;
	Room* getNeighbour(string direction) const;

	const int ID() const;
	const string getName() const;
	
	Item* removeItem(string item);
	bool addItem(Item* item);

	void print(bool eItems) const ;
	void printDirections() const ;

	string getRandomDirection() const;

};
}
