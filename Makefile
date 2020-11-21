FLAGS = -pedantic-errors -std=c++11

game: game.o show.o winGame.o endGame.o start.o path.o wolf.o monsterPlay.o castle.o finalStage.o bingo.o quitGame.o
	g++ game.o show.o winGame.o endGame.o start.o path.o wolf.o monsterPlay.o castle.o finalStage.o bingo.o quitGame.o -o game

game.o: game.cpp start.h stat.h wolf.h monsterPlay.h castle.h finalStage.h
	g++ -c game.cpp

quitGame.o: quitGame.cpp quitGame.h stat.h
	g++ -c quitGame.cpp

show.o: show.cpp show.h stat.h
	g++ -c show.cpp

winGame.o: winGame.cpp winGame.h stat.h
	g++ -c winGame.cpp

endGame.o: endGame.cpp endGame.h stat.h
	g++ -c endGame.cpp

bingo.o : bingo.cpp bingo.h endGame.h castle.h stat.h
	g++ -c bingo.cpp

start.o: start.cpp start.h path.h stat.h
	g++ -c start.cpp

path.o: path.cpp path.h endGame.h show.h wolf.h stat.h quitGame.h
	g++ -c path.cpp

wolf.o: wolf.cpp wolf.h show.h monsterPlay.h castle.h quitGame.h endGame.h stat.h
	g++ -c wolf.cpp

monsterPlay.o: monsterPlay.cpp monsterPlay.h show.h castle.h endGame.h bingo.h quitGame.h stat.h
	g++ -c monsterPlay.cpp

castle.o: castle.cpp finalStage.h show.h winGame.h endGame.h bingo.h quitGame.h stat.h
	g++ -c castle.cpp

finalStage.o: finalStage.cpp finalStage.h show.h winGame.h endGame.h quitGame.h stat.h
	g++ -c finalStage.cpp

clean:
	rm -f *o game

tar:
	tar -czvf *.cpp *.h

.PHONY: clean tar
