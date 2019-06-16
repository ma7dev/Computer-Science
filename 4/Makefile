all: Hunter
	
Hunter: main.o Game.o Room.o Events.o Gold.o Escape.o Wumpus.o Bats.o Pit.o Player.o 
	g++ -o Hunter main.o Game.o Room.o Events.o Gold.o Escape.o Wumpus.o Bats.o Pit.o Player.o -o run
	run -r 4 -c 4

main.o: main.cpp
	g++ -c -std=c++11 -o main.o main.cpp

Game.o: Game.h Game.cpp
	g++ -c -std=c++11 Game.h Game.cpp

Room.o: Room.h Room.cpp
	g++ -c -std=c++11 Room.h Room.cpp

Events.o: Events.h Events.cpp
	g++ -c -std=c++11 Events.h Events.cpp

Gold.o: Gold.h Gold.cpp
	g++ -c -std=c++11 Gold.h Gold.cpp

Escape.o: Escape.h Escape.cpp
	g++ -c -std=c++11 Escape.h Escape.cpp

Wumpus.o: Wumpus.h Wumpus.cpp
	g++ -c -std=c++11 Wumpus.h Wumpus.cpp

Bats.o: Bats.h Bats.cpp
	g++ -c -std=c++11 Bats.h Bats.cpp

Pit.o: Pit.h Pit.cpp
	g++ -c -std=c++11 Pit.h Pit.cpp

Player.o: Player.h Player.cpp
	g++ -c -std=c++11 Player.h Player.cpp

clean:
	rm -f *.gch
	rm -f *.o