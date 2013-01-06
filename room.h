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
	vector<Item*> items;
	int rID;
	string rName;
	string rDescription;

	public:
	Room(){}
	Room(const int ID, const string name, const string description);
	~Room();

	// add neighbour by string direction and pointer to neighbour
	void addNeighbour(string str, Room* room);

	bool isNeighbour(const string str);

	// returns ID of this room
	const int ID() const;
	// returns the name of this room
	const string getName() const;
	// returns a vector of pointers to the items in this room
	const vector<Item*> getItems() const;
	// removes given item from the room and returns its pointer
	Item* removeItem(string item);
	Item* removeItem(Item* item);
	// adds a item to the room
	bool addItem(Item* item);
	// returns the string description of this room
	const string getDescription() const;

	// prints a description of the room and what items are in the room
	const void printDescription() ;
	// prints the directions of the rooms exits
	void printDirections() ;

	// gets the room reached by the given direction, or NULL if direction does not exist
	Room* getDirection(string direction);

	string getRandomDirection();

};
}
