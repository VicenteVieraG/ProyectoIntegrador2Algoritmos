#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>
#include "../headers/functions.h"

void terceraParte( unsigned int** flux, int colonias){
    int source = 0, sink = colonias -1;

    std::cout<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<std::endl;
	std::cout<<"Tercera Parte:"<<std::endl<<std::endl;
    
    std::cout << "Flujo Máximo: " <<fordFulkerson(flux,colonias,source,sink)<<std::endl;

    std::cout<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<std::endl;
}

// Finds a path from source to sink, and make sure there is still
// space for flux
// Complexity : O(NumOfVerticies^2)
bool bfs(unsigned int** residualFlux,int colonias, int source, int sink, int pathStorage[]){
    bool* visited = new bool[colonias];
    // Mark all colonias as not visited
    for(int i = 0; i < colonias; i++){
        visited[i] = 0;
    }

 
    // Standard BFS
    std::queue<int> q;
    q.push(source);
    visited[source] = true;
    pathStorage[source] = -1;
 
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        for (int i = 0; i < colonias; i++) {
            if (visited[i] == false && residualFlux[u][i] > 0) {
                // Once we find a path to the sink node
                // we return true
                if (i == sink) {
                    pathStorage[i] = u;
                    return true;
                }
                q.push(i);
                pathStorage[i] = u;
                visited[i] = true;
            }
        }
    }

    // There is no path to reach sink from source
    return false;
}

// The ford fulkerson algorithm find the gratest flux, between two nodes
// in a weighted graph, it will try to augment the flux in al vertices,
// it return the maximum flux
// Complexity O(MaxFlux*E)
int fordFulkerson(unsigned int** flux,int colonias, int source, int sink) {
    int u, v;
    
    // Residual graph
    unsigned int** residualGraph = flux;
    
    // Filled by bfs axilary function
    int* pathStorage = new int[colonias]; 
 
    int maxFlux = 0; 
 
    // While there is still room for more flux on paths, augment it
    while (bfs(residualGraph,colonias, source, sink, pathStorage)) {
        
        int pathFlow = INT32_MAX;
        for (v = sink; v != source; v = pathStorage[v]) {
            u = pathStorage[v];
            pathFlow = std::min(pathFlow, (int) residualGraph[u][v]);
        }
 
        // Update residual capacities
        for (v = sink; v != source; v = pathStorage[v]) {
            u = pathStorage[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }
 
        // Add path flow to overall flux
        maxFlux += pathFlow;
    }
 
    return maxFlux;
}