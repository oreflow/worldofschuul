#pragma once

#include "character.h"
#include "player.h"
#include "npc.h"
#include "item.h"
#include "weapon.h"
#include "powerup.h"
#include "key.h"
#include "room.h"

#include <iostream>
#include <vector>

using namespace std;

namespace WoS{

	class Game
	{
		private:
		vector<Room*> room;
		vector<Character*> character;

		vector<vector<Character*>> cir;
		vector<Room*> currentRoom;
		public:

		Room& getRoom(const int roomID) const;
		Room& getRoom(const Character& character) const;
		
		const vector<Character*> getCharacters() const;
		vector<Character*> getCharacters(const int roomID) const;
		vector<Character*> getCharacters(const Room& room) const;

		bool moveCharacter(const Character& character, const Room newRoom);



		Game();
		~Game();
	};

	
}

int main()
	{
		bool active = true;
		Game g = new Game;
		string str;
		while(active)
		{
		cin >> str;
		cout << "Game Over" << endl;
		}
		return 0;
	}
