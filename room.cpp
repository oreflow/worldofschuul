#include "room.h"
#include "item.h"
#include <time.h>
#include <set>
#include <stdexcept>

using namespace WoS;
using namespace std;


Room::Room(const int ID, const string name, const string description)
{
	rID = ID;
	rName = name;
	rDescription = description;
	needsKey = false;
}

Room::~Room()
{

}

void Room::addNeighbour(string str, Room* room)
{
	neighbours.insert(pair<string,Room*>(str,room));
}

Room* Room::getNeighbour(string direction) const 
{
	try{
		return neighbours.at(direction);
	}
	catch(...)
	{
		return NULL;
	}
}

const int Room::ID() const
{
	return rID;
}


const string Room::getName() const
{
	return rName;
}


Item* Room::removeItem(string item)
{
	try{
		Item* tmp = items.at(item);
		items.erase(item);
		return tmp;
	}
	catch(...)
	{
		return NULL;
	}
}

bool Room::addItem(Item* item)
{
	try{
	items.insert(pair<string,Item*>(item->getName(),item));
	return true;
	}
	catch(...)
	{
		return false;
	}
}



void Room::print(bool eItems) const 
{
	cout << rDescription << endl;

	if(eItems && items.size()>0)
	{
		cout << "in the room you can find: " << endl;
		for(map<string, Item*>::const_iterator it = items.begin(); it != items.end(); ++it)
		{
			cout << it->first << endl;
		}

	}
}

void Room::printDirections() const
{
	for(map<string, Room*>::const_iterator it = neighbours.begin(); it != neighbours.end(); ++it)
	{
		cout << it->first << " -> " << it->second->getName() << endl;
	}
}



string Room::getRandomDirection() const 
{
	srand ( time(NULL) );
	map<string,Room*>::const_iterator it = neighbours.begin();
	int random = rand() % neighbours.size();
	advance( it, random);
	return it->first;	

}
