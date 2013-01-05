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
		cout << "You have entered the World of Schuul \nyour goal in this game is to learn stuff\nto your help you have the following commands:\ngo <direction>\nsearch\npick up <item>\ndrop <item>\nuse <item> on <target>\n" << endl;
		cout << "Enter your name: " << endl;
		cin >> str;
		Game g(str);

		while(active)
		{
			getline(cin,str);
		
		if(str.compare("exit") == 0 ||str.compare("quit") == 0 )
		  {	
			cout << "Exiting the World of Schuul" << endl;
			active = false;
		  }
		else
			g.runCommand(str);
		
		}

		return 0;
	}


