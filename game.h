#pragma once

#include "room.h"

#include "player.h"
#include "npc.h"

#include "weapon.h"
#include "key.h"


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
		vector<Item*> items;

		vector<vector<Character*>> cir;
		vector<Room*> currentRoom;


		void loadMap();
		void loadCharacters(string str);
		void loadItems();

		Room& getRoom(const Character& character) const;
		
		const vector<Character*> getCharacters() const;
		vector<Character*> getCharacters(const int roomID) const;
		vector<Character*> getCharacters(const Room& room) const;


		public:

		Room& getRoom(const int characterID) const;

		void printRoom(int characterID, bool description) const;
		
		void takeItem(int characterID, string item);
		void dropItem(int characterID, Item* item);

		void moveCharacter(int characterID, string direction);
		
		void fight(int charID, Item* item, string target);
		void talkTo(int charID, string target);

		bool gameGoal();
		bool gameLost();
		int timeLeft();
		
		void runCommand(string command);


		Game(string str);
		~Game();
	};
}
