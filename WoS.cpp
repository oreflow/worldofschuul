#include <iostream>
#include <stdlib.h>
#include "game.h"
#include "player.h"

using namespace std;
using namespace WoS;
int main()
{
	bool active = true;
	string str;
	cout << "You have entered the World of Schuul \nyour goal in this game is to learn stuff\nto your help you have the following commands:\ngo <direction>\nwait\nsearch\npick up <item>\ndrop <item>\nuse <item> on <target>\n\nType \"quit\" to leave the world of schuul" << endl;
	cout << "Enter your name: " << endl;
	cin >> str;
	Game g(str);
	cin.ignore(1);

	while(active)
	{
		cout << g.getCurrentRoomDescription() << endl;
		getline(cin,str);

		if(str.compare("exit") == 0 ||str.compare("quit") == 0 )
		{	
			cout << "Leaving the World of Schuul" << endl;
			active = false;
		}
		else
			g.runCommand(str);
	}

	return 0;
}



