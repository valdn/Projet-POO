#include "PolygoneDrawable.hpp"

void PolygoneD::ecrire(std::ostream & os) const {
	os << "PolygoneD ";
	FormeD::ecrire(os);
	os << tabPointD.size();
	for (size_t i = 0; i < tabPointD.size(); ++i)
		os << ' ' << tabPointD[i]->getId();
}

PolygoneD::PolygoneD(sf::Color couleur, int x1, int y1, std::vector<PointD*> & _tabPointD)
	: Forme(couleur.toInteger(), x1, y1),
		Polygone(couleur.toInteger(), x1, y1, nullptr),
		FormeD(couleur, x1, y1),
		tabPointD(_tabPointD)
{
	if (tabPointD.empty()) throw "il n'y a aucun points";

	std::vector<fm::Point*>* tabPoint = new std::vector<fm::Point*>;

	for (size_t i = 0; i < tabPointD.size(); i++) {
		tabPoint->push_back(tabPointD[i]->getPtrPoint());
		tabDistance.push_back(getDistance(getAncre(), tabPointD[i]->getPoint()));
	}
	setTabPoint(tabPoint);

	setFillColor(sf::Color(getCouleur()));
	setOutlineThickness(getBorder());
	setOutlineColor(sf::Color(getCouleur()));
	recalculate();
}

//PolygoneD::PolygoneD(const PolygoneD & ori) : PolygoneD(sf::Color(ori.getCouleur()), getAncre().getX(), getAncre().getY(), ori.tabPointD) {}

PolygoneD::PolygoneD(std::istream & is) : Forme(is), FormeD(is), Polygone(is) {

	for (size_t i = 0; i < getNbPoints(); ++i) {
		tabPointD.push_back(PointD::getPointD(getPointAt(i)));
		tabDistance.push_back(getDistance(getAncre(), tabPointD[i]->getPoint()));
	}

	if (isPleine()) setFillColor(sf::Color(getCouleur()));
	else setFillColor(sf::Color::Transparent);
	setOutlineThickness(getBorder());
	setOutlineColor(sf::Color(getCouleur()));
	recalculate();
}

PolygoneD::~PolygoneD() {}

//TODO
bool PolygoneD::isOver(int x, int y) const {
	return (getAncreD().isOver(x,y));
}

void PolygoneD::dessiner(sf::RenderWindow & window) const {
	window.draw(*this);
	getAncreD().dessiner(window);
	for (size_t i = 0; i < tabPointD.size(); i++) {
		tabPointD[i]->dessiner(window);
	}
}

void PolygoneD::maj() {
	FormeD::maj();
	for (size_t i = 0; i < tabPointD.size(); i++) {
		tabPointD[i]->setPos(getAncre().getX() + tabDistance.at(i).x, getAncre().getY() + tabDistance.at(i).y);
		tabPointD[i]->update();
	}
	recalculate();
}

void PolygoneD::recalculate() {
	for (size_t i = 0; i < tabPointD.size(); i++) {
		tabDistance.at(i) = (getDistance(getAncre(), tabPointD[i]->getPoint()));
	}
	Shape::update();
}

std::size_t PolygoneD::getPointCount() const {
	return tabPointD.size() + 1;	//Tous les sommet du tableau plus l'ancre
}

sf::Vector2f PolygoneD::getPoint(std::size_t index) const {
	switch (index) {
		case 0: 
			return sf::Vector2f(getAncre().getX(), getAncre().getY());	//Premier point, ancre
			break;
		default:
			return sf::Vector2f(tabPointD[index - 1]->getX(), tabPointD[index - 1]->getY());
			break;
	}
}