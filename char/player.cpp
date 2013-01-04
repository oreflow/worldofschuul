#include "player.h"
#include "item.h"
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

}

string Player::fight(string character)
{

}

string Player::talk_to(string character)
{

}


