#ifndef POINT_H
#define POINT_H

class point{
    public:
        int x = 0;
        int y = 0;
        //Default Constructor
        point() = default;
        //Overloaded constructor
        point(int x, int y): x(x), y(y){}
        void operator=(const point& B){this->x=B.x;this->y=B.y;}
        bool operator==(const point& B){return (this->x==B.x && this->y==B.y);}
        void reset(){point();}
};

#endif