#include "RectangleDrawable.hpp"

RectangleD::RectangleD(sf::Color couleur, uint x, uint y, uint largeur, uint hauteur)
	: Forme(couleur.toInteger(), x, y),
		Rectangle(couleur.toInteger(), x, y, largeur, hauteur), 
		FormeD(couleur, x, y) 
{
	setFillColor(sf::Color(getCouleur()));
	setOutlineThickness(-1);
	setOutlineColor(sf::Color(getCouleur()));
	update();
}

RectangleD::RectangleD(const RectangleD & ori) : RectangleD(sf::Color(ori.Rectangle::getCouleur()), ori.Rectangle::getAncre().getX(), ori.Rectangle::getAncre().getX(), ori.getLargeur(), ori.getHauteur()) {}

RectangleD::RectangleD(std::istream & is) : Forme(is), Rectangle(is), FormeD(is) {
	setFillColor(sf::Color(getCouleur()));
	setOutlineColor(sf::Color(getCouleur()));
	update();
}

RectangleD::~RectangleD() {}

bool RectangleD::isOver(uint _x, uint _y) const {
	return ((_x >= getAncre().getX()) && (_x <= getAncre().getX() + getLargeur()) && (_y >= getAncre().getY()) && (_y <= getAncre().getY() + getHauteur()));
}

void RectangleD::dessiner(sf::RenderWindow & window) const {
	window.draw(*this);
	this->dessinerAncre(window);
}

inline void RectangleD::maj() {
	this->updateAncre();
	update();
}

std::size_t RectangleD::getPointCount() const {
	return 4;	//Y'a 4 coin dans un carré
}

sf::Vector2f RectangleD::getPoint(std::size_t index) const {
	float x = Rectangle::getAncre().getX();
	float y = Rectangle::getAncre().getY();
	float largeur = float(getLargeur());
	float hauteur = float(getHauteur());

	switch (index) {
	default:	//pour eviter le warning
	case 0: return sf::Vector2f(x, y);	//Premier point ancre coin supérieur gauche
	case 1: return sf::Vector2f(largeur + x, y);	//coin supérieur droit
	case 2: return sf::Vector2f(largeur + x, y + hauteur);	//coin inférieur droit
	case 3: return sf::Vector2f(x, y + hauteur);	//coin inférieur gauche
	}
}
