#include <iostream>
#include "functions.h"
#include "point.h"
#include "edge.h"

int main(int argc, char** argv){
    //Variables
    unsigned int colonias;
	std::cin>>colonias;
    point* points = new point[colonias];
    int** distancias = new int*[colonias];
    int** flujo = new int*[colonias];

    //readInput(colonias, distancias, flujo, points);
    //printMatrix(flujo, colonias);
    edge E(2,4,2);
    unsigned int arr[] = {2,0,4,4,4,5};
    //Union(arr, E);
    std::cout<<Find(arr, E);


    return 0;
}