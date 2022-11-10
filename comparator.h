#ifndef COMPARATOR_H
#define COMPARATOR_H

#include "edge.h"

class comparator{
    public:
        bool operator()(const edge& E, const edge& E2);
};

#endif