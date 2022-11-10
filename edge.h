#ifndef EDGE_H
#define EDGE_H

#include <iostream>

class edge{
    public:
        unsigned int src = 0;
        unsigned int dest = 0;
        unsigned int weight = 0;
        //Constructors
        edge() = default;
        edge(unsigned int _src, unsigned int _dest, unsigned int _weight): src(_src), dest(_dest), weight(_weight){}
        //Functions
        friend std::ostream& operator<<(std::ostream& os, const edge& E){
            os<<E.src<<","<<E.dest<<"||"<<E.weight<<std::endl;
        }
        void reset(){edge();}
        void set(const unsigned int& _src, const unsigned int& _dest, const unsigned int& _weight);
};

#endif