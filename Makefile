FLAGS = -pedantic-errors -std=c++11

.PHONY: clean all

main: main.o display.o game.o save.o start.o
	g++ $(FLAGS) $^ -o $@

main.o: main.cpp game.h
	g++ $(FLAGS) -c $<

game.o: game.cpp game.h save.h start.h
	g++ $(FLAGS) -c $<

save.o: save.cpp save.h
	g++ $(FLAGS) -c $<

start.o: start.cpp start.h display.h
	g++ $(FLAGS) -c $<

display.o: display.cpp display.h
	g++ $(FLAGS) -c $<

all: main

clean:
	rm -f main *.o
