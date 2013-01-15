#include "player.h"
#include "item.h"
#include "../game.h"
#include <sstream>
using namespace WoS;
using namespace std;

Player::Player()
{
}

Player::Player(Game* g, string name)
	{
		cID = 0;
		cType = "player";
		cName = name;
		health = 100;
		maxhealth = 100;
		energy = 100;
		maxenergy = 100;
		game = g;
 	}

Player::~Player()
{
game = NULL;
}


void Player::action(const string act)
{
	// commands are given as:
	// <command> <preference>
	//
	// Available commands:
	// go <direction>
	//
	
	stringstream ss(act);

	string cmd;

	// Parses first word
	ss >> cmd;
	if(cmd.compare("go") == 0)
	{
		ss >> cmd;
		go(cmd);
		game->printRoom(cID,false);
	}else if(cmd.compare("wait") == 0)
	{
	}else if(cmd.compare("search") == 0)
	{
		searchRoom();
	}else if(cmd.compare("pick") == 0)
	{
		ss >> cmd;
		if(cmd.compare("up") == 0)
		{
		ss >> cmd;
		pick_up(cmd);
		}
	}else if(cmd.compare("drop") == 0)
	{
		ss >> cmd;
		drop(cmd);
		items.erase(cmd);
	}else if(cmd.compare("use") == 0)
	{
		string item;
		ss >> item;
		if(ss >> cmd)
		{
			ss >> cmd;
			fight(item,cmd);
		}
	}
	else
	{
	}
	return;
}

void Player::fight(string item, string character)
{
	Item* tmp = getItem(item);
	if(tmp != NULL)
	{
		game->fight(cID,tmp,character);
	}
	else{
		cout << "You don't have item " << item << endl;
	}
	return;
}

void Player::talk_to(string character)
{
	game->talkTo(cID,character);
	return;
}


