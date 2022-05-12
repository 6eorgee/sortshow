all: link

compile:
	g++ -std=c++17 -c main.cpp renderer.cpp sorts.cpp tools.cpp

link: compile
	g++ main.o renderer.o sorts.o tools.o -o vis -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -rf *.o vis
