#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "point.h"
#include "edge.h"
#include "comparator.h"

//Basic Input Output functions

void readInput(unsigned int& colonias, unsigned int** distancias, unsigned int** flujo, point* points);
void printMatrix(unsigned int**,unsigned int&);

//Disjoint Set Union functions

void Union(unsigned int* V, edge E);
bool Find(unsigned int* V, edge E);
unsigned int Root(unsigned int* V, unsigned int i);
void test();

//Kruskal algorithm

void Kruskal(unsigned int** M, const unsigned int& size);

#endif