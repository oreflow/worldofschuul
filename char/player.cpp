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
	cout << "player acting:" << act << endl;
	
	stringstream ss(act);

	string cmd;

	// Parses first word
	ss >> cmd;
	if(cmd.compare("go") == 0)
	{
		ss >> cmd;
		cout << go(cmd) << endl << endl;
	}
}

string Player::fight(string character)
{
	return 0;
}

string Player::talk_to(string character)
{
	return 0;
}


