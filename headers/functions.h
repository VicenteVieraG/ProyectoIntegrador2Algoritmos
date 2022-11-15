#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "point.h"
#include "edge.h"
#include "comparator.h"

//Basic Input Output functions

void readInput(unsigned int& colonias, unsigned int** distancias, unsigned int** flujo, point* points);
void printMatrix(unsigned int**,unsigned int&);

//Disjoint Set Union functions

void Union(unsigned int* V, const edge& E);
bool Find(unsigned int* V, edge E);
unsigned int Root(const unsigned int* V, const unsigned int& i);

//Kruskal algorithm

void Kruskal(unsigned int** M, const unsigned int& size);

// Ford-Fulkenson algorithm

void terceraParte( unsigned int** flux, int colonias);
bool bfs(unsigned int** residualFlux,int colonias, int source, int sink, int pathStorage[] );
int fordFulkerson( unsigned int** flux, int colonias, int source, int sink);

#endif