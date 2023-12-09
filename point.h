#ifndef POINT_H
#define POINT_H

#include <ostream>

struct Point {
    int x = 0;
    int y = 0;
    int z = 0;

    Point() { ; }
    
    Point(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

#endif // POINT_H