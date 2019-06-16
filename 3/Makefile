all: Zoo_Tycoon

Zoo_Tycoon: main.o Game.o Zoo.o Animal.o Tiger.o Bear.o Monkey.o Peng.o 
	g++ -o Zoo_Tycoon main.o Game.o Zoo.o Animal.o Tiger.o Bear.o Monkey.o Peng.o -o run
	run

main.o: main.cpp
	g++ -c -std=c++11 -o main.o main.cpp

Game.o: Game.h Game.cpp
	g++ -c -std=c++11 Game.h Game.cpp

Zoo.o: Zoo.h Zoo.cpp
	g++ -c -std=c++11 Zoo.h Zoo.cpp

Animal.o: Animal.h Animal.cpp
	g++ -c -std=c++11 Animal.h Animal.cpp

Tiger.o: Tiger.h Tiger.cpp
	g++ -c -std=c++11 Tiger.h Tiger.cpp

Bear.o: Bear.h Bear.cpp
	g++ -c -std=c++11 Bear.h Bear.cpp

Monkey.o: Monkey.h Monkey.cpp
	g++ -c -std=c++11 Monkey.h Monkey.cpp

Peng.o: Peng.h Peng.cpp
	g++ -c -std=c++11 Peng.h Peng.cpp

clean:
	rm -f *.gch
	rm -f *.o