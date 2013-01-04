#pragma once

#include <stdlib.h>
#include <string>
#include <vector>
#include <item.h>

using namespace std;

namespace WoS{

class Room{
	Room* Neighbours;
	vector<Item> items;
	int roomID;

	public:
	Room();
	~Room();
	const int ID() const;


};
}
