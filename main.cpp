#include <iostream>
#include "functions.h"
#include "point.h"

int main(int argc, char** argv){
    //Variables
    unsigned int colonias;
	std::cin>>colonias;
    point* points = new point[colonias];
    int** distancias = new int*[colonias];
    int** flujo = new int*[colonias];
    std::cout<<"DESDEMAIN: "<<distancias<<std::endl;

    readInput(colonias, distancias, flujo, points);
    printMatrix(flujo, colonias);


    return 0;
}