#include "CercleDrawable.hpp"

CercleD::CercleD(sf::Color couleur, uint x, uint y, uint rayon) 
	: Forme(couleur.toInteger(), rayon+x, rayon+y), 
		Cercle(couleur.toInteger(), rayon+x, rayon+y, rayon),
		FormeD(couleur.toInteger(), rayon+x, rayon+y) 
{
	setFillColor(sf::Color(getCouleur()));
	setOutlineColor(sf::Color(getCouleur()));
	update();
}

CercleD::CercleD(const CercleD & ori) : CercleD(sf::Color(ori.getCouleur()), ori.getAncre().getX(), ori.getAncre().getX(), ori.getRayon()) {}

CercleD::CercleD(std::istream & is) : Forme(is), Cercle(is), FormeD(is) {
	setFillColor(sf::Color(getCouleur()));
	setOutlineColor(sf::Color(getCouleur()));
	update();
}

CercleD::~CercleD() {}

//Faut pas oublier que l'ancre est au centre
bool CercleD::isOver(uint _x, uint _y) const {
	return ((_x >= getAncre().getX() - getRayon()) && (_x <= getAncre().getX() + getRayon()) && (_y >= getAncre().getY() - getRayon()) && (_y <= getAncre().getY() + getRayon()));
}

void CercleD::dessiner(sf::RenderWindow & window) const {
	window.draw(*this);
}

inline void CercleD::maj() {
	update();
}

std::size_t CercleD::getPointCount() const {
	return 30;	//Fixé mais pas obligé. Retourne 30 points qui vont définir la forme
}

sf::Vector2f CercleD::getPoint(std::size_t index) const {
	float angle = index * 2 * M_PI / getPointCount() - M_PI / 2;
	float x = std::cos(angle) * getRayon();
	float y = std::sin(angle) * getRayon();

	return sf::Vector2f(x + getAncre().getX(), y + getAncre().getY());
}