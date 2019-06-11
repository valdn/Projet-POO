#include "FormeDrawable.hpp"
#include "RectangleDrawable.hpp"
#include "CarreDrawable.hpp"
#include "EllipseDrawable.hpp"
#include "CercleDrawable.hpp"
#include "TriangleDrawable.hpp"
#include "PolygoneDrawable.hpp"
#include "ImageDrawable.hpp"

FormeD::FormeD(sf::Color couleur, int x, int y) : Forme(couleur.toInteger(),x,y), pleine(true), ancreD(getAncrePtr(), sf::Color::Magenta) {}

FormeD::FormeD(const FormeD & ori) : FormeD(sf::Color(ori.getCouleur()), ori.getAncre().getX(), ori.getAncre().getY()) {}

FormeD::FormeD(std::istream & is) : Forme(is), ancreD(getAncrePtr(), sf::Color::Magenta) {}

FormeD::~FormeD() {}

void FormeD::maj() {
	ancreD.update();
}

sf::Vector2f FormeD::getDistance(const fm::Point & p1, const fm::Point & p2) {
	return sf::Vector2f((p2.getX() - p1.getX()), (p2.getY() - p1.getY()));
}

FormeD * FormeD::charger(std::istream & is) {
	std::string type;
	is >> type;
	if (type == "Rectangle") return new RectangleD(is);
	else if (type == "Carre") return new CarreD(is);
	else if (type == "Ellipse") return new EllipseD(is);
	else if (type == "Cercle") return new CercleD(is);
	else if (type == "Triangle") return new TriangleD(is);
	else if (type == "Polygone") return new PolygoneD(is);
	else if (type == "Image") return new ImageD(is);

	throw std::range_error("La forme \"" + type + "\" n'existe pas");
}
