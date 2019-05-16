#include "CarreDrawable.hpp"

CarreD::CarreD(sf::Color couleur, int x, int y, uint cote) 
	: Forme(couleur.toInteger(), x, y), 
		Carre(couleur.toInteger(), x, y, cote),
		FormeD(couleur, x, y) 
{
	setFillColor(sf::Color(getCouleur()));
	setOutlineThickness(-1);
	setOutlineColor(sf::Color(getCouleur()));
	recalculate();
}

CarreD::CarreD(const Carre & ori) : CarreD(sf::Color(ori.getCouleur()), ori.getAncre().getX(), ori.getAncre().getX(), ori.getCote()) {}

CarreD::CarreD(std::istream & is) : Forme(is), Carre(is), FormeD(is) {
	setFillColor(sf::Color(getCouleur()));
	setOutlineThickness(-1);
	setOutlineColor(sf::Color(getCouleur()));
	recalculate();
}

CarreD::~CarreD() {}

bool CarreD::isOver(int _x, int _y) const {
	return (getAncreD().isOver(_x, _y) || ((_x >= getAncre().getX()) && (_x <= getAncre().getX() + getCote()) && (_y >= getAncre().getY()) && (_y <= getAncre().getY() + getCote())));
}

void CarreD::dessiner(sf::RenderWindow & window) const {
	window.draw(*this);
	getAncreD().dessiner(window);
}

inline void CarreD::maj() {
	FormeD::maj();
	recalculate();
}

void CarreD::recalculate() {
	Shape::update();
}

std::size_t CarreD::getPointCount() const {
	return 4;	//Y'a 4 coin dans un carré
}

sf::Vector2f CarreD::getPoint(std::size_t index) const {
	float x = getAncre().getX();
	float y = getAncre().getY();
	float cote = float(getCote());

	switch (index) {
	default:	//pour eviter le warning
	case 0: return sf::Vector2f(x, y);	//Premier point ancre coin supérieur gauche
	case 1: return sf::Vector2f(cote + x, y);	//coin supérieur droit
	case 2: return sf::Vector2f(cote + x, y + cote);	//coin inférieur droit
	case 3: return sf::Vector2f(x, y + cote);	//coin inférieur gauche
	}
}
