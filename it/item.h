#pragma once

#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;
namespace WoS{

class Item{
	protected:
	int weight;
	int volume;
	int value;

	const string name;
	const string type;

	public:
	Item();
	~Item();
	Item& operator=(Item& i);
	const int getWeight()const;
	const int getVolume()const;
	const int getValue()const;
	virtual string getDescription()=0;

};
}
