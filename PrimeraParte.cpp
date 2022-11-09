#include <iostream>
#include <string>
#include "functions.h"
#include "point.h"

//Declarations

//Reads the specified input and returns two matrixes with the data and an array of points
void readInput(unsigned int& colonias, int** distancias, int** flujo, point* points){
	//Variables
	std::string coordenada;
	std::string aux;
	point P;
	int it = 0;
	std::cout<<"DESDEPRIMERA: "<<distancias<<std::endl;

	//Initialize matrixes
	for(unsigned int i=0;i<colonias;i++){
		distancias[i] = new int[colonias];
		flujo[i] = new int[colonias];
	}
	//Get the vaules for colonias
	for(unsigned int i=0;i<colonias;i++){
		for(unsigned j=0;j<colonias;j++){
			std::cin>>distancias[i][j];
			//std::cout<<distancias[i][j]<<std::endl;
		}
	}
	//Get the vaules for flow
	for(unsigned int i=0;i<colonias;i++){
		for(unsigned j=0;j<colonias;j++){
			std::cin>>flujo[i][j];
			//std::cout<<flujo[i][j]<<std::endl;
		}
	}
	//Get coordinates
	points = new point[colonias];
	for(unsigned int i=0;i<colonias;i++){
		std::cin>>coordenada;
		//std::cout<<coordenada<<std::endl;
		//Get the numbers
		for(unsigned int j=0;j<coordenada.length();j++){
			if(coordenada[j]>47 && coordenada[j]<58){
				aux+=coordenada[j];
			}else if(coordenada[j]==44){
				//Foud a ',' , add the number and clean aux
				P.x = std::stoi(aux);
				aux = "";
			}else if(coordenada[j]==41){
				//Found ')' meaning is the end fo the input and the delimiter of the y coordinate
				//Set P.y to aux, add it to the array of points, reset point and axis and set it++
				P.y = stoi(aux);
				points[it] = P;
				P.reset();
				aux = "";
				it++;
			}
		}
	}
}

void printMatrix(int** M, unsigned int& size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			std::cout<<M[i][j]<<std::endl;
		}
	}
}