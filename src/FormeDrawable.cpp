#include "FormeDrawable.hpp"
#include "RectangleDrawable.hpp"
#include "CarreDrawable.hpp"
#include "EllipseDrawable.hpp"
#include "CercleDrawable.hpp"

FormeD::FormeD(sf::Color couleur, uint x, uint y) : Forme(couleur.toInteger(),x,y), pleine(true), ancreD(getAncreMem()) {}

FormeD::FormeD(const FormeD & ori) : FormeD(sf::Color(ori.getCouleur()), ori.getAncre().getX(), ori.getAncre().getY()) {}

FormeD::FormeD(std::istream & is) : Forme(is), ancreD(getAncreMem()) {}

FormeD::~FormeD() {}

void FormeD::maj() {
	ancreD.update();
}

FormeD * FormeD::charger(std::istream & is) {
	std::string type;
	is >> type;
	std::cout << "type : " << type << std::endl;
	if (type == "Rectangle") return new RectangleD(is);
	else if (type == "Carre") return new CarreD(is);
	else if (type == "Ellipse") return new EllipseD(is);
	else if (type == "Cercle") return new CercleD(is);

	throw std::range_error("Cette forme n'existe pas");
}
