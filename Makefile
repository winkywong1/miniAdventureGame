FLAGS = -pedantic-errors -std=c++11

game: game.o car.o bingo.p show.o winGame.o endGame.o start.o path.o wolf.o monsterPlay.o castle.o finalStage.o
	g++ game.o endGame.o start.o -o game

game.o: game.cpp start.h
	g++ -c game.cpp
	
car.o:  car.cpp car.h
        g++ -c car.cpp
bingo.o: bingo.cpp bingo.h
         g++ -c bingo.cpp

show.o: show.cpp show.h
	g++ -c show.cpp

winGame.o: winGame.cpp winGame.h
	g++ -c winGame.cpp

endGame.o: endGame.cpp endGame.h
	g++ -c endGame.cpp

start.o: start.cpp start.h path.h
	g++ -c start.cpp

path.o: path.cpp path.h endGame.h show.h wolf.h 
	g++ -c path.cpp

wolf.o: wolf.cpp wolf.h show.h monsterPlay.h castle.h endGame.h
	g++ -c wolf.cpp

monsterPlay.o: monsterPlay.cpp monsterPlay.h show.h castle.h endGame.h
	g++ -c monsterPlay.cpp

castle.o: castle.cpp finalStage.h show.h winGame.h endGame.h
	g++ -c castle.cpp

finalStage.o: finalStage.cpp finalStage.h show.h winGame.h endGame.h
	g++ -c finalStage.cpp

clean:
	rm -f *o game

tar:
	tar -czvf *.cpp *.h

.PHONY: clean tar
