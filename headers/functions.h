#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <queue>
#include <limits>
#include <unordered_map>

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

//Nearest Neighbor

void NearestNeighbor(unsigned int** M, const unsigned int& size);
bool DFS(unsigned int** M, const unsigned int& size, std::unordered_map<unsigned int,bool>& visitedNodes, std::queue<unsigned int>& remainingNodes, unsigned int currentNode, std::queue<unsigned int>& path);

#endif