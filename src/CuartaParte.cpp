#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stack>
#include "../headers/point.h"
using namespace std;

/*
    Global variable of point type that will help us to save the point with the short "y"
    (And the short "x" if the case is required)
*/
point mostBottonpoint; 

/*
    Function that returns the next value of the actual "top" from the stack

    Computational complexity: O(1)

    Input:
        S = A stack of points.

    Output:
        The next point of the actual "top" of the stack 
*/
point nextToTop(stack<point> &S) {
    point p = S.top();
    S.pop();
    point res = S.top();
    S.push(p);
    return res;
}
 

/*
    Function that calculates the orientation of the points

    Computational complexity: O(1)

    Input:
        p0 = Value of class point
        p1 = Value of class point
        p2 = Value of class point

    Output:
        Returns the orientation of the point
*/
int orientation_point(point p0, point p1, point p2){
    return ((p1.y - p0.y) * (p2.x - p1.x)) - ((p2.y - p1.y) * (p1.x - p0.x));
}


/*
    Function that help us to determinate the type of oriantation.
    
    Computational complexity: O(1)
    Input:
        p0 = Value of class point
        p1 = Value of class point
        p2 = Value of class point

    Output:
        Returns the orientation of the point.
*/
int compute_orientation(point p0, point p1, point p2){
    int determinant = orientation_point(p0, p1, p2);
    
    if(determinant < 0) 
        return 2; // Counterclock
    else if(determinant > 0)    
        return 1; // Clock
    else
        return 0; // Collinear
}


/*
    Function that calculates the distance between 2 points

    Computational complexity: O(1)
    Input:
        p1 = Value of class point
        p2 = Value of class point

    Output:
        Returns the distance between 2 points.
*/
int distanceTwopoints(point p1, point p2){
    return pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2);
}

/*
    Function that swap the reference of two point values

    Computational complexity: O(1)
    
    Input:
        p0 = Reference of one variable of type point
        p1 = Reference of one variable of type point

    Output:
        Swap the reference of 2 variables.
*/
void swap(point* p0, point* p1){
    point* holdpoint = p0;
    p0 = p1;
    p1 = holdpoint;
}

/*
    Auxiliary function that will help the quick sort algorithm to organize the
    points in ascending order, in order of angle (taking as reference the point most
    close to "y").

    Since the program makes use of "point orientation", the order of hierarchy for
    The decision of which goes first is:
    2 = Time Trial
    1 = Clockwise
    0 = Collinear

    If there is a point with the collinear case, then it will be arranged in order of which is closest to the
    closest point to the "y".

    Input:
        vp1 = Reference of type void (first point)
        vp2 = Reference of type void (second point)

    Output:
        Returns the point with the largest angle
*/
int compare(const void *vp1, const void *vp2){
    point *p1 = (point *)vp1;
    point *p2 = (point *)vp2;

    int orientation = compute_orientation(mostBottonpoint, *p1, *p2);

    if(orientation == 0)
        return (distanceTwopoints(mostBottonpoint, *p1) < distanceTwopoints(mostBottonpoint, *p2))? -1:1;

    return (orientation == 2)? -1:1;
}

/*
    Function that implements Graham's scan algorithm.


    Input:
        - vector<point> vect = Vector with all the point that of the set
        
    Output:
        Returns a vector with all the points that compound the the convex hull.
*/
void GrahamAlgorithm(vector<point>& vect){

    int indexMostBottonpoint = 0;
    vector<point> vectFiltered;
    stack<point> S;
    vector<point> vectSolution;
 
    //Find the leftmost point "y"
    for(int i = 0; i < vect.size(); i++){
        if(vect[i].y < vect[indexMostBottonpoint].y){
            indexMostBottonpoint = i;
        } else if(vect[indexMostBottonpoint].y == vect[i].y){
            //In case of 2 points with equal "y", the we going to take the shorter point in "x"
            if(vect[i].x < vect[indexMostBottonpoint].x){
                indexMostBottonpoint = i;
            }
        }
    } 

    //Save the leftmost point
    mostBottonpoint.x = vect[indexMostBottonpoint].x;
    mostBottonpoint.y = vect[indexMostBottonpoint].y;

    //Put in first place of the vector the leftmost point
    swap(vect[0], vect[indexMostBottonpoint]);

    /*  
        Sort the points by angle, in our case, it sorts by Counterclock taking as reference
        the leftmost point
    */
    int size = vect.size() - 1;
    qsort(&vect[1], size, sizeof(point), compare);

    //Delete those points that have the same angle as another point
    vectFiltered.push_back(vect[0]);
    for(int i = 1; i < size; i++){
        if(orientation_point(mostBottonpoint, vect[i], vect[i+1]) != 0){
            vectFiltered.push_back(vect[i]);
        }
    }

    vectFiltered.push_back(vect[size]); //Push back the farthes point

    if(vectFiltered.size() < 3) cout<< "The polygon can't be made"<<endl;
    

    //We save the three initial points that make up the stack
    S.push(vectFiltered[0]);
    S.push(vectFiltered[1]);
    S.push(vectFiltered[2]);

    //We determine the points that will belong to the convex polygon
    for(int i = 3; i < vectFiltered.size(); i++){
        while(S.size() > 1 && compute_orientation(nextToTop(S), S.top(), vectFiltered[i]) != 2)
            S.pop();

        S.push(vectFiltered[i]);
    }


    while(!S.empty()){
        point solutionpoint = S.top();
        vectSolution.push_back(solutionpoint);
        S.pop();
    }

    //Print solution convex hull
    for(int i=0; i < vectSolution.size(); i++){
       cout << "(" << vectSolution[i].x << ", " << vectSolution[i].y <<")" << endl;  
    }
}

