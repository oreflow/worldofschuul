#include "character.h"
using namespace WoS;
using namespace std;

const int Character::ID() const
{
	return cID;
}

const string Character::type() const
{
	return cType;
}

const string Character::name() const
{
	return cName;
}

Character::~Character()
{
game = NULL;
}

int go(const string direction)
{
}