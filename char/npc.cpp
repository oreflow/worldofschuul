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

	if(energy<10 || health < 10)
	{
		//om energy är mindre än 10
		for(map<string,Item*>::iterator it = items.begin();it != items.end();++it)
		{
			drop(it->first);
		}
		inWorld = false;
		items.clear();
		cout << cName << " has dropped all items and fled from the world of schuul" << endl;
		return;
	}

	Room myRoom = game->getRoom(ID());

	if(&game->getRoom(cID) != &game->getRoom(0))
	{// npcn är inte i samma rum som spelaren
		srand ( time(NULL) );
		int random = rand() % 100;
		if(random>50)
		{
			string direct = myRoom.getRandomDirection();
			go(direct);
		}
		else
			wait();
	}
	else{
		// npcn är i samma rum som spelaren
		fight("question", "player");
	}
}

void NPC::fight(string item, string character)
{
	if(cType.compare("Labassisstant") == 0){
	cout << cType << " " << cName << " asks a difficult question about c++\nYour answer is:" << endl;
	string answer;
	getline(cin,answer);
	if(answer.compare("polymorphism") == 0)
	{
		energy = 0;
		action("");
	}
	return ;
	}else if(cType.compare("Teacher") == 0)
	{
	if(!game->gameGoal())
		cout << cType << " " << cName << ": You need to bring a book to the lecture " << endl;
	else
		cout << cType << " " << cName << ": Yay, you made it" << endl;
	return ;
	}
}

void NPC::talk_to(string character)
{
	return;
}

