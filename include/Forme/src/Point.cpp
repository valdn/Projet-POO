#include "Forme/Point.hpp"

namespace fm {

std::vector<Point*> Point::tab_points = std::vector<Point*>();

Point::Point(int _x, int _y) : x(_x), y(_y) {
	id = tab_points.size();
	tab_points.push_back(this);
}

Point::Point(const Point &ori) : Point(ori.x, ori.y) {}

Point::Point(std::istream &is) {
	is >> x;
	is >> y;
	is >> id;

	tab_points.push_back(this);
}

 Point::~Point() {
	try {
		tab_points.erase(tab_points.begin() + getPointIndex(this));
	}
	catch (std::domain_error & e) {
		std::cerr << e.what() << std::endl;
	}
}

Point * Point::getPointByID(size_t id) {
	for (size_t i = 0; i < tab_points.size(); ++i) {
		if (tab_points[i]->id == id) return tab_points[i];
	}
	throw std::out_of_range("Aucun point ne poss�de l'Id : " + std::to_string(id));
}

 size_t Point::getPointIndex(Point * point) {
	for (size_t i = 0; tab_points.size(); ++i) {
		if (tab_points[i] == point) return i;
	}

	throw std::domain_error("Le point n'existe pas");
}

std::ostream & operator<<(std::ostream &os, const Point & p) {
	os << p.getX() << ' ' << p.getY() << ' ' << p.getId();
	return os;
}

std::istream & operator>>(std::istream &is, Point & p) {
	is >> p.x;
	is >> p.y;
	is >> p.id;

	return is;
}

}//namespace
