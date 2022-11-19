# Actividad Integradora 2
###### TC2038.601
## Created by:
- Vicente Javier Viera Guízar | A01639784
- Renet de Jesús Pérez Gómez | A01640555
- Carlos García Mercado | A01633757
## Creation date:
- 08/11/2022
# Scripts Gide
## Run
### __CMake Needed__
### Run All Tests For Windows with CMake:
>./src/run
## Build
### Biuild for Windows
>./src/build
## Run with no CMake
### Run All Tests for Windows
>./src/rnmk
## Build with no CMake
### Build for Windows
>./src/buildnmk
### Build for Linux/Unix withouth CMake
>./src/buildbs
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
>$O(n+n^2+n^2+n*m) => O(n(1+2n+m)) => O(n^2+nm)$
## printMatrix:
### Description:
>Prints the matrix based in the size
### Time Complexity:
>O(n^2)
## Root:
### Description:
>Returns the root node of the Disjoint set data of nodes
### Time Complexity:
>Complexity: $O(n)$
## Union:
### Description:
>Makes the operation Union(A,B) in the Vertex array
### Time Complexity:
>Complexity: $O(2n) => O(n)$
## Find:
### Description:
>Makes operaton Find(A,B).Finds if there is a cycle.If there is a cycle it returns true, else false.If both node´s root are the same means they are in the same subset therefore, there is a cycle.
### Time Complexity:
>Complexity: $O(2n) => O(n)$
## Kruskal:
### Description:
>Kruskal's algorithm for minimun spanning tree
### Time Complexity:
>Main algorithm complexity: $O(|E|(4|V|+log(|E|)))$  
>Complete function complexity: $O(|V|+|E|log(|E|)+|E|(4|V|+log(|E|))+|V|) => O(2|V|+2|E|log(|E|)+4|E||V|) => O(2(|V|+|E|+|E|log(|E|)+2|E||V|)) => O(|V|+|E|+|E|log(|E|)+|E||V|) => O(|E|(|V|+1+log(|E|)+|V|)) => O(|E|(|V|+log(|E|)+|V|)) => O(|E|(|V|+log(|E|))) => O(|E||V|+|E|log(|E|))$
# Part Two
## Aproach:
<div style="text-align: justify">

The algorithm implemented for this problem was the __Nearest Neighbor Algorithm__, Basicly a DFS with minimun weighted path. The function works __Recursively__ entering in a node and checking for each of it´s neighbors nodes wich one has the __minimun weight__ and if it has not been visited yet, if that case is found visits the node and the function is repeated.
</div>

# Algorithms Implemented
## DFS
### Description:
>Depth First Search traverse all graph with min weight
### Time complexity:
>$O(n^2)$
## Nearest Neighbor
### Description:
>Is the setter function for the __DFS__
# Part Three
## Aproach:
<div style="text-align: justify">

To solve this problem, the __Ford Fulkerson__ algorithm was implement, thsi ensure the maximun flux using all available nodes in the graph.

The Ford Fulkerson algortihm, finds a path from source node to sink node through a BFS of the graph, once found, itr verifies the maximum flux that can fullt pass through all the nodes, taking in to consideration de residual flux left by previous paths found. Once determined the maximun flux of the path the overall flux and residual graph are updated. This is repeted until the BFS isn´t able to find a path from source to sink.
</div>

# Algorithms Implemented:
## BFS:
### Description:
>BFS use to find a path from source to sink in a graph considering flux
### Time Complexity:
>Complexity: $O(NumOfVerticies^2)$
## Ford fulkerson:
### Description:
>Ford Fulkerson for maximum flux in a weighthed graph
### Time Complexity:
>Main algorithm complexity: $O(MaxFlux*E)$

# Part Fourth
## Aproach
<div style="text-align: justify">

In this part we implement a __convex hull__ through the __Graham scanning algorithm__.
As input we take the coordinates that represent the contracting centers where customers can go, as a result of the algorithm we obtain the minimum polynomial that encompasses all the points.

<div>

# Algorithms Implemented:
## nextToTop
### Description:
>Function that returns the next value of the actual "top" from the stack

### Time complexity:
>Time Complexity: $O(1)$


## orientation_point
### Description:
>Function that calculates the orientation of the points

### Time complexity:
>Time Complexity: $O(1)$

# Algorithms Implemented:
## compute_orientation
### Description:
>Function that help us to determinate the type of oriantation.

### Time complexity:
>Time Complexity: $O(1)$

## distanceTwopoints
### Description:
>Function that calculates the distance between 2 points

### Time complexity:
>Time Complexity: $O(1)$

## swap
### Description:
>Function that swap the reference of two point values

### Time complexity:
>Time Complexity: $O(1)$

## compare
### Description:
>Auxiliary function that will help the quick sort algorithm to organize the points in ascending order, in order of angle (taking as reference the point most
close to "y").

>Since the program makes use of "point orientation", the order of hierarchy for
The decision of which goes first is:

    2 = Time Trial
    1 = Clockwise
    0 = Collinear

>If there is a point with the collinear case, then it will be arranged in order of which is closest to the closest point to the "y".

### Time complexity:
>Time Complexity: $O(1)$


## GrahamAlgorithm
### Description:
>This function implements the graham scan algorithm, roughly speaking the algorithm first finds the smallest point in "y".
Since we have identified our point, we organize by "angle".

>Here I make a parenthesis since our implementation does not use trigonometric functions, instead, the "orientation of the points" is used, having the smallest point in "y" as our pivot point to determine the orientation, the orientation that we are looking for specifically is "counterclockwise".
After organizing them, we eliminate those points that have repeated angles (collinear angles).

>Having already filtered our points, with the rest we will begin to unite them to create our convex hull (during the test we will discard those points that do not have a "counterclockwise" order).

### Time complexity:
>Time Complexity: $O(nLogn)$

# Disclaimers
For large number of cities to travel in the first graph in some point the letters of the alphabet are not enough and i start to run out of ascii characters so the output start to show extrange symbols but eventhough those symbols are different between each other
