#include <iostream>
#include "functions.h"
#include "point.h"
#include "edge.h"

int main(int argc, char** argv){
    //Variables
    unsigned int colonias;
	std::cin>>colonias;
    point* points = new point[colonias];
    unsigned int** distancias = new unsigned int*[colonias];
    unsigned int** flujo = new unsigned int*[colonias];

    readInput(colonias, distancias, flujo, points);
    // printMatrix(flujo, colonias);
    //unsigned int arr[] = {2,0,4,4,4,5};
    //Union(arr, E);
    //std::cout<<Find(arr, E);
    //test();
    Kruskal(distancias, colonias);


    return 0;
}