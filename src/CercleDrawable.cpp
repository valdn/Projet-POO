#include "CercleDrawable.hpp"

CercleD::CercleD(sf::Color couleur, uint x, uint y, uint rayon) 
	: Forme(couleur.toInteger(), x, y), 
		Cercle(couleur.toInteger(), x, y, rayon),
		FormeD(couleur, x, y) 
{
	setFillColor(sf::Color(getCouleur()));
	setOutlineThickness(-1);
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
	//retourne vrai si la distance entre le centre du cerlce et la souris est inférieur au rayon
	return (std::sqrt(std::pow((double)_x - (double)(getAncre().getX() + getRayon()), 2) + std::pow((double)_y - (double)(getAncre().getY() + getRayon()), 2)) <= getRayon());
}

void CercleD::dessiner(sf::RenderWindow & window) const {
	window.draw(*this);
	this->dessinerAncre(window);
}

inline void CercleD::maj() {
	this->updateAncre();
	update();
}

std::size_t CercleD::getPointCount() const {
	return 30;	//Fixé mais pas obligé. Retourne 30 points qui vont définir la forme
}

sf::Vector2f CercleD::getPoint(std::size_t index) const {
	float angle = index * 2 * M_PI / getPointCount() - M_PI / 2;
	float x = std::cos(angle) * getRayon();
	float y = std::sin(angle) * getRayon();

	return sf::Vector2f(getRayon() + getAncre().getX() + x, getRayon() + getAncre().getY() + y);
}