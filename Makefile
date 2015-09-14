INC = /usr/include/

all:
	g++ -std=c++11 -o Ants main.cpp Chunk.cpp Game.cpp Hex.cpp World.cpp Block.cpp -lsfml-graphics -lsfml-window -lsfml-system