#include "CercleDrawable.hpp"

CercleD::CercleD(sf::Color couleur, int x, int y, uint rayon) 
	: Forme(couleur.toInteger(), x, y), 
		Cercle(couleur.toInteger(), x, y, rayon),
		FormeD(couleur, x, y) 
{
	setFillColor(sf::Color(getCouleur()));
	setOutlineThickness(-1);
	setOutlineColor(sf::Color(getCouleur()));
	recalculate();
}

CercleD::CercleD(const CercleD & ori) : CercleD(sf::Color(ori.getCouleur()), ori.getAncre().getX(), ori.getAncre().getX(), ori.getRayon()) {}

CercleD::CercleD(std::istream & is) : Forme(is), Cercle(is), FormeD(is) {
	setFillColor(sf::Color(getCouleur()));
	setOutlineColor(sf::Color(getCouleur()));
	recalculate();
}

CercleD::~CercleD() {}

//Faut pas oublier que l'ancre est au centre
bool CercleD::isOver(int _x, int _y) const {
	//retourne vrai si la distance entre le centre du cerlce et la souris est inf�rieur au rayon
	return (getAncreD().isOver(_x, _y) || ((std::pow((double)_x - (getAncre().getX() + (int)getRayon()), 2) + std::pow((double)_y - (getAncre().getY() + (int)getRayon()), 2)) <= std::pow((int)getRayon(),2)));
}

void CercleD::dessiner(sf::RenderWindow & window) const {
	window.draw(*this);
	getAncreD().dessiner(window);
}

inline void CercleD::maj() {
	FormeD::maj();
	recalculate();
}

void CercleD::recalculate() {
	Shape::update();
}

std::size_t CercleD::getPointCount() const {
	return 30;	//Fixé mais pas obligé. Retourne 30 points qui vont définir la forme
}

sf::Vector2f CercleD::getPoint(std::size_t index) const {
	float angle = index * 2 * M_PI / getPointCount() - M_PI / 2;
	float x = std::cos(angle) * getRayon();
	float y = std::sin(angle) * getRayon();

	return sf::Vector2f(x + getAncre().getX() + getRayon(), y + getAncre().getY() + getRayon());
}