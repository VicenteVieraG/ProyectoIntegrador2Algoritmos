#include <queue>
#include <limits>
#include <iostream>
#include <unordered_map>
#include "../headers/functions.h"

bool DFS(unsigned int** M, const unsigned int& size, std::unordered_map<unsigned int,bool>& visitedNodes, std::queue<unsigned int>& remainingNodes, unsigned int currentNode, std::queue<unsigned int>& path){
	//BASS cases
	if(remainingNodes.empty())return true;

	unsigned int min = INT32_MAX;
	unsigned int minNode = 0;

	//Search the adjacent node with min weight to the current node
	for(unsigned int i=0;i<size;i++){
		if(M[currentNode][i]<min && M[currentNode][i]!=0 && !visitedNodes[i]){
			min = M[currentNode][i];
			minNode = i;
		}
	}

	//Travel to the min weighted node, mark it as visited, add it to the path and remove
	//a node from remainigNodes
	visitedNodes[minNode] = true;
	path.push(minNode);
	remainingNodes.pop();
	DFS(M, size, visitedNodes, remainingNodes, minNode, path);
}

void NearestNeighbor(unsigned int** M, const unsigned int& size){
	//Variables
	std::unordered_map<unsigned int, bool> visitedNodes;
	std::queue<unsigned int> remainingNodes;
	std::queue<unsigned int> path;

	//Initialize visitedNodes
	for(unsigned int i=0;i<size-1;i++)visitedNodes[i] = false;
	//Initializing remaining
	for(unsigned int i=0;i<size;i++)remainingNodes.push(i);

	//Start by visiting the first Node
	visitedNodes[0] = true;
	path.push(0);
	DFS(M, size, visitedNodes, remainingNodes, 0, path);

	//Print the path
	for(int i=0;!path.empty();i++){
		std::cout<<path.front()<<"=>"<<std::endl;
		path.pop();
	}
}