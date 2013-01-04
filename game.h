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
		int rooms;
		int chars;

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

		Item* takeItem(int characterID, string item);
		void dropItem(int characterID, Item* item);

		string moveCharacter(int characterID, string direction);
		void setPlayer(Character* ch);


		Game();
		~Game();
	};
}
	
using namespace WoS;
int main()
	{
		bool active = true;
		string str;
		cout << "background story: enter name." << endl;
		cin >> str;
		Game g;
		Player* p = new Player(&g, str);
		g.setPlayer(p);

		while(active)
		{
		cin >> str;

		cout << "Game Over!\nDu skrev: " << str << endl;
		active = false;
		}

		return 0;
	}

