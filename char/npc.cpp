#include "player.h"

NPC::NPC()
	{
 	}

NPC::NPC(const int ID, const string type, const string name)
	{
		actorID = ID;
		actorType = type;
		actorName = name;
 	}

NPC::~NPC()
{

}


const bool NPC::action(const string act)
{

}
