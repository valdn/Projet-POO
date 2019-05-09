#include "Ellipse.hpp"

void Ellipse::ecrire(std::ostream &os) const {
	os << "Ellipse ";
	Forme::ecrire(os);
	os << demiLargeur << ' ' << demiHauteur;
}

Ellipse::Ellipse(uint couleur, uint x, uint y, uint _demiLargeur, uint _demiHauteur) : Forme(couleur, _demiLargeur+x, _demiHauteur+y), demiLargeur(_demiLargeur), demiHauteur(_demiHauteur) {
	setFillColor(sf::Color::Color(getCouleur()));
	setOutlineColor(sf::Color::Color(getCouleur()));
	setPosition(0, 0);
	update();
}

Ellipse::Ellipse(const Ellipse & ori) : Ellipse(ori.getCouleur(), ori.getAncre().getX(), ori.getAncre().getY(), ori.demiLargeur, ori.demiHauteur) {}

Ellipse::Ellipse(std::istream &is) : Forme(is) {
	is >> demiLargeur;
	is >> demiHauteur;
}

Ellipse::~Ellipse() {}

void Ellipse::reload() {
	update();
}

//Faut pas oublier que l'ancre est au centre
bool Ellipse::isOver(uint _x, uint _y) const {
	return ((_x >= getAncre().getX() - demiLargeur) && (_x <= getAncre().getX() + demiLargeur) && (_y >= getAncre().getY() - demiHauteur) && (_y <= getAncre().getY() + demiHauteur));
}

std::size_t Ellipse::getPointCount() const {
	return 30; // fixé, mais ça pourrait tout aussi bien être un attribut de la classe
}

sf::Vector2f Ellipse::getPoint(std::size_t index) const {
	static const float pi = 3.141592654f;

	float angle = index * 2 * pi / getPointCount() - pi / 2;
	float x = std::cos(angle) * demiLargeur;
	float y = std::sin(angle) * demiHauteur;

	return sf::Vector2f(x + getAncre().getX(), y + getAncre().getY());
}
