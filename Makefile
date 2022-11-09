# -*- MakeFile -*-

main: main.o PrimeraParte.o
	g++ main.o PrimeraParte.o -o main
	del *.o

main.o: main.cpp functions.h point.h
	g++ -c main.cpp

PrimeraParte.o: PrimeraParte.cpp functions.h point.h
	g++ -c PrimeraParte.cpp

clean:
	del *.o
