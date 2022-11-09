#ifndef EDGE_H
#define EDGE_H

class edge{
    public:
        unsigned int src = 0;
        unsigned int dest = 0;
        unsigned int weight = 0;
        //Constructors
        edge() = default;
        edge(unsigned int _src, unsigned int _dest, unsigned int _weight): src(_src), dest(_dest), weight(_weight){}
        //Functions
        
};

#endif