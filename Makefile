CXX=clang++-9 
CXXVERSION=c++2a
SOURCE_PATH=sources
OBJECT_PATH=objects
CXXFLAGS=-std=$(CXXVERSION) -Werror -Wsign-conversion -I$(SOURCE_PATH)

all: main test

main: main.o
	g++ -o main Team.cpp League.cpp Schedule.cpp Game.cpp main.cpp



main.o: Team.cpp League.cpp Schedule.cpp Game.cpp main.cpp
	g++ -c Team.cpp League.cpp Schedule.cpp Game.cpp main.cpp	


test: Test.cpp Team.cpp League.cpp Game.cpp Schedule.cpp TestCounter.cpp
	g++ Test.cpp Team.cpp League.cpp Game.cpp Schedule.cpp TestCounter.cpp -o test

.PHONY: main clean

clean:
	rm -f main main.o Game Game.o Team Team.o League League.o Schedule Schedule.o Test.o test TestCounter.o