#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

typedef unsigned int uint;

namespace fm {

class Point {
    static const uint TAILLE = 3;
    uint x,y;

	public:
		Point();
    Point(uint _x, uint _y);
    Point(const Point &ori);
    Point(std::istream &is);
    ~Point();
    inline uint getTaille() const {return TAILLE;}
    inline uint getX() const {return x;}
    inline uint getY() const {return y;}
    inline void setX(uint _x) {x = _x;}
    inline void setY(uint _y) {y = _y;}
    inline void setXY(uint _x, uint _y) {x=_x; y=_y;}
    bool isOver(uint _x, uint _y) const;
    friend std::ostream & operator<<(std::ostream &os, const Point & p);
    friend std::istream & operator>>(std::istream &is, Point & p);
};

}//namespace

#endif POINT_HPP