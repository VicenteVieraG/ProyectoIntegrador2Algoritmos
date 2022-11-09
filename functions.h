#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "point.h"
#include "edge.h"

void readInput(unsigned int& colonias, unsigned int** distancias, unsigned int** flujo, point* points);
void printMatrix(unsigned int**,unsigned int&);
void Union(unsigned int* V, edge E);
bool Find(unsigned int* V, edge E);
unsigned int Root(unsigned int* V, unsigned int i);

#endif