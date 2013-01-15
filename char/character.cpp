#include "character.h"
#include "../game.h"
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

bool Character::addItem(Item* item)
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

void Character::go(const string direction)
{
	game->moveCharacter(ID(),direction);
	return;
}

void Character::pick_up(string item)
{
	game->takeItem(cID,item);
	return;
}


void Character::drop(string item)
{
	try{
		Item* tmp = items.at(item);

		game->dropItem(cID,tmp);
		return;
	}
	catch(...)
	{
		return;
	}
}


void Character::searchRoom()const 
{
	game->printRoom(cID,true);
}

Item* Character::getItem(string itemName)
{
	try{
		return items.at(itemName);
	}
	catch(...)
	{
		return NULL;
	}
}

void Character::takeDamage(int dmg)
{
	health -= dmg;
}
