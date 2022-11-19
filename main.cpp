#include <iostream>
#include "headers/functions.h"
#include "headers/point.h"
#include "headers/edge.h"
#include <vector>

int main(int argc, char** argv){
    //Variables
    unsigned int colonias;
	std::cin>>colonias;
    std::vector<point> P;

    unsigned int** distancias = new unsigned int*[colonias];
    unsigned int** flujo = new unsigned int*[colonias];

    readInput(colonias, distancias, flujo, P);
    Kruskal(distancias, colonias);

    terceraParte(flujo, colonias);

    NearestNeighbor(distancias, colonias);
    GrahamAlgorithm(P);

    return 0;
}