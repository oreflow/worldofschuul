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
#include <algorithm>

using namespace std;

namespace WoS{

	class Game
	{
		protected:
		int gameTimer;
		vector<Room*> room;
		vector<Character*> character;

		vector<vector<Character*>> cir;
		vector<Room*> currentRoom;

		void initializeRooms();
		void initializeCharacters();

		public:

		Room& getRoom(const int roomID) const;
		Room& getRoom(const Character& character) const;
		
		const vector<Character*> getCharacters() const;
		vector<Character*> getCharacters(const int roomID) const;
		vector<Character*> getCharacters(const Room& room) const;

		bool moveCharacter(const Character& character, Room& newRoom);


		Game();
		~Game();
	};
}
	
using namespace WoS;
int main()
	{
		bool active = true;
		Game g ;
		string str;
		while(active)
		{
		cin >> str;
		cout << "Game Over!\nDu skrev: " << str << endl;
		active = false;
		}
		return 0;
	}

