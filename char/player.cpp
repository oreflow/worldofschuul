#include "player.h"
#include "item.h"
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
		cout << go(cmd) << endl << endl;
	}else if(cmd.compare("wait") == 0)
	{
	}else if(cmd.compare("search") == 0)
	{
		cout << searchRoom() << endl << endl;
	}else if(cmd.compare("pick") == 0)
	{
		ss >> cmd;
		if(cmd.compare("up") == 0)
		{
		ss >> cmd;
		cout << pick_up(cmd) << endl << endl;
		}
	}else if(cmd.compare("drop") == 0)
	{
		ss >> cmd;
		cout << drop(cmd) << endl << endl;
	}else if(cmd.compare("use") == 0)
	{
		string item;
		ss >> item;
		if(ss >> cmd)
		{
			ss >> cmd;
			cout << fight(item,cmd) << endl << endl;
		}
	}


}

string Player::fight(string item, string character)
{
	cout << "Fighting " << character << " with " << item << endl;
	return "";
}

string Player::talk_to(string character)
{
	return 0;
}


