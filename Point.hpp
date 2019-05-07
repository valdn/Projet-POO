#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

#include "ez-draw++.hpp"

typedef unsigned long ulong;
typedef unsigned int uint;

class Point {
    static const uint TAILLE = 3;
    uint x,y;

	public:
		Point();
        Point(uint _x, uint _y);
        Point(const Point &ori);
        Point(std::istream &is);
        ~Point();
        inline uint getX() const {return x;}
        inline uint getY() const {return y;}
        inline void setXY(uint _x, uint _y) {x=_x; y=_y;}
        bool isOver(uint _x, uint _y) const;
        void dessiner(EZWindow &fenetre, bool active = false) const;
        friend std::ostream & operator<<(std::ostream &os, const Point & p);
        friend std::istream & operator>>(std::istream &is, Point & p);
};

#endif