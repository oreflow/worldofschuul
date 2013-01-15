#include "key.h"
using namespace WoS;
using namespace std;
Key::Key(string name, int room)
{
	weight = 0;
	volume = 0;
	value = 100;
	iName = name;
	type = "key";
	roomnr = room;
}
string Key::getDescription()
{
	return "key opening door to a room ";
}

Key::~Key()
{

}
	
