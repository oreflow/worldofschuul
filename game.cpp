#include "game.h"
#include <fstream>
#include <sstream>

using namespace WoS;
using namespace std;

Game::Game(string str)
{
	chars = 0;
	gameTimer = 0;
	loadMap();

	loadCharacters(str);
	
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
		//cout << "From: " << from << " To: " << to << endl;
	}
}

void Game::loadCharacters(string str)
{

	cir.resize(rs);
	Player* p = new Player(this, str);
	characters.push_back(p);
	currentRoom.push_back(rooms[0]);
	cir[0].push_back(characters[0]);
	chars++;
}

void Game::loadItems()
{

}

Game::~Game()
{

}

string Game::getCurrentRoomDescription() const
{
	return getRoom(*characters.at(0)).getDescription();
}

Room& Game::getRoom(const int roomID) const
{
	return *rooms[roomID];
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

Item* Game::takeItem(int characterID, string item)
{
	Room r = *currentRoom[characterID];
	return r.removeItem(item);
}

void Game::dropItem(int characterID, Item* item)
{
	currentRoom[characterID]->addItem(item);
}

bool Game::canMove(const int characterID, const string direction) const
{
	return getRoom(characterID).isNeighbour(direction);
}

string Game::moveCharacter(int characterID, string direction)
{
	Room oldRoom = getRoom(characterID);
	Room* newRoom = oldRoom.getDirection(direction);

	if(newRoom == NULL)
	{
		return "There is no room in that direction";
	}
	else{
		cir[oldRoom.ID()].clear();

		cir[(*newRoom).ID()].push_back(characters[characterID]);
		currentRoom[characterID] = newRoom;
	}
	//TODO Maybe another return value?
	return "Moved " + direction;
}

void Game::runCommand(string command)
{
		for(vector<Character*>::iterator it = characters.begin();it != characters.end(); ++it)
		{
			(*it)->action(command);
		}
}
