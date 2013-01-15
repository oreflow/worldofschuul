#pragma once

#include <stdlib.h>
#include <string>
#include <vector>
#include <item.h>

using namespace std;
namespace WoS{

class Key : public Item{
	public:	
	int roomnr;
	Key(string name,int room);
	virtual string getDescription();
	~Key();
};
}
