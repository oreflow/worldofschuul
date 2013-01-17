#include "game.h"
#include <fstream>
#include <sstream>

using namespace WoS;
using namespace std;

Game::Game(string str)
{
	chars = 0;
	gameTimer = 30;
	loadMap();

	loadCharacters(str);

	loadItems();
	rooms[6]->needsKey = true;
	cout << "Game map initialized" << endl;
}
void Game::loadMap()
{

	rooms.clear();
	ifstream in;
	string name;
	string description;
	in.open("gamemap.dat");
	getline(in,name);
	rs = atoi(name.c_str());
	for(int i=0;i<rs;i++)
	{
		getline(in,name);
		getline(in,description);
		rooms.push_back(new Room(i,name,description));
	}	
	getline(in,name);
	int relations = atoi(name.c_str());
	string str;
	for(int i=0;i<relations;i++)
	{
		getline(in,str);
		string from,to,dir;
		istringstream ss( str );

		getline( ss, from, ',' );
		getline( ss, to,  ',' );
		getline( ss, dir,   ',' );
		rooms[atoi(from.c_str())]->addNeighbour(dir,rooms[atoi(to.c_str())]);
		//cout << "DEBUG " << "From " << from << " To: " << to << " Dir: " << dir << endl;
	}
}

void Game::loadCharacters(string str)
{

	cir.resize(rs);
	Character* c = new Player(this, str);
	characters.push_back(c);
	currentRoom.push_back(rooms[0]);
	cir[0].push_back(characters[0]);
	chars++;

	//labasse Erik börjar i lab-salen
	c = new NPC(this,1,"Labassisstant","Erik");
	characters.push_back(c);
	currentRoom.push_back(rooms[4]);
	cir[4].push_back(characters[1]);
	chars++;

	//Läraren står och väntar i "lecture hall"
	c = new NPC(this,2,"Teacher","Stefan");
	characters.push_back(c);
	currentRoom.push_back(rooms[6]);
	cir[6].push_back(characters[2]);
	chars++;
}

void Game::loadItems()
{
	items.push_back(new Weapon("book"));
	rooms[3]->addItem(items[0]);

	items.push_back(new Key("key",6));
	characters[1]->addItem(items[1]);

	items.push_back(new Weapon("knowledge"));
	characters[2]->addItem(items[2]);

}

Game::~Game()
{
	for(vector<Room*>::iterator it = rooms.begin();it != rooms.end();++it)
	{
		delete (*it);
	}	
	for(vector<Character*>::iterator it = characters.begin();it != characters.end();++it)
	{
		delete (*it);
	}
	for(vector<Item*>::iterator it = items.begin();it != items.end();++it)
	{
		delete (*it);
	}

}

void Game::printRoom(int characterID,bool description) const
{
	currentRoom[characterID]->print(description);
}

Room& Game::getRoom(const int characterID) const
{
	return *currentRoom[characterID];
}

Room& Game::getRoom(const Character& character) const
{
	return *currentRoom[character.ID()];
}

const vector<Character*> Game::getCharacters() const
{
	return characters;
}

vector<Character*> Game::getCharacters(const int roomID) const
{
	return cir[roomID];
}

vector<Character*> Game::getCharacters(const Room& room) const
{
	return cir[room.ID()];
}

void Game::takeItem(int characterID, string item)
{

	Item* tmp = currentRoom[characterID]->removeItem(item);
	if(tmp == NULL)
	{
		cout << "Item " << item << " was not found" << endl;
		return;
	}
	{
		cout << "Picked up item " << item << endl;
		characters[characterID]->addItem(tmp);
		return;
	}

}

void Game::dropItem(int characterID, Item* item)
{
	currentRoom[characterID]->addItem(item);
}


void Game::moveCharacter(int characterID, string direction)
{

	Room* oldRoom = currentRoom[characterID];
	Room* newRoom = oldRoom->getNeighbour(direction);

	if(newRoom == NULL)
	{
		cout <<  "There is no room in that direction" << endl;
		return;
	}


	if(newRoom->needsKey)
	{
		string str = "key";
		if(characters[characterID]->getItem(str) == NULL)
		{
			cout <<  "you need a key to enter that room" << endl ;
			return;
		}
	}
	if(oldRoom->needsKey)
	{
		string str = "key";
		if(characters[characterID]->getItem(str) == NULL)
		{
			return;
		}
	}

	vector<Character*>::iterator it;
	for(it = cir[oldRoom->ID()].begin();it != cir[oldRoom->ID()].end(); ++it)
	{
		if((*it)->ID() == characterID)
		{
			break;
		}
	}
	cir[oldRoom->ID()].erase(it);

	cir[(*newRoom).ID()].push_back(characters[characterID]);
	currentRoom[characterID] = newRoom;

	if(characterID == 0)
	{
		cout << "Moved " << direction << endl;
	}
}

void Game::fight(int charID, Item* item, string target)
{
	cout << "DEBUG trying to use " << item->getName() << " on " << target << endl; 
	Character* t;
	for(vector<Character*>::iterator it = characters.begin();it != characters.end();++it)
	{
		if(((*it)->name()).compare(target) == 0)
			t = *it;
	}
	if(currentRoom[charID] != currentRoom[t->ID()])
	{
		cout << "Cannot find target" << endl;
		return;
	}
	if(item->getName().compare("book") == 0)
	{
		cout << "You whack the book across the face of " << t->name() << endl;
		t->takeDamage(50);

	}
}
void Game::talkTo(int charID, string target)
{
	return;
}
bool Game::gameGoal()
{
	if(	currentRoom[0]->ID() == 6 &&
		characters[0]->getItem("key") != NULL &&
		characters[0]->getItem("book") != NULL)
		return true;

	return false;

}
bool Game::gameLost()
{
	if(gameTimer<=0)
		return true;
	return false;
}

int Game::timeLeft()
{
	return gameTimer;
}

void Game::runCommand(string command)
{
	for(vector<Character*>::iterator it = characters.begin();it != characters.end(); ++it)
	{
		(*it)->action(command);
	}
	gameTimer--;
}
