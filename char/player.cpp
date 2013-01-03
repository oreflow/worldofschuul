#include "player.h"

Player::Player()
	{
		actorID = 0;
		actorType = "player";
		actorName = "player";
 	}

Player::Player(const string name)
	{
		actorID = 0;
		actorType = "player";
		actorName = name;
 	}

Player::~Player()
{

}


const bool Player::action(const string act)
{

}
