# -*- MakeFile -*-

main: main.o PrimeraParte.o
	g++ main.o PrimeraParte.o -o main

main.o: main.cpp ./headers/comparator.h ./headers/point.h
	g++ -c main.cpp

PrimeraParte.o: ./src/PrimeraParte.cpp ./headers/comparator.h ./headers/point.h ./headers/edge.h
	g++ -c ./src/PrimeraParte.cpp

clean:
	del *.o
