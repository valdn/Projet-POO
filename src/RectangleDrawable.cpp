#include "RectangleDrawable.hpp"

RectangleD::RectangleD(sf::Color couleur, int x, int y, uint largeur, uint hauteur)
	: Forme(couleur.toInteger(), x, y),
		Rectangle(couleur.toInteger(), x, y, largeur, hauteur), 
		FormeD(couleur, x, y) 
{
	setFillColor(sf::Color(getCouleur()));
	setOutlineThickness(-1);
	setOutlineColor(sf::Color(getCouleur()));
	recalculate();
}

RectangleD::RectangleD(const RectangleD & ori) : RectangleD(sf::Color(ori.Rectangle::getCouleur()), ori.Rectangle::getAncre().getX(), ori.Rectangle::getAncre().getX(), ori.getLargeur(), ori.getHauteur()) {}

RectangleD::RectangleD(std::istream & is) : Forme(is), Rectangle(is), FormeD(is) {
	setFillColor(sf::Color(getCouleur()));
	setOutlineColor(sf::Color(getCouleur()));
	recalculate();
}

RectangleD::~RectangleD() {}

bool RectangleD::isOver(int _x, int _y) const {
	return ( getAncreD().isOver(_x,_y) || ((_x >= getAncre().getX()) && (_x <= getAncre().getX() + getLargeur()) && (_y >= getAncre().getY()) && (_y <= getAncre().getY() + getHauteur())));
}

void RectangleD::dessiner(sf::RenderWindow & window) const {
	window.draw(*this);
	getAncreD().dessiner(window);
}

inline void RectangleD::maj() {
	FormeD::maj();
	recalculate();
}

void RectangleD::recalculate() {
	Shape::update();
}

std::size_t RectangleD::getPointCount() const {
	return 4;	//Y'a 4 coin dans un carré
}

sf::Vector2f RectangleD::getPoint(std::size_t index) const {
	float x = getAncre().getX();
	float y = getAncre().getY();
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
