#include "character.h"
#include "game.h"
#include "item.h"
using namespace WoS;
using namespace std;

const int Character::ID() const
{
	return cID;
}

const string Character::type() const
{
	return cType;
}

const string Character::name() const
{
	return cName;
}

const vector<Item*> Character::getItems() const
{
	return items;
}


string Character::go(const string direction)
{
	return game->moveCharacter(ID(),direction);
}


string Character::pick_up(string item)
{
	Item* tmp = game->takeItem(cID,item);
	if(tmp != NULL)
	{
		items.push_back(tmp);
		cout << item << " picked up." << endl;
	}
	else
	{
		cout << item << " was not found" << endl;
	}
}

string Character::drop(string item)
{
	for(vector<Item*>::iterator it = items.begin();it != items.end();++it)
	{
		if((*it)->getName().compare(item) == 0)
		{
			// item was found in inventory
			game->dropItem(cID, (*it));
			items.erase(it);
			string ret = "Dropped item ";
			ret.append(item);
			return ret;
		}
	}
	string ret = "Was not able to drop ";
	ret.append(item);
	return ret;
}

