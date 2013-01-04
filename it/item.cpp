#include <item.h>
using namespace WoS;
using namespace std;


Item::Item()
{
}

Item::~Item()
{

}

Item& Item::operator=(Item& i)
{

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
