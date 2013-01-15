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
	cout << "You have entered the World of Schuul \nYou have a lecture in 30 minutes, if you don't make it in time you will fail the course\nto your help you have the following commands:\ngo <direction>\nwait\nsearch\npick up <item>\ndrop <item>\nuse <item> on <target>\n\nType \"quit\" to leave the world of schuul" << endl;
	cout << "Enter your name: " << endl;
	getline(cin,str);
	Game g(str);

	g.printRoom(0,false) ;

	while(active)
	{
		getline(cin,str);
		for(int i=0;i<50;i++)
		{
			cout << "-";
			if(i == 24)
				cout << "Time left: " << g.timeLeft();
		}
		cout << "-" <<endl;

		if(str.compare("exit") == 0 ||str.compare("quit") == 0 )
		{	
			cout << "Leaving the World of Schuul" << endl;
			active = false;
		}
		if(g.gameGoal())
		{
			cout << "You have made it to the lecture room in time\n and won't fail the course" << endl;
			active = false;
		}
		else if(g.gameLost())
		{
			cout << "You didn't make it to the lecture in time and will therefore fail the course" << endl;
			active = false;
		}
		else
		{
			cout << endl;
			g.runCommand(str);
		}
	}

	return 0;
}



