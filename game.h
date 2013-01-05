#pragma once

#include <room.h>

#include <player.h>
#include <npc.h>

#include <weapon.h>
#include <powerup.h>
#include <key.h>


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace WoS{

	class Game
	{
		private:
		int gameTimer;
		int rs;
		int chars;

		vector<Room*> rooms;
		vector<Character*> characters;

		vector<vector<Character*>> cir;
		vector<Room*> currentRoom;

		void loadMap();
		void loadCharacters();
		void loadItems();
		public:

		Room& getRoom(const int roomID) const;
		Room& getRoom(const Character& character) const;
		
		const vector<Character*> getCharacters() const;
		vector<Character*> getCharacters(const int roomID) const;
		vector<Character*> getCharacters(const Room& room) const;

		Item* takeItem(int characterID, string item);
		void dropItem(int characterID, Item* item);

		string moveCharacter(int characterID, string direction);
		void setPlayer(Character* ch);
		void runCommand(string command);


		Game();
		~Game();
	};
}
