#include "npc.h"
#include "../game.h"
#include "item.h"
#include "room.h"
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

		inWorld = true;
 	}

NPC::~NPC()
{
game = NULL;
}


void NPC::action(const string playerAction)
{
	if(!inWorld)
		return;
	if(energy<10)
	{
		//om energy är mindre än 10
		for(vector<Item*>::iterator it = items.begin();it != items.end();++it)
		{
			drop((*it)->getName());
		}
		inWorld = false;
		cout << cName << "has dropped all items and fled from the world of schuul" << endl;
		return;
	}

	Room myRoom = game->getRoom(ID());

	if(&game->getRoom(cID) != &game->getRoom(0))
	{// npcn är inte i samma rum som spelaren
		string direct = myRoom.getRandomDirection();
		go(direct);
	}
	else{
		// npcn är i samma rum som spelaren
		fight("question", "player");
	}
	//use
}
string NPC::fight(string item, string character)
{
	cout << cType << " " << cName << " asks a difficult question about c++\nYour answer is:" << endl;
	string answer;
	getline(cin,answer);
	if(answer.compare("polymorphism") == 0)
	{
		energy = 0;
		action("");
	}
	return "";
}

string NPC::talk_to(string character)
{
	return "";
}

