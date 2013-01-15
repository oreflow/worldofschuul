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

	string iName;
	string type;
	public:
	Item& operator=(Item& i);
	bool operator==(Item& i);
	const string getName() const;
	const string getType() const;
	const int getWeight() const;
	const int getVolume() const;
	const int getValue() const;
	virtual string getDescription()=0;

};
}
