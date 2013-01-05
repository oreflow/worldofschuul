FLAGS = -std=c++0x
P =/home/tim/Dropbox/cprog12/worldofschuul
DIRS =-I$(P)/char -I$(P)/it -I$(P)

characters: character player npc

character: char/character.cpp char/character.h items
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
	
room: room.cpp room.h items 
	g++ $(FLAGS) $(DIRS) -c room.cpp 

game: game.cpp characters items room 
	g++ $(FLAGS) $(DIRS) -c game.cpp  

WoS: WoS.cpp characters items room game
	g++ $(FLAGS) $(DIRS) character.o player.o game.o room.o item.o WoS.cpp -o WoS.o

clean:
	rm *.o
