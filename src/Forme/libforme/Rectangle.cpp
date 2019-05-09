#include "Rectangle.hpp"

void Rectangle::ecrire(std::ostream &os) const {
	os << "Rectangle ";
	Forme::ecrire(os);
	os << largeur << ' ' << hauteur;
}

Rectangle::Rectangle(uint couleur, uint x, uint y, uint _largeur, uint _hauteur) : Forme(couleur, x, y), largeur(_largeur), hauteur(_hauteur) {
	setFillColor(sf::Color::Color(getCouleur()));
	setOutlineColor(sf::Color::Color(getCouleur()));
	setPosition(0, 0);
	update();
}

Rectangle::Rectangle(const Rectangle & ori) : Rectangle(ori.getCouleur(), ori.getAncre().getX(), ori.getAncre().getY(), ori.largeur, ori.hauteur) {}

Rectangle::Rectangle(std::istream &is) : Forme(is) {
	is >> largeur;
	is >> hauteur;
}

Rectangle::~Rectangle() {}

void Rectangle::reload() {
	update();
}

bool Rectangle::isOver(uint _x, uint _y) const {
	return ((_x >= getAncre().getX()) && (_x <= getAncre().getX() + largeur) && (_y >= getAncre().getY()) && (_y <= getAncre().getY() + hauteur));
}

std::size_t Rectangle::getPointCount() const {
	return 4; //Obligaotirement 4 points (les 4 sommets) pour un rectangle 
}

sf::Vector2f Rectangle::getPoint(std::size_t index) const {
	float x = getAncre().getX();
	float y = getAncre().getY();
	float largeurf = float(largeur);
	float hauteurf = float(hauteur);

	switch (index) {
	default:
	case 0: return sf::Vector2f(x, y);	//Premier point ancre coin supérieur gauche
	case 1: return sf::Vector2f(largeurf + x, y);	//coin supérieur droit
	case 2: return sf::Vector2f(largeurf + x, y + hauteur);	//coin inférieur droit
	case 3: return sf::Vector2f(x, y + hauteurf);	//coin inférieur gauche
	}
}
