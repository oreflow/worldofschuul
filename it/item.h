#pragma once

#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;
namespace WoS{

class Item{
	int weight;
	string name;

	public:
	Item();
	~Item();
	Item& operator=(Item& i);
};
}
