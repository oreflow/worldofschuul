#pragma once

#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;
using namespace WoS;

class Actor{
	private:
		const string actorType;
		const string actorName;


	public:
		Actor() = 0;
		const string type()const;
	   	const string name()const;

		virtual void action() = 0;	
		virtual void go() = 0;
		virtual void fight() = 0;
		virtual void pick_up() = 0;
		virtual void drop() = 0;
		virtual void talk_to() = 0;
}
