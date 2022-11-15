# Actividad Integradora 2
###### TC2038.601
## Created by:
- Vicente Javier Viera Guízar | A01639784
- Renet de Jesús Pérez Gómez | A01640555
- Carlos García Mercado | A01633757
## Creation date:
- 08/11/2022
# Problem Overview
During the year 2020 the whole world was affected by an event that nobody expected: the pandemic caused by COVID-19. In every country on the planet, sanitary measures were taken to try to contain the pandemic. One of these measures was to send the entire population to their homes,
moving a large part of face-to-face activities to a remote model in which Internet Service Provider companies (ISPs) took a more than leading role. Many people moved to the modality of remote work, or home-office,
Also, the majority of educational institutions chose to continue their operations under a remote model, greatly increasing the transmission of data on the Internet.

If it were in our hands to improve Internet services in a small population,
Could we decide how to wire the most important points of said population in such a way that the least amount of fiber optics is used?

Assuming we have several ways to connect two nodes in the population,

For a person who has to visit all the points in the network,
What will be the optimal way to visit all points in the network and return to the point of origin?

Could we analyze the maximum amount of information that can pass from one node to another?

Could we analyze the feasibility of connecting a new point (a new location) on the map to the network?
# Problem Breackdown
1. read an input file that contains the information of a graph represented in the form of an adjacency matrix with weighted graphs
The weight of each edge is the distance in kilometers between colony and colony, where it is feasible to insert cables.
The program must display what is the optimal way to wire with fiber optics connecting colonies in such a way that information can be shared between any two colonies.

2. Because cities are just entering the technological world, someone is required to visit each neighborhood to drop off physical account statements,
printed advertising, notices and notifications. For this reason, you want to know what is the shortest possible route that visits each colony exactly once and at the end returns to the origin colony?
The program must display the route to consider, taking into account that the first city will be called A, the second B, and so on.

3. The program must also read another square matrix of N x N data representing the maximum data transmission capacity between colony i and colony j. As we are working with cities with a large amount of electromagnetic fields, which can generate interference, estimates have already been made that are reflected in this matrix.
The company wants to know the maximum flow of information from the initial node to the final node. This should also be displayed on stdout.
Finally

4. Given the geographic location of various "exchanges" to which new houses may be connected, the company wants a way to decide,
given a new contract for the service, which is the closest geographical center to that new contract. There is not necessarily a central for each neighborhood. You can have colonies without central, and colonies with more than one central.
# Part One
## Aproach:
<div style="text-align: justify">
To solve this problem a __Minimun Spanning Tree (MST)__ was implemented through the __Kruskal's MST algorithm__. With this aproach we ensure to connect all nodes with the minimun weight possible.

The concept of the Kruskal's algorithm is simple but consists of several parts that need to be binded together. How this works is by first adding all the edges to a __min heap structure__ then, for each edge in the min heap we verify that no cycles are being created and just after this we make a relation between the edges. This Union and Cycle verifications are easy to do with the implementation of a __Disjoint Set Union Tree (DSUT)__ where the nodes are initially stored, then sorted with Kruskal´s algorithm and finally getting the MST with the relations created between the nodes.
</div>

# Algorithms Implemented:
## readInput
### Description:
>Reads the specified input and returns two matrixes with the data and an array of points
### Time complexity:
>O(n+n^2+n^2+n*m) => O(n(1+2n+m)) => O(n^2+nm)
## printMatrix:
### Description:
>Prints the matrix based in the size
### Time Complexity:
>O(n^2)
## Root:
### Description:
>Returns the root node of the Disjoint set data of nodes
### Time Complexity:
>Complexity: O(n)
## Union:
### Description:
>Makes the operation Union(A,B) in the Vertex array
### Time Complexity:
>Complexity: O(2n) => O(n)
## Find:
### Description:
>Makes operaton Find(A,B).Finds if there is a cycle.If there is a cycle it returns true, else false.If both node´s root are the same means they are in the same subset therefore, there is a cycle.
### Time Complexity:
>Complexity: O(2n) => O(n)
## Kruskal:
### Description:
>Kruskal's algorithm for minimun spanning tree
### Time Complexity:
>Main algorithm complexity: O(|E|(4|V|+log(|E|)))  
>Complete function complexity: O(|V|+|E|log(|E|)+|E|(4|V|+log(|E|))+|V|) => O(2|V|+2|E|log(|E|)+4|E||V|) => O(2(|V|+|E|+|E|log(|E|)+2|E||V|)) => O(|V|+|E|+|E|log(|E|)+|E||V|) => O(|E|(|V|+1+log(|E|)+|V|)) => O(|E|(|V|+log(|E|)+|V|)) => O(|E|(|V|+log(|E|))) => O(|E||V|+|E|log(|E|))
