#include "Forme/Point.hpp"

namespace fm {

Point::Point(int _x, int _y) : x(_x), y(_y) {}

Point::Point(const Point &ori) : Point(ori.x, ori.y) {}

Point::Point(std::istream &is) {
	is >> x;
	is >> y;
}

Point::~Point() {

}

std::ostream & operator<<(std::ostream &os, const Point & p) {
	os << p.getX() << ' ' << p.getY();
	return os;
}

std::istream & operator>>(std::istream &is, Point & p) {
	uint x, y;
	is >> x;
	is >> y;
	p.setXY(x, y);
	return is;
}

}//namespace
