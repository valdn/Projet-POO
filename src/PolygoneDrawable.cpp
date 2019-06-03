#include "PolygoneDrawable.hpp"

PolygoneD::PolygoneD(sf::Color couleur, int x1, int y1, std::vector<PointD*> * _tabPointD)
	: Forme(couleur.toInteger(), x1, y1),
		Polygone(couleur.toInteger(), x1, y1, nullptr),
		FormeD(couleur, x1, y1),
		tabPointD(_tabPointD)
{
	if (tabPointD->empty()) throw "il n'y a aucun points";

	size_t tailleTab = tabPointD->size();
	std::vector<fm::Point*>* tabPoint = new std::vector<fm::Point*>;

	for (size_t i = 0; i < tailleTab; i++) {
		tabPoint->push_back(tabPointD->at(i)->getPtrPoint());
		tabDistance.push_back(getDistance(getAncre(), tabPointD->at(i)->getPoint()));
	}
	setTabPoint(tabPoint);

	setFillColor(sf::Color(getCouleur()));
	setOutlineThickness(-1);
	setOutlineColor(sf::Color(getCouleur()));
	recalculate();
}

PolygoneD::PolygoneD(const PolygoneD & ori) : PolygoneD(sf::Color(ori.getCouleur()), getAncre().getX(), getAncre().getY(), ori.tabPointD) {}

PolygoneD::PolygoneD(std::istream & is) : fm::Forme(is), fm::Polygone(is), FormeD(is) {
	std::string str;
	std::getline(is, str);

	throw std::range_error("il est impossible de charger cette forme");
}

PolygoneD::~PolygoneD() {}

//TODO
bool PolygoneD::isOver(int x, int y) const {
	return (getAncreD().isOver(x,y));
}

void PolygoneD::dessiner(sf::RenderWindow & window) const {
	window.draw(*this);
	getAncreD().dessiner(window);
	for (size_t i = 0; i < getTailleTab(); i++) {
		tabPointD->at(i)->dessiner(window);
	}
}

void PolygoneD::maj() {
	FormeD::maj();
	for (size_t i = 0; i < getTailleTab(); i++) {
		tabPointD->at(i)->setPos(getAncre().getX() + tabDistance.at(i).x, getAncre().getY() + tabDistance.at(i).y);
		tabPointD->at(i)->update();
	}
	recalculate();
}

void PolygoneD::recalculate() {
	for (size_t i = 0; i < getTailleTab(); i++) {
		tabDistance.at(i) = (getDistance(getAncre(), tabPointD->at(i)->getPoint()));
	}
	Shape::update();
}

std::size_t PolygoneD::getPointCount() const {
	return getTailleTab() + 1;	//Tous les sommet du tableau plus l'ancre
}

sf::Vector2f PolygoneD::getPoint(std::size_t index) const {
	switch (index) {
		case 0: 
			return sf::Vector2f(getAncre().getX(), getAncre().getY());	//Premier point, ancre
			break;
		default:
			return sf::Vector2f(tabPointD->at(index - 1)->getX(), tabPointD->at(index - 1)->getY());
			break;
	}
}