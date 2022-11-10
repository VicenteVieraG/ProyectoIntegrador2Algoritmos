#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "functions.h"
#include "comparator.h"
#include "point.h"
#include "edge.h"

//Declarations

//Reads the specified input and returns two matrixes with the data and an array of points
void readInput(unsigned int& colonias, unsigned int** distancias, unsigned int** flujo, point* points){
	//Variables
	std::string coordenada;
	std::string aux;
	point P;
	int it = 0;

	//Initialize matrixes
	for(unsigned int i=0;i<colonias;i++){
		distancias[i] = new unsigned int[colonias];
		flujo[i] = new unsigned int[colonias];
	}
	//Get the vaules for colonias
	for(unsigned int i=0;i<colonias;i++){
		for(unsigned int j=0;j<colonias;j++){
			std::cin>>distancias[i][j];
		}
	}
	//Get the vaules for flow
	for(unsigned int i=0;i<colonias;i++){
		for(unsigned int j=0;j<colonias;j++){
			std::cin>>flujo[i][j];
		}
	}
	//Get coordinates
	for(unsigned int i=0;i<colonias;i++){
		std::cin>>coordenada;
		//Get the numbers
		for(unsigned int j=0;j<coordenada.length();j++){
			if(coordenada[j]>47 && coordenada[j]<58){
				aux+=coordenada[j];
			}else if(coordenada[j]==44){
				//Foud a ',' , add the number and clean aux
				P.x = std::stoul(aux);
				aux = "";
			}else if(coordenada[j]==41){
				//Found ')' meaning is the end fo the input and the delimiter of the y coordinate
				//Set P.y to aux, add it to the array of points, reset point and axis and set it++
				P.y = std::stoul(aux);
				points[it] = P;
				P.reset();
				aux = "";
				it++;
			}
		}
	}
}

//Prints the matrix based in the size
void printMatrix(unsigned int** M, unsigned int& size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			std::cout<<M[i][j]<<std::endl;
		}
	}
}

//Returns the root node of the Disjoint set data of nodes
unsigned int Root(unsigned int* V, unsigned int i){
	//Follos the parents tree until the node whose parent it´s it self
	if(V[i]==i)return i;
	return Root(V, V[i]);
}

//Makes the operation Union(A,B) in the Vertex array
void Union(unsigned int* V, edge E){
	//Get the nodes of the edge
	unsigned int A = E.src;
	unsigned int B = E.dest;
	//Make B the parent of A
	V[Root(V, A)] = Root(V, B);
}

//Makes operaton Find(A,B)
//Finds if there is a cycle.
//If there is a cycle it returns true, else false.
//If both node´s root are the same means they are in the same subset therefore, there is a cycle.
bool Find(unsigned int* V, edge E){
	//Get the nodes of the edge
	unsigned int A = E.src;
	unsigned int B = E.dest;
	if(Root(V, A) == Root(V, B))return true;
	return false;
}

//Making the function class for the comparison in the heap
bool comparator::operator()(const edge& E, const edge& E2){
	return E.weight>E2.weight;
}

std::priority_queue<edge,std::vector<edge>,comparator> pq;

void test(){
	edge E(1,2,1);
	edge E2(1,2,2);
	edge E3(1,2,3);
	edge E4(1,2,4);
	edge E5(1,2,5);
	edge E6(1,2,6);
	edge E7(1,2,7);
	edge E8(1,2,8);
	edge E9(1,2,120);
	edge E10(1,2,20);
	edge E11(1,2,10);

	pq.push(E);
	pq.push(E2);
	pq.push(E3);
	pq.push(E4);
	pq.push(E5);
	pq.push(E6);
	pq.push(E7);
	pq.push(E8);
	pq.push(E9);
	pq.push(E10);
	pq.push(E11);

	int s = pq.size();
	for(int i=0;i<s;i++){
		std::cout<<pq.top();
		pq.pop();
	}
}