#include "game.h"

using namespace WoS;
using namespace std;

Game::Game()
{
	initializeRooms();
	initializeCharacters();
	cout << "kaoz! de startar!!!" << endl;
}
void Game::initializeRooms()
{

}

void Game::initializeCharacters()
{

}

Game::~Game()
{

}

Room& Game::getRoom(const int roomID) const
{
	return *room[roomID];
}

Room& Game::getRoom(const Character& character) const
{
	return *currentRoom[0];//character.ID()];
}

const vector<Character*> Game::getCharacters() const
{
	return character;
}

vector<Character*> Game::getCharacters(const int roomID) const
{
	return cir[roomID];
}

vector<Character*> Game::getCharacters(const Room& room) const
{
	return cir[0];//room.ID()];
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
	//cir.erase(find(cir.begin(),cir.end(),character.ID()));
	
	//currentRoom[character.ID()] = &newRoom;

	//cir[newRoom].push_back(&character);

}

void Game::setPlayer(Character* ch)
{
	character[0] = ch;
}
