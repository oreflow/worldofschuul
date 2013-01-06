#include "room.h"
#include "item.h"
#include <time.h>
#include <set>

using namespace WoS;
using namespace std;


Room::Room(const int ID, const string name, const string description)
{
	rID = ID;
	rName = name;
	rDescription = description;
}

Room::~Room()
{

}

void Room::addNeighbour(string str, Room* room)
{
	neighbours.insert(pair<string,Room*>(str,room));
}

bool Room::isNeighbour(const string str)
{
	if(neighbours[str] == 0)
		return false;
	return true;
}

const int Room::ID() const
{
	return rID;
}


const string Room::getName() const
{
	return rName;
}

const vector<Item*> Room::getItems() const
{
	return items;
}

Item* Room::removeItem(string item)
{
	for(vector<Item*>::iterator it = items.begin();it!= items.end();++it)
	{
		if(((*it)->getName()).compare(item) == 0)
		{
			Item* tmp = *it;
			items.erase(it);
			return tmp;
		}
	}
	return NULL;
}

Item* Room::removeItem(Item* item)
{
	for(vector<Item*>::iterator it = items.begin();it!= items.end();++it)
	{
		if(*(*it) == *item)
		{
			Item* tmp = *it;
			items.erase(it);
			return tmp;
		}
	}
	return NULL;
}

bool Room::addItem(Item* item)
{
	items.push_back(item);
	return 0;
}

const string Room::getDescription() const
{
	return rDescription;
}

const void Room::printDescription()
{
	cout << rDescription << endl;

	cout << "in the room you can find: " << endl;
	
	for(vector<Item*>::iterator it = items.begin();it!= items.end();++it)
	{
		cout << (*it)->getName() << endl;
	}
}

void Room::printDirections() 
{
	for(map<string, Room*>::iterator it = neighbours.begin(); it != neighbours.end(); ++it)
	{
		cout << it->first << " -> " << it->second->getName() << endl;
	}
}

Room* Room::getDirection(string direction)
{
	return neighbours.at(direction);
}

string Room::getRandomDirection()
{
	srand ( time(NULL) );
	map<string,Room*>::iterator it = neighbours.begin();
	int random = rand() % neighbours.size();
	advance( it, random);
	return it->first;	

}
