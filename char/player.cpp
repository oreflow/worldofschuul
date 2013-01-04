#include "player.h"
using namespace WoS;
using namespace std;
Player::Player()
	{
		cID = 0;
		cType = "player";
		cName = "player";
 	}

Player::Player(const string name)
	{
		cID = 0;
		cType = "player";
		cName = name;
 	}

Player::~Player()
{

}


const bool Player::action(const string act)
{

}
