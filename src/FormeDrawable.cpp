#include "FormeDrawable.hpp"
#include "RectangleDrawable.hpp"
#include "CarreDrawable.hpp"
#include "EllipseDrawable.hpp"
#include "CercleDrawable.hpp"

void FormeD::dessinerAncre(sf::RenderWindow & window) const {
	window.draw(ancreD);
}

void FormeD::updateAncre() {
	ancreD.setPosition(getAncre().getX(), getAncre().getY());
}

FormeD::FormeD(sf::Color couleur, uint x, uint y) : Forme(couleur.toInteger(),x,y), pleine(true) {
	ancreD.setFillColor(sf::Color::Black);
	ancreD.setRadius(getAncre().getTaille());
	ancreD.setOrigin(ancreD.getRadius(), ancreD.getRadius());
	std::cout << ancreD.getOrigin().x << " " << ancreD.getOrigin().y << std::endl;
	updateAncre();
}

FormeD::FormeD(const FormeD & ori) : FormeD(sf::Color(ori.getCouleur()), ori.getAncre().getX(), ori.getAncre().getY()) {}

FormeD::FormeD(std::istream & is) : Forme(is) {}

FormeD::~FormeD() {}

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
