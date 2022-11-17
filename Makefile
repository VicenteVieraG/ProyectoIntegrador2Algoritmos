# -*- MakeFile -*-

main: main.o PrimeraParte.o ParteDos.o
	g++ main.o PrimeraParte.o ParteDos.o -o main

main.o: main.cpp ./headers/comparator.h ./headers/point.h ./headers/functions.h
	g++ -c main.cpp

PrimeraParte.o: ./src/PrimeraParte.cpp ./headers/comparator.h ./headers/point.h ./headers/edge.h ./headers/functions.h
	g++ -c ./src/PrimeraParte.cpp

ParteDos.o: ./src/ParteDos.cpp ./headers/functions.h
	g++ -c ./src/ParteDos.cpp

clean:
	del *.o
