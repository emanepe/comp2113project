FLAGS = -pedantic-errors -std=c++11

d2boh.o: gamefunc.cpp gamefunc.h
	g++ $(FLAGS) -c $<

main.o: main.cpp gamefunc.h
	g++ $(FLAGS) -c $<

main: gamefunc.o main.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f main main.o gamefunc.o

.PHONY: clean

