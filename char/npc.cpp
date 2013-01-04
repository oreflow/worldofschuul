#include "npc.h"
using namespace WoS;
using namespace std;

NPC::NPC()
	{
 	}

NPC::NPC(const int ID, const string type, const string name)
	{
		cID = ID;
		cType = type;
		cName = name;
 	}

NPC::~NPC()
{

}


const bool NPC::action(const string act)
{

}
