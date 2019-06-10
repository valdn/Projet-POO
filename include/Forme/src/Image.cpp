#include "Forme/Image.hpp"

namespace fm {

void Image::ecrire(std::ostream &os) const {
	os << "Image ";
	Forme::ecrire(os);
	os << p1->getId() << ' ' << img;
}

Image::Image(std::string _img, int x, int y, Point * _p1) : Forme(0, x, y), p1(_p1), img(_img), activeRatio(true) {}

Image::Image(const Image & ori) : Image(ori.getImg(), ori.getAncre().getX(), ori.getAncre().getY(), &Point(ori.getP1())) {}

Image::Image(std::istream &is) : Forme(is) {
	size_t id_p1;

	is >> id_p1;
	is >> img;

	p1 = Point::getPointByID(id_p1);
}

Image::~Image() {}

}//namespace
