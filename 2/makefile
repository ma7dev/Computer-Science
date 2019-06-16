all: BlackJack

BlackJack: play_game.o game.o player.o dealer.o hand.o deck.o card.o
	g++ -o BlackJack play_game.o game.o player.o dealer.o hand.o deck.o card.o -o run
	run

play_game.o: play_game.cpp
	g++ -c -std=c++11 -o play_game.o play_game.cpp

game.o: game.h game.cpp
	g++ -c -std=c++11 game.h game.cpp

player.o: player.h player.cpp
	g++ -c -std=c++11 player.h player.cpp

dealer.o: dealer.h dealer.cpp
	g++ -c -std=c++11 dealer.h dealer.cpp

hand.o: hand.h hand.cpp
	g++ -c -std=c++11 hand.h hand.cpp

deck.o: deck.h deck.cpp
	g++ -c -std=c++11 deck.h deck.cpp

card.o: card.h card.cpp
	g++ -c -std=c++11 card.h card.cpp

clean:
	rm -f *.gch
	rm -f *.o