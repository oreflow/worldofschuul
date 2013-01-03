FLAGS =-Wall -std=c++0x
P =/home/tim/Dropbox/cprog12/worldofschuul
DIRS =-I$(P)/char -I$(P)/it -I$(P)

character: char/character.cpp char/character.h item
	g++ $(FLAGS) $(DIRS) -c char/character.cpp 

player: char/player.cpp char/player.h
	g++ $(FLAGS) $(DIRS) -c char/player.cpp 

npc: char/npc.cpp char/npc.h
	g++ $(FLAGS) $(DIRS) -c char/npc.cpp 

items: item weapon powerup key 

item: it/item.cpp it/item.h 
	g++ $(FLAGS) $(DIRS) -c it/item.cpp
weapon: it/weapon.cpp it/weapon.h
	g++ $(FLAGS) $(DIRS) -c it/weapon.cpp
powerup: it/powerup.cpp it/powerup.h
	g++ $(FLAGS) $(DIRS) -c it/powerup.cpp
key: it/key.cpp it/key.h
	g++ $(FLAGS) $(DIRS) -c it/key.cpp
	
room: room.cpp room.h item character 
	g++ $(FLAGS) $(DIRS) -c room.cpp 

game: game.cpp character item room
	g++ $(FLAGS) $(DIRS) -c game.cpp -o WoS.o

clean:
	rm *.o
