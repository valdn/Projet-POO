#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <vector>

typedef unsigned int uint;
//les coordonée d'un point sont entière car il est possible d'avoir des point avec des coordonnées négatives

namespace fm {

class Point {
  static const uint TAILLE = 3;
	static std::vector<Point*> tab_points;
	size_t id;
  int x,y;

	public:
    Point(int _x, int _y);
    Point(const Point &ori);
    Point(std::istream &is);
    ~Point();
    inline uint getTaille() const {return TAILLE;}
    inline int getX() const {return x;}
    inline int getY() const {return y;}
		inline size_t getId() const {return id;}
    inline void setX(int _x) {x = _x;}
    inline void setY(int _y) {y = _y;}
    inline void setXY(int _x, int _y) {x=_x; y=_y;}
    friend std::ostream & operator<<(std::ostream &os, const Point & p);
    friend std::istream & operator>>(std::istream &is, Point & p);

		static Point* getPointAt(size_t index) { return tab_points.at(index); }

	private:
		static size_t getPointIndex(Point * point);
};

}//namespace

#endif POINT_HPP