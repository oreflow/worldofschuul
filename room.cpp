#include "room.h"
using namespace WoS;
using namespace std;

Room::Room()
{
roomID = 0;
}

Room::~Room()
{

}

const int Room::ID() const
{
	return roomID;
}
