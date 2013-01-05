#include "game.h"
#include <fstream>

using namespace WoS;
using namespace std;

Game::Game()
{
	loadMap();
	loadCharacters();
	cout << "Game map initialized" << endl;
}
void Game::loadMap()
{
	/*
	rooms.clear();
	ifstream in;
	string name;
	string description;
	in.open("gamemap.dat");
	getline(in,name);
	int rs = atoi(name);
	for(int i=0;i<rs;i++)
	{
		getline(in,name);
		getline(in,description);
		rooms.push_back(new Room(i,name,description));
	}	
	getline(in,name);
	int relations = atoi(name);

*/
}

void Game::loadCharacters()
{

}

void Game::loadItems()
{

}

Game::~Game()
{

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

string Game::moveCharacter(int characterID, string direction)
{
	Room oldRoom = getRoom(characterID);
	Room* newRoom = oldRoom.getDirection(direction);

	if(newRoom == NULL)
	{
		return "There is no room in that direction";
	}
	else{
		for(vector<Character*>::iterator it = cir[oldRoom.ID()].begin();it != cir[oldRoom.ID()].end();++it)
		{
			if((*it)->ID() == characterID)
			{
				cir[oldRoom.ID()].erase(it);
			}
		}

		cir[(*newRoom).ID()].push_back(characters[characterID]);
		currentRoom[characterID] = newRoom;
	}

}

void Game::setPlayer(Character* ch)
{
	if(characters.size() == 0)
	{
		characters.push_back(ch);
	}
	else{
		characters[0] = ch;
	}
}

void Game::runCommand(string command)
{
		for(vector<Character*>::iterator it = characters.begin();it != characters.end(); ++it)
		{
			(*it)->action(command);
		}
}
