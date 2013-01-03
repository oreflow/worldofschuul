#include "game.h"

Game::Game()
{
	initializeRooms();
	initializeCharacters();
	cout << "kaoz! de startar!!!" << endl;
}
void initializeRooms()
{

}

void initializeCharacters()
{

}

Game::~Game()
{

}

Room& getRoom(const int roomID) const
{
	return *room[roomID];
}

Room& getRoom(const Character& character) const
{
	return currentRoom[character.ID()];
}

const vector<Character*> getCharacters() const
{
	return character;
}

vector<Character*> getCharacters(const int roomID) const
{
	return cir[roomID];
}

vector<Character*> getCharacters(const Room& room) const
{
	return cir[room.ID()];
}

bool moveCharacter(const Character& character, const Room& newRoom)
{
	cir.erase(find(cir.begin(),cir.end(),character.ID()));
	
	currentRoom[character.ID()] = &newRoom;

	cir[newRoom].push_back(&character);

}
