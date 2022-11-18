#include <iostream>
#include "headers/functions.h"
#include "headers/point.h"
#include "headers/edge.h"

int main(int argc, char** argv){
    //Variables
    unsigned int colonias;
	std::cin>>colonias;
    point* points = new point[colonias];
    unsigned int** distancias = new unsigned int*[colonias];
    unsigned int** flujo = new unsigned int*[colonias];

    readInput(colonias, distancias, flujo, points);
    Kruskal(distancias, colonias);

    terceraParte(flujo, colonias);

    NearestNeighbor(distancias, colonias);

    return 0;
}