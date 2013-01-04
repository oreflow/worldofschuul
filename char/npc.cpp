#include "npc.h"
#include "game.h"
#include "item.h"
using namespace WoS;
using namespace std;

NPC::NPC()
	{
 	}

NPC::NPC(Game* g, const int ID, const string type, const string name)
	{
		health = 50;
		maxhealth = 50;
		energy = 50;
		maxenergy = 50;
		game = g;

		cID = ID;
		cType = type;
		cName = name;
 	}

NPC::~NPC()
{

}


void NPC::action(const string)
{

}
string fight(string character)
{

}

string talk_to(string character)
{

}

