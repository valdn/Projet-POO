#include "FormeDrawable.hpp"
#include "RectangleDrawable.hpp"
#include "CarreDrawable.hpp"
#include "EllipseDrawable.hpp"
#include "CercleDrawable.hpp"
#include "TriangleDrawable.hpp"
#include "PolygoneDrawable.hpp"
#include "ImageDrawable.hpp"

void FormeD::ecrire(std::ostream & os) const {
	Forme::ecrire(os);
	os << pleine << ' ' << getOutlineThickness() << ' ';
}

FormeD::FormeD(sf::Color couleur, int x, int y) : Forme(couleur.toInteger(),x,y), pleine(true), border(-1), ancreD(getAncrePtr(), sf::Color::Magenta) {}

FormeD::FormeD(const FormeD & ori) : FormeD(sf::Color(ori.getCouleur()), ori.getAncre().getX(), ori.getAncre().getY()) {}

FormeD::FormeD(std::istream & is) : Forme(is), ancreD(getAncrePtr(), sf::Color::Magenta) {
	is >> pleine;
	is >> border;
}

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
	if (type == "RectangleD") return new RectangleD(is);
	else if (type == "CarreD") return new CarreD(is);
	else if (type == "EllipseD") return new EllipseD(is);
	else if (type == "CercleD") return new CercleD(is);
	else if (type == "TriangleD") return new TriangleD(is);
	else if (type == "PolygoneD") return new PolygoneD(is);
	else if (type == "ImageD") return new ImageD(is);

	throw std::range_error("La forme \"" + type + "\" n'existe pas");
}
