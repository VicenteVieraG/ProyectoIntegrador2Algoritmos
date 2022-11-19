# -*- MakeFile -*-

main: main.o PrimeraParte.o ParteDos.o TerceraParte.o
	g++ main.o PrimeraParte.o ParteDos.o TerceraParte.o -o main

main.o: main.cpp ./headers/comparator.h ./headers/point.h ./headers/functions.h
	g++ -c main.cpp

PrimeraParte.o: ./src/PrimeraParte.cpp ./headers/comparator.h ./headers/point.h ./headers/edge.h ./headers/functions.h
	g++ -c ./src/PrimeraParte.cpp

ParteDos.o: ./src/ParteDos.cpp ./headers/functions.h
	g++ -c ./src/ParteDos.cpp

TerceraParte.o: ./src/TerceraParte.cpp ./headers/functions.h
	g++ -c ./src/TerceraParte.cpp

clean:
	del *.o