#include "EllipseDrawable.hpp"

void EllipseD::ecrire(std::ostream & os) const {
	os << "EllipseD ";
	FormeD::ecrire(os);
	os << getDemiLargeur() << ' ' << getDemiHauteur();
}

EllipseD::EllipseD(sf::Color couleur, int x, int y, uint largeur, uint hauteur)
	: Forme(couleur.toInteger(), x, y),
		Ellipse(couleur.toInteger(), x, y, largeur/2, hauteur/2),
		FormeD(couleur, x, y)
{	
	setFillColor(sf::Color(getCouleur()));
	setOutlineThickness(getBorder());
	setOutlineColor(sf::Color(getCouleur()));
	recalculate();
}

EllipseD::EllipseD(const EllipseD & ori) : EllipseD(sf::Color(ori.getCouleur()), ori.getAncre().getX(), ori.getAncre().getX(), ori.getDemiHauteur(), ori.getDemiLargeur()) {}

EllipseD::EllipseD(std::istream & is) : Forme(is), FormeD(is), Ellipse(is) {
	if (isPleine()) setFillColor(sf::Color(getCouleur()));
	else setFillColor(sf::Color::Transparent);
	setOutlineThickness(getBorder());
	setOutlineColor(sf::Color(getCouleur()));
	recalculate();
}

EllipseD::~EllipseD() {}

//Faut pas oublier que l'ancre est au centre
bool EllipseD::isOver(int _x, int _y) const {
	return (getAncreD().isOver(_x, _y) || (std::pow(((double)_x - (double)(getAncre().getX()+ (int)getDemiLargeur())) / (int)getDemiLargeur(), 2) + std::pow(((double)_y - (double)(getAncre().getY()+ (int)getDemiHauteur())) / (int)getDemiHauteur(), 2) < 1));
}

void EllipseD::dessiner(sf::RenderWindow & window) const {
	window.draw(*this);
	getAncreD().dessiner(window);
}

inline void EllipseD::maj() {
	FormeD::maj();
	recalculate();
}

void EllipseD::recalculate() {
	Shape::update();
}

std::size_t EllipseD::getPointCount() const {
	return 30;	//Fixé mais pas obligé. Retourne 30 points qui vont définir la forme
}

sf::Vector2f EllipseD::getPoint(std::size_t index) const {
	float angle = index * 2 * M_PI / getPointCount() - M_PI / 2;
	float x = std::cos(angle) * getDemiLargeur();
	float y = std::sin(angle) * getDemiHauteur();

	return sf::Vector2f(x + getAncre().getX() + getDemiLargeur(), y + getAncre().getY()+ getDemiHauteur());
}
