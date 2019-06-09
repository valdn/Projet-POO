#include "Forme/Point.hpp"

namespace fm {

std::vector<Point*> Point::tab_points = std::vector<Point*>();

Point::Point(int _x, int _y) : x(_x), y(_y) {
	tab_points.push_back(this);
	id = tab_points.size();
}

Point::Point(const Point &ori) : Point(ori.x, ori.y) {}

Point::Point(std::istream &is) {
	is >> x;
	is >> y;

	tab_points.push_back(this);
	id = tab_points.size();
}

Point::~Point() {
	try {
		tab_points.erase(tab_points.begin() + getPointIndex(this));
	}
	catch (std::domain_error & e) {
		std::cerr << e.what() << std::endl;
	}

	for (size_t i = 0; i < tab_points.size(); ++i) {	//Re organise les id des points
		tab_points[i]->id = i;
	}
}

size_t Point::getPointIndex(Point * point) {
	for (size_t i = 0; tab_points.size(); ++i) {
		if (tab_points[i] == point) return i;
	}

	throw std::domain_error("Le point n'existe pas");
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
