# -*- MakeFile -*-

main: main.o PrimeraParte.o
	g++ main.o PrimeraParte.o -o main

main.o: main.cpp comparator.h point.h
	g++ -c main.cpp

PrimeraParte.o: PrimeraParte.cpp comparator.h point.h edge.h
	g++ -c PrimeraParte.cpp

clean:
	del *.o
