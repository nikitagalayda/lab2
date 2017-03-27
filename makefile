main: cls.o main.o
	g++ -o cls main.o cls.o

cls.o: cls.cpp cls.h
	g++ -c cls.cpp

main.o: main.cpp cls.h
	g++ -c main.cpp
