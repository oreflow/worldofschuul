#include <item.h>
using namespace WoS;
using namespace std;


Item& Item::operator=(Item& i)
{
	return *this;
}
bool Item::operator==(Item& i)
{
	return iName.compare(i.iName);
}
const string Item::getName() const
{
return iName;
}
const string Item::getType() const
{
return type;
}
const int Item::getWeight() const
{
return weight;
}
const int Item::getVolume() const
{
return volume;
}
const int Item::getValue() const
{
return value;
}
