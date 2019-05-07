#include "Point.hpp"

Point::Point() : x(NULL), y(NULL) {}

Point::Point(uint _x, uint _y) : x(_x), y(_y) {}

Point::Point(const Point &ori) : Point(ori.x, ori.y) {}

Point::Point(std::istream &is) {
	is >> x;
	is >> y;
}

Point::~Point() {

}

bool Point::isOver(uint _x, uint _y) const {
	return ((_x >= x - TAILLE) && (_x <= x + TAILLE) && (_y >= y - TAILLE) && (_y <= y + TAILLE));
}

void Point::dessiner(EZWindow &fenetre, bool active) const {
	fenetre.setColor(ez_black);
	fenetre.setThick(TAILLE);
	fenetre.drawPoint(getX(), getY());
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
